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

#import "ElasticLoadBalancingPolicyAttributeDescription.h"


@implementation ElasticLoadBalancingPolicyAttributeDescription

@synthesize attributeName;
@synthesize attributeValue;


-(id)init
{
    if (self = [super init]) {
        attributeName  = nil;
        attributeValue = nil;
    }

    return self;
}



-(NSString *)description
{
    NSMutableString *buffer = [[NSMutableString alloc] initWithCapacity:256];

    [buffer appendString:@"{"];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"AttributeName: %@,", attributeName] autorelease]];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"AttributeValue: %@,", attributeValue] autorelease]];
    [buffer appendString:[super description]];
    [buffer appendString:@"}"];

    return [buffer autorelease];
}



-(void)dealloc
{
    [attributeName release];
    [attributeValue release];

    [super dealloc];
}


@end
