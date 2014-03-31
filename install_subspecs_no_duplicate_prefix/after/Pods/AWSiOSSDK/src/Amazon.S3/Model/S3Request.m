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

#import "S3Request.h"
#import "S3BucketNameUtilities.h"

@implementation S3Request

#pragma mark methods

-(AmazonURLRequest *)configureURLRequest
{
    [super configureURLRequest];
    [self setHttpMethod:kHttpMethodGet];

    [self.urlRequest setValue:[NSString stringWithFormat:@"%lld", self.contentLength] forHTTPHeaderField:kHttpHdrContentLength];

    [self.urlRequest setValue:self.host forHTTPHeaderField:kHttpHdrHost];
    
    self.date = [NSDate date];
    
    [self.urlRequest setValue:[self.date stringWithRFC822Format] forHTTPHeaderField:kHttpHdrDate];

    if (nil != self.httpMethod) {
        [self.urlRequest setHTTPMethod:self.httpMethod];
    }
    if (nil != self.contentType) {
        [self.urlRequest setValue:self.contentType forHTTPHeaderField:kHttpHdrContentType];
    }
    if (nil != self.securityToken) {
        [self.urlRequest setValue:self.securityToken forHTTPHeaderField:kHttpHdrAmzSecurityToken];
    }

    [self.urlRequest setURL:self.url];

    return urlRequest;
}

-(NSString *)timestamp
{
    return [[self date] stringWithRFC822Format];
}

#pragma mark accessors

-(NSURL *)url
{
    NSString *keyPath;
    NSString *resQuery;

    if (self.bucket == nil || [S3BucketNameUtilities isDNSBucketName:self.bucket]) {
        keyPath  = (self.key == nil ? @"" : [NSString stringWithFormat:@"%@", [self.key stringWithURLEncoding]]);
    }
    else {
        keyPath  = (self.key == nil ? [NSString stringWithFormat:@"%@/", self.bucket] : [NSString stringWithFormat:@"%@/%@", self.bucket, [self.key stringWithURLEncoding]]);
    }
    resQuery = (self.subResource == nil ? @"" : [NSString stringWithFormat:@"?%@", self.subResource]);

    return [NSURL URLWithString:[NSString stringWithFormat:@"%@://%@/%@%@", self.protocol, self.host, keyPath, resQuery]];
}

-(NSString *)host
{
    if (nil != self.bucket) {
        if ( [S3BucketNameUtilities isDNSBucketName:self.bucket]) {
            return [NSString stringWithFormat:@"%@.%@", self.bucket, self.hostName];
        }
    }

    return self.hostName;
}

-(NSDate *)date
{
    if (_date == nil) {
        _date = [[NSDate date] retain];
    }
    return _date;
}

-(NSString *)protocol
{
    if ( [self.endpoint hasPrefix:@"http://"]) {
        return @"http";
    }
    else {
        return @"https";
    }
}

-(NSString *)endpointHost
{
    return self.hostName;
}

#pragma mark memory management

- (id)initWithCoder:(NSCoder *)decoder
{
    self = [super initWithCoder:decoder];
    
    [self setAuthorization:[decoder decodeObjectForKey:@"Authorization"]];
    self.contentLength = [decoder decodeInt64ForKey:@"ContentLength"];
    [self setContentType:[decoder decodeObjectForKey:@"ContentType"]];
    [self setSecurityToken:[decoder decodeObjectForKey:@"SecurityToken"]];
    [self setBucket:[decoder decodeObjectForKey:@"Bucket"]];
    [self setKey:[decoder decodeObjectForKey:@"Key"]];
    [self setSubResource:[decoder decodeObjectForKey:@"SubResource"]];
    
    return self;
}

- (void)encodeWithCoder:(NSCoder *)encoder
{
    [super encodeWithCoder:encoder];
    
    [encoder encodeObject:self.authorization forKey:@"Authorization"];
    [encoder encodeInt64:self.contentLength forKey:@"ContentLength"];
    [encoder encodeObject:self.contentType forKey:@"ContentType"];
    [encoder encodeObject:self.securityToken forKey:@"SecurityToken"];
    [encoder encodeObject:self.bucket forKey:@"Bucket"];
    [encoder encodeObject:self.key forKey:@"Key"];
    [encoder encodeObject:self.subResource forKey:@"SubResource"];
}

-(void)dealloc
{
    [_authorization release];
    [_contentType release];
    [_date release];
    [_securityToken release];
    [_bucket release];
    [_key release];
    [_subResource release];

    [super dealloc];
}

@end

