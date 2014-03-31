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

#import "EC2TerminateInstancesRequestMarshaller.h"

@implementation EC2TerminateInstancesRequestMarshaller

+(AmazonServiceRequest *)createRequest:(EC2TerminateInstancesRequest *)terminateInstancesRequest
{
    AmazonServiceRequest *request = [[EC2Request alloc] init];

    [request setParameterValue:@"TerminateInstances"           forKey:@"Action"];
    [request setParameterValue:@"2013-10-15"   forKey:@"Version"];

    [request setDelegate:[terminateInstancesRequest delegate]];
    [request setCredentials:[terminateInstancesRequest credentials]];
    [request setEndpoint:[terminateInstancesRequest requestEndpoint]];
    [request setRequestTag:[terminateInstancesRequest requestTag]];

    if (terminateInstancesRequest != nil) {
        if (terminateInstancesRequest.dryRunIsSet) {
            [request setParameterValue:(terminateInstancesRequest.dryRun ? @"true":@"false") forKey:[NSString stringWithFormat:@"%@", @"DryRun"]];
        }
    }

    if (terminateInstancesRequest != nil) {
        int instanceIdsListIndex = 1;
        for (NSString *instanceIdsListValue in terminateInstancesRequest.instanceIds) {
            if (instanceIdsListValue != nil) {
                [request setParameterValue:[NSString stringWithFormat:@"%@", instanceIdsListValue] forKey:[NSString stringWithFormat:@"%@.%d", @"InstanceId", instanceIdsListIndex]];
            }

            instanceIdsListIndex++;
        }
    }


    return [request autorelease];
}

@end

