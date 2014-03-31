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

#import "AutoScalingDescribeScalingActivitiesRequest.h"


@implementation AutoScalingDescribeScalingActivitiesRequest

@synthesize activityIds;
@synthesize autoScalingGroupName;
@synthesize maxRecords;
@synthesize nextToken;


-(id)init
{
    if (self = [super init]) {
        activityIds          = [[NSMutableArray alloc] initWithCapacity:1];
        autoScalingGroupName = nil;
        maxRecords           = nil;
        nextToken            = nil;
    }

    return self;
}


-(void)addActivityId:(NSString *)activityIdObject
{
    if (activityIds == nil) {
        activityIds = [[NSMutableArray alloc] initWithCapacity:1];
    }

    [activityIds addObject:activityIdObject];
}


-(NSString *)description
{
    NSMutableString *buffer = [[NSMutableString alloc] initWithCapacity:256];

    [buffer appendString:@"{"];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"ActivityIds: %@,", activityIds] autorelease]];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"AutoScalingGroupName: %@,", autoScalingGroupName] autorelease]];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"MaxRecords: %@,", maxRecords] autorelease]];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"NextToken: %@,", nextToken] autorelease]];
    [buffer appendString:[super description]];
    [buffer appendString:@"}"];

    return [buffer autorelease];
}



-(void)dealloc
{
    [activityIds release];
    [autoScalingGroupName release];
    [maxRecords release];
    [nextToken release];

    [super dealloc];
}


@end
