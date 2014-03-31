/*
 * Copyright 2010-2013 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 *
 *  http://aws.amazon.com/apache2.0
 *
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */


#import "AmazonServiceRequest.h"
#import "AmazonServiceResponse.h"
#import "AmazonAuthUtils.h"

@implementation AmazonServiceRequest

@synthesize httpMethod;
@synthesize parameters;
@synthesize endpoint;
@synthesize userAgent;
@synthesize credentials;
@synthesize urlRequest;
@synthesize urlConnection;
@synthesize responseTimer;
@synthesize requestTag;
@synthesize serviceName;
@synthesize regionName;
@synthesize hostName;
@synthesize delegate;

- (id)init
{
    if(self = [super init])
    {
        httpMethod = nil;
        parameters = nil;
        endpoint = nil;
        userAgent = nil;
        credentials = nil;
        urlRequest = [AmazonURLRequest new];
        urlConnection = nil;
        responseTimer = nil;
        requestTag = nil;
        serviceName = nil;
        regionName = nil;
        hostName = nil;
        delegate = nil;
    }

    return self;
}

- (id)initWithCoder:(NSCoder *)decoder
{
    if (self = [self init]) {
        [self setHttpMethod:[decoder decodeObjectForKey:@"HttpMethod"]];
        [self setParameters:[decoder decodeObjectForKey:@"Parameters"]];
        [self setEndpoint:[decoder decodeObjectForKey:@"Endpoint"]];
        [self setUserAgent:[decoder decodeObjectForKey:@"UserAgent"]];
        [self setResponseTimer:[decoder decodeObjectForKey:@"ResponseTime"]];
        [self setRequestTag:[decoder decodeObjectForKey:@"RequestTag"]];
        [self setServiceName:[decoder decodeObjectForKey:@"ServiceName"]];
        [self setRegionName:[decoder decodeObjectForKey:@"RegionName"]];
        [self setHostName:[decoder decodeObjectForKey:@"HostName"]];
    }
    
    return self;
}

- (void)encodeWithCoder:(NSCoder *)encoder
{
    [encoder encodeObject:httpMethod forKey:@"HttpMethod"];
    [encoder encodeObject:parameters forKey:@"Parameters"];
    [encoder encodeObject:endpoint forKey:@"Endpoint"];
    [encoder encodeObject:userAgent forKey:@"UserAgent"];
    [encoder encodeObject:responseTimer forKey:@"ResponseTimer"];
    [encoder encodeObject:requestTag forKey:@"RequestTag"];
    [encoder encodeObject:serviceName forKey:@"ServiceName"];
    [encoder encodeObject:regionName forKey:@"RegionName"];
    [encoder encodeObject:hostName forKey:@"HostName"];
}

-(void)sign
{
    // headers to sign
    NSMutableDictionary *headers = [NSMutableDictionary dictionary];
    [headers setObject:self.hostName forKey:@"Host"];
    
    [AmazonAuthUtils signRequestV4:self headers:headers payload:[self queryString] credentials:self.credentials];
}

-(NSMutableURLRequest *)configureURLRequest
{
    if (self.credentials != nil && self.credentials.securityToken != nil) {
        [self setParameterValue:self.credentials.securityToken forKey:@"SecurityToken"];
    }

    [self.urlRequest setHTTPMethod:@"POST"];
    
    [self.urlRequest setHTTPBody:[[self queryString] dataUsingEncoding:NSUTF8StringEncoding]];
    
    [self.urlRequest setValue:self.userAgent forHTTPHeaderField:@"User-Agent"];

    NSURL *url = [NSURL URLWithString:self.endpoint];
    [urlRequest setURL:url];
    [urlRequest setValue:[url host] forHTTPHeaderField:@"Host"];


    return self.urlRequest;
}

