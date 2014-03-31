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

#import "ElasticLoadBalancingCreateAppCookieStickinessPolicyRequest.h"


@implementation ElasticLoadBalancingCreateAppCookieStickinessPolicyRequest

@synthesize loadBalancerName;
@synthesize policyName;
@synthesize cookieName;


-(id)init
{
    if (self = [super init]) {
        loadBalancerName = nil;
        policyName       = nil;
        cookieName       = nil;
    }

    return self;
}

-(id)initWithLoadBalancerName:(NSString *)theLoadBalancerName andPolicyName:(NSString *)thePolicyName andCookieName:(NSString *)theCookieName
{
    if (self = [self init]) {
        self.loadBalancerName = theLoadBalancerName;
        self.policyName       = thePolicyName;
        self.cookieName       = theCookieName;
    }

    return self;
}



-(NSString *)description
{
    NSMutableString *buffer = [[NSMutableString alloc] initWithCapacity:256];

    [buffer appendString:@"{"];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"LoadBalancerName: %@,", loadBalancerName] autorelease]];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"PolicyName: %@,", policyName] autorelease]];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"CookieName: %@,", cookieName] autorelease]];
    [buffer appendString:[super description]];
    [buffer appendString:@"}"];

    return [buffer autorelease];
}



-(void)dealloc
{
    [loadBalancerName release];
    [policyName release];
    [cookieName release];

    [super dealloc];
}


@end
