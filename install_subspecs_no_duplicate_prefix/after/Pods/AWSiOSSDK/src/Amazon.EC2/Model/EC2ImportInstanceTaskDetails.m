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

#import "EC2ImportInstanceTaskDetails.h"


@implementation EC2ImportInstanceTaskDetails

@synthesize volumes;
@synthesize instanceId;
@synthesize platform;
@synthesize descriptionValue;


-(id)init
{
    if (self = [super init]) {
        volumes          = [[NSMutableArray alloc] initWithCapacity:1];
        instanceId       = nil;
        platform         = nil;
        descriptionValue = nil;
    }

    return self;
}


-(void)addVolume:(EC2ImportInstanceVolumeDetailItem *)volumeObject
{
    if (volumes == nil) {
        volumes = [[NSMutableArray alloc] initWithCapacity:1];
    }

    [volumes addObject:volumeObject];
}


-(NSString *)description
{
    NSMutableString *buffer = [[NSMutableString alloc] initWithCapacity:256];

    [buffer appendString:@"{"];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"Volumes: %@,", volumes] autorelease]];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"InstanceId: %@,", instanceId] autorelease]];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"Platform: %@,", platform] autorelease]];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"Description: %@,", descriptionValue] autorelease]];
    [buffer appendString:[super description]];
    [buffer appendString:@"}"];

    return [buffer autorelease];
}



-(void)dealloc
{
    [volumes release];
    [instanceId release];
    [platform release];
    [descriptionValue release];

    [super dealloc];
}


@end
