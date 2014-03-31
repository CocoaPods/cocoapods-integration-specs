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

#import "EC2AttachVolumeRequest.h"


@implementation EC2AttachVolumeRequest

@synthesize dryRun;
@synthesize dryRunIsSet;
@synthesize volumeId;
@synthesize instanceId;
@synthesize device;


-(id)init
{
    if (self = [super init]) {
        dryRun      = NO;
        dryRunIsSet = NO;
        volumeId    = nil;
        instanceId  = nil;
        device      = nil;
    }

    return self;
}

-(id)initWithVolumeId:(NSString *)theVolumeId andInstanceId:(NSString *)theInstanceId andDevice:(NSString *)theDevice
{
    if (self = [self init]) {
        self.volumeId   = theVolumeId;
        self.instanceId = theInstanceId;
        self.device     = theDevice;
    }

    return self;
}



-(NSString *)description
{
    NSMutableString *buffer = [[NSMutableString alloc] initWithCapacity:256];

    [buffer appendString:@"{"];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"DryRun: %d,", dryRun] autorelease]];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"VolumeId: %@,", volumeId] autorelease]];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"InstanceId: %@,", instanceId] autorelease]];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"Device: %@,", device] autorelease]];
    [buffer appendString:[super description]];
    [buffer appendString:@"}"];

    return [buffer autorelease];
}


-(void)setDryRun:(BOOL)theValue
{
    dryRun      = theValue;
    dryRunIsSet = YES;
}


-(void)dealloc
{
    [volumeId release];
    [instanceId release];
    [device release];

    [super dealloc];
}


@end
