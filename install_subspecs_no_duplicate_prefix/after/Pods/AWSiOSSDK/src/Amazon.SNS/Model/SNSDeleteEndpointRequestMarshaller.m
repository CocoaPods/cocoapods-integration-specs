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

#import "SNSDeleteEndpointRequestMarshaller.h"

@implementation SNSDeleteEndpointRequestMarshaller

+(AmazonServiceRequest *)createRequest:(SNSDeleteEndpointRequest *)deleteEndpointRequest
{
    AmazonServiceRequest *request = [[SNSRequest alloc] init];

    [request setParameterValue:@"DeleteEndpoint"           forKey:@"Action"];
    [request setParameterValue:@"2010-03-31"   forKey:@"Version"];

    [request setDelegate:[deleteEndpointRequest delegate]];
    [request setCredentials:[deleteEndpointRequest credentials]];
    [request setEndpoint:[deleteEndpointRequest requestEndpoint]];
    [request setRequestTag:[deleteEndpointRequest requestTag]];

    if (deleteEndpointRequest != nil) {
        if (deleteEndpointRequest.endpointArn != nil) {
            [request setParameterValue:[NSString stringWithFormat:@"%@", deleteEndpointRequest.endpointArn] forKey:[NSString stringWithFormat:@"%@", @"EndpointArn"]];
        }
    }


    return [request autorelease];
}

@end

