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

#import "AutoScalingTag.h"


@implementation AutoScalingTag

@synthesize resourceId;
@synthesize resourceType;
@synthesize key;
@synthesize value;
@synthesize propagateAtLaunch;
@synthesize propagateAtLaunchIsSet;


-(id)init
{
    if (self = [super init]) {
        resourceId             = nil;
        resourceType           = nil;
        key                    = nil;
        value                  = nil;
        propagateAtLaunch      = NO;
        propagateAtLaunchIsSet = NO;
    }

    return self;
}



-(NSString *)description
{
    NSMutableString *buffer = [[NSMutableString alloc] initWithCapacity:256];

    [buffer appendString:@"{"];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"ResourceId: %@,", resourceId] autorelease]];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"ResourceType: %@,", resourceType] autorelease]];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"Key: %@,", key] autorelease]];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"Value: %@,", value] autorelease]];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"PropagateAtLaunch: %d,", propagateAtLaunch] autorelease]];
    [buffer appendString:[super description]];
    [buffer appendString:@"}"];

    return [buffer autorelease];
}


-(void)setPropagateAtLaunch:(BOOL)theValue
{
    propagateAtLaunch      = theValue;
    propagateAtLaunchIsSet = YES;
}


-(void)dealloc
{
    [resourceId release];
    [resourceType release];
    [key release];
    [value release];

    [super dealloc];
}


@end
