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

#import "EC2StopInstancesRequestMarshaller.h"

@implementation EC2StopInstancesRequestMarshaller

+(AmazonServiceRequest *)createRequest:(EC2StopInstancesRequest *)stopInstancesRequest
{
    AmazonServiceRequest *request = [[EC2Request alloc] init];

    [request setParameterValue:@"StopInstances"           forKey:@"Action"];
    [request setParameterValue:@"2013-10-15"   forKey:@"Version"];

    [request setDelegate:[stopInstancesRequest delegate]];
    [request setCredentials:[stopInstancesRequest credentials]];
    [request setEndpoint:[stopInstancesRequest requestEndpoint]];
    [request setRequestTag:[stopInstancesRequest requestTag]];

    if (stopInstancesRequest != nil) {
        if (stopInstancesRequest.dryRunIsSet) {
            [request setParameterValue:(stopInstancesRequest.dryRun ? @"true":@"false") forKey:[NSString stringWithFormat:@"%@", @"DryRun"]];
        }
    }

    if (stopInstancesRequest != nil) {
        int instanceIdsListIndex = 1;
        for (NSString *instanceIdsListValue in stopInstancesRequest.instanceIds) {
            if (instanceIdsListValue != nil) {
                [request setParameterValue:[NSString stringWithFormat:@"%@", instanceIdsListValue] forKey:[NSString stringWithFormat:@"%@.%d", @"InstanceId", instanceIdsListIndex]];
            }

            instanceIdsListIndex++;
        }
    }
    if (stopInstancesRequest != nil) {
        if (stopInstancesRequest.forceIsSet) {
            [request setParameterValue:(stopInstancesRequest.force ? @"true":@"false") forKey:[NSString stringWithFormat:@"%@", @"Force"]];
        }
    }


    return [request autorelease];
}

@end

