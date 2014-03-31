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

#import "AutoScalingDeleteAutoScalingGroupRequestMarshaller.h"

@implementation AutoScalingDeleteAutoScalingGroupRequestMarshaller

+(AmazonServiceRequest *)createRequest:(AutoScalingDeleteAutoScalingGroupRequest *)deleteAutoScalingGroupRequest
{
    AmazonServiceRequest *request = [[AutoScalingRequest alloc] init];

    [request setParameterValue:@"DeleteAutoScalingGroup"           forKey:@"Action"];
    [request setParameterValue:@"2011-01-01"   forKey:@"Version"];

    [request setDelegate:[deleteAutoScalingGroupRequest delegate]];
    [request setCredentials:[deleteAutoScalingGroupRequest credentials]];
    [request setEndpoint:[deleteAutoScalingGroupRequest requestEndpoint]];
    [request setRequestTag:[deleteAutoScalingGroupRequest requestTag]];

    if (deleteAutoScalingGroupRequest != nil) {
        if (deleteAutoScalingGroupRequest.autoScalingGroupName != nil) {
            [request setParameterValue:[NSString stringWithFormat:@"%@", deleteAutoScalingGroupRequest.autoScalingGroupName] forKey:[NSString stringWithFormat:@"%@", @"AutoScalingGroupName"]];
        }
    }
    if (deleteAutoScalingGroupRequest != nil) {
        if (deleteAutoScalingGroupRequest.forceDeleteIsSet) {
            [request setParameterValue:(deleteAutoScalingGroupRequest.forceDelete ? @"true":@"false") forKey:[NSString stringWithFormat:@"%@", @"ForceDelete"]];
        }
    }


    return [request autorelease];
}

@end

