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

#import "AutoScalingLaunchConfiguration.h"


@implementation AutoScalingLaunchConfiguration

@synthesize launchConfigurationName;
@synthesize launchConfigurationARN;
@synthesize imageId;
@synthesize keyName;
@synthesize securityGroups;
@synthesize userData;
@synthesize instanceType;
@synthesize kernelId;
@synthesize ramdiskId;
@synthesize blockDeviceMappings;
@synthesize instanceMonitoring;
@synthesize spotPrice;
@synthesize iamInstanceProfile;
@synthesize createdTime;
@synthesize ebsOptimized;
@synthesize ebsOptimizedIsSet;
@synthesize associatePublicIpAddress;
@synthesize associatePublicIpAddressIsSet;


-(id)init
{
    if (self = [super init]) {
        launchConfigurationName       = nil;
        launchConfigurationARN        = nil;
        imageId                       = nil;
        keyName                       = nil;
        securityGroups                = [[NSMutableArray alloc] initWithCapacity:1];
        userData                      = nil;
        instanceType                  = nil;
        kernelId                      = nil;
        ramdiskId                     = nil;
        blockDeviceMappings           = [[NSMutableArray alloc] initWithCapacity:1];
        instanceMonitoring            = nil;
        spotPrice                     = nil;
        iamInstanceProfile            = nil;
        createdTime                   = nil;
        ebsOptimized                  = NO;
        ebsOptimizedIsSet             = NO;
        associatePublicIpAddress      = NO;
        associatePublicIpAddressIsSet = NO;
    }

    return self;
}


-(void)addSecurityGroup:(NSString *)securityGroupObject
{
    if (securityGroups == nil) {
        securityGroups = [[NSMutableArray alloc] initWithCapacity:1];
    }

    [securityGroups addObject:securityGroupObject];
}

-(void)addBlockDeviceMapping:(AutoScalingBlockDeviceMapping *)blockDeviceMappingObject
{
    if (blockDeviceMappings == nil) {
        blockDeviceMappings = [[NSMutableArray alloc] initWithCapacity:1];
    }

    [blockDeviceMappings addObject:blockDeviceMappingObject];
}


-(NSString *)description
{
    NSMutableString *buffer = [[NSMutableString alloc] initWithCapacity:256];

    [buffer appendString:@"{"];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"LaunchConfigurationName: %@,", launchConfigurationName] autorelease]];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"LaunchConfigurationARN: %@,", launchConfigurationARN] autorelease]];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"ImageId: %@,", imageId] autorelease]];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"KeyName: %@,", keyName] autorelease]];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"SecurityGroups: %@,", securityGroups] autorelease]];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"UserData: %@,", userData] autorelease]];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"InstanceType: %@,", instanceType] autorelease]];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"KernelId: %@,", kernelId] autorelease]];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"RamdiskId: %@,", ramdiskId] autorelease]];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"BlockDeviceMappings: %@,", blockDeviceMappings] autorelease]];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"InstanceMonitoring: %@,", instanceMonitoring] autorelease]];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"SpotPrice: %@,", spotPrice] autorelease]];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"IamInstanceProfile: %@,", iamInstanceProfile] autorelease]];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"CreatedTime: %@,", createdTime] autorelease]];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"EbsOptimized: %d,", ebsOptimized] autorelease]];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"AssociatePublicIpAddress: %d,", associatePublicIpAddress] autorelease]];
    [buffer appendString:[super description]];
    [buffer appendString:@"}"];

    return [buffer autorelease];
}


-(void)setEbsOptimized:(BOOL)theValue
{
    ebsOptimized      = theValue;
    ebsOptimizedIsSet = YES;
}

-(void)setAssociatePublicIpAddress:(BOOL)theValue
{
    associatePublicIpAddress      = theValue;
    associatePublicIpAddressIsSet = YES;
}


-(void)dealloc
{
    [launchConfigurationName release];
    [launchConfigurationARN release];
    [imageId release];
    [keyName release];
    [securityGroups release];
    [userData release];
    [instanceType release];
    [kernelId release];
    [ramdiskId release];
    [blockDeviceMappings release];
    [instanceMonitoring release];
    [spotPrice release];
    [iamInstanceProfile release];
    [createdTime release];

    [super dealloc];
}


@end