-(NSString *)queryString
{
    NSMutableString *buffer = [[NSMutableString alloc] initWithCapacity:256];

    NSArray         *keys       = [[self parameters] allKeys];
    NSArray         *sortedKeys = [keys sortedArrayUsingSelector:@selector(compare:)];
    for (NSInteger index = 0; index < [sortedKeys count]; index++) {
        NSString *key   = [sortedKeys objectAtIndex:index];
        NSString *value = (NSString *)[[self parameters] valueForKey:key];

        [buffer appendString:[AmazonSDKUtil urlEncode:key]];
        [buffer appendString:@"="];
        [buffer appendString:[AmazonSDKUtil urlEncode:value]];

        if (index < [sortedKeys count] - 1) {
            [buffer appendString:@"&"];
        }
    }

    return [buffer autorelease];
}

-(NSString *)hostName
{
    // hostName was explicitly set
    if (hostName != nil) {
        return hostName;
    }
    
    NSRange startOfHost = [self.endpoint rangeOfString:@"://"];
    
    NSString *trimmed = [self.endpoint substringFromIndex:(startOfHost.location + 3)];
    NSRange endOfHost = [trimmed rangeOfString:@"/"];
    if (endOfHost.location == NSNotFound) {
        return trimmed;
    }

    return [trimmed substringToIndex:(endOfHost.location)];
}

-(NSString *)regionName
{
    // regionName was explicitly set
    if (regionName != nil) {
        return regionName;
    }
    // If we don't recognize the domain, just return the default
    if ([self.hostName hasSuffix:@".queue.amazonaws.com"]){
        NSRange  range             = [self.hostName rangeOfString:@".queue.amazonaws.com"];
        return [self.hostName substringToIndex:range.location];
    }
    else if ([self.hostName hasSuffix:@".amazonaws.com"]) {
        NSRange  range             = [self.hostName rangeOfString:@".amazonaws.com"];
        NSString *serviceAndRegion = [self.hostName substringToIndex:range.location];
        
        NSString *separator = @".";
        if ( [serviceAndRegion hasPrefix:@"s3"]) {
            separator = @"-";
        }
        
        if ( [serviceAndRegion rangeOfString:separator].location == NSNotFound) {
            return @"us-east-1";
        }
        
        NSRange  index   = [serviceAndRegion rangeOfString:separator];
        NSString *region = [serviceAndRegion substringFromIndex:(index.location + 1)];
        if ( [region isEqualToString:@"us-gov"]) {
            return @"us-gov-west-1";
        }
        else {
            return region;
        }
    }
    else {
        return @"us-east-1";
    }
    
}

-(NSString *)serviceName
{
    // serviceName was explicitly set
    if (serviceName != nil) {
        return serviceName;
    }
    
    // If we don't recognize the domain, just return nil
    if ([self.hostName hasSuffix:@"queue.amazonaws.com"]){
        return @"sqs";
    }
    else if ([self.hostName hasSuffix:@".amazonaws.com"]) {
        NSRange  range             = [self.hostName rangeOfString:@".amazonaws.com"];
        NSString *serviceAndRegion = [self.hostName substringToIndex:range.location];
        
        NSString *separator = @".";
        if ( [serviceAndRegion hasPrefix:@"s3"]) {
            return @"s3";
        }
        
        if ( [serviceAndRegion rangeOfString:separator].location == NSNotFound) {
            return serviceAndRegion;
        }
        
        NSRange index = [serviceAndRegion rangeOfString:separator];
        return [serviceAndRegion substringToIndex:index.location];
    }
    else {
        return nil;
    }
}

-(void)setParameterValue:(NSString *)theValue forKey:(NSString *)theKey
{
    if (nil == parameters) {
        parameters = [[NSMutableDictionary alloc] initWithCapacity:1];
    }
    [parameters setValue:theValue forKey:theKey];
}

-(NSURL *)url
{
    return nil;
}

- (AmazonClientException *)validate
{
    return nil;
}

- (void)cancel
{
    [self.urlConnection cancel];
    [self.responseTimer invalidate];
}

-(AmazonServiceResponse*)constructResponse
{
    return [[AmazonServiceResponse new] autorelease];
}

-(void)dealloc
{
    delegate = nil;
    
    [credentials release];
    [urlRequest release];
    [urlConnection release];
    [responseTimer release];
    [httpMethod release];
    [parameters release];
    [endpoint release];
    [serviceName release];
    [regionName release];
    [hostName release];
    [userAgent release];
    [requestTag release];

    [super dealloc];
}

@end
