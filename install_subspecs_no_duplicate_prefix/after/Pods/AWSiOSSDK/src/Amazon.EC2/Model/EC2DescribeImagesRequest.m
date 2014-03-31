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

#import "EC2DescribeImagesRequest.h"


@implementation EC2DescribeImagesRequest

@synthesize dryRun;
@synthesize dryRunIsSet;
@synthesize imageIds;
@synthesize owners;
@synthesize executableUsers;
@synthesize filters;


-(id)init
{
    if (self = [super init]) {
        dryRun          = NO;
        dryRunIsSet     = NO;
        imageIds        = [[NSMutableArray alloc] initWithCapacity:1];
        owners          = [[NSMutableArray alloc] initWithCapacity:1];
        executableUsers = [[NSMutableArray alloc] initWithCapacity:1];
        filters         = [[NSMutableArray alloc] initWithCapacity:1];
    }

    return self;
}


-(void)addImageId:(NSString *)imageIdObject
{
    if (imageIds == nil) {
        imageIds = [[NSMutableArray alloc] initWithCapacity:1];
    }

    [imageIds addObject:imageIdObject];
}

-(void)addOwner:(NSString *)ownerObject
{
    if (owners == nil) {
        owners = [[NSMutableArray alloc] initWithCapacity:1];
    }

    [owners addObject:ownerObject];
}

-(void)addExecutableUser:(NSString *)executableUserObject
{
    if (executableUsers == nil) {
        executableUsers = [[NSMutableArray alloc] initWithCapacity:1];
    }

    [executableUsers addObject:executableUserObject];
}

-(void)addFilter:(EC2Filter *)filterObject
{
    if (filters == nil) {
        filters = [[NSMutableArray alloc] initWithCapacity:1];
    }

    [filters addObject:filterObject];
}


-(NSString *)description
{
    NSMutableString *buffer = [[NSMutableString alloc] initWithCapacity:256];

    [buffer appendString:@"{"];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"DryRun: %d,", dryRun] autorelease]];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"ImageIds: %@,", imageIds] autorelease]];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"Owners: %@,", owners] autorelease]];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"ExecutableUsers: %@,", executableUsers] autorelease]];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"Filters: %@,", filters] autorelease]];
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
    [imageIds release];
    [owners release];
    [executableUsers release];
    [filters release];

    [super dealloc];
}


@end
