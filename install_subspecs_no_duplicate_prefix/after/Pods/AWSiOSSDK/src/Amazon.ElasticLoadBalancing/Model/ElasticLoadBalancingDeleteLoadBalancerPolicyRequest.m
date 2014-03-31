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

#import "ElasticLoadBalancingDeleteLoadBalancerPolicyRequest.h"


@implementation ElasticLoadBalancingDeleteLoadBalancerPolicyRequest

@synthesize loadBalancerName;
@synthesize policyName;


-(id)init
{
    if (self = [super init]) {
        loadBalancerName = nil;
        policyName       = nil;
    }

    return self;
}

-(id)initWithLoadBalancerName:(NSString *)theLoadBalancerName andPolicyName:(NSString *)thePolicyName
{
    if (self = [self init]) {
        self.loadBalancerName = theLoadBalancerName;
        self.policyName       = thePolicyName;
    }

    return self;
}



-(NSString *)description
{
    NSMutableString *buffer = [[NSMutableString alloc] initWithCapacity:256];

    [buffer appendString:@"{"];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"LoadBalancerName: %@,", loadBalancerName] autorelease]];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"PolicyName: %@,", policyName] autorelease]];
    [buffer appendString:[super description]];
    [buffer appendString:@"}"];

    return [buffer autorelease];
}



-(void)dealloc
{
    [loadBalancerName release];
    [policyName release];

    [super dealloc];
}


@end
