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

#import "EC2CreatePlacementGroupRequestMarshaller.h"

@implementation EC2CreatePlacementGroupRequestMarshaller

+(AmazonServiceRequest *)createRequest:(EC2CreatePlacementGroupRequest *)createPlacementGroupRequest
{
    AmazonServiceRequest *request = [[EC2Request alloc] init];

    [request setParameterValue:@"CreatePlacementGroup"           forKey:@"Action"];
    [request setParameterValue:@"2013-10-15"   forKey:@"Version"];

    [request setDelegate:[createPlacementGroupRequest delegate]];
    [request setCredentials:[createPlacementGroupRequest credentials]];
    [request setEndpoint:[createPlacementGroupRequest requestEndpoint]];
    [request setRequestTag:[createPlacementGroupRequest requestTag]];

    if (createPlacementGroupRequest != nil) {
        if (createPlacementGroupRequest.dryRunIsSet) {
            [request setParameterValue:(createPlacementGroupRequest.dryRun ? @"true":@"false") forKey:[NSString stringWithFormat:@"%@", @"DryRun"]];
        }
    }
    if (createPlacementGroupRequest != nil) {
        if (createPlacementGroupRequest.groupName != nil) {
            [request setParameterValue:[NSString stringWithFormat:@"%@", createPlacementGroupRequest.groupName] forKey:[NSString stringWithFormat:@"%@", @"GroupName"]];
        }
    }
    if (createPlacementGroupRequest != nil) {
        if (createPlacementGroupRequest.strategy != nil) {
            [request setParameterValue:[NSString stringWithFormat:@"%@", createPlacementGroupRequest.strategy] forKey:[NSString stringWithFormat:@"%@", @"Strategy"]];
        }
    }


    return [request autorelease];
}

@end

