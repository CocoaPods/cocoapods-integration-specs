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

#import "SQSGetQueueUrlRequestMarshaller.h"

@implementation SQSGetQueueUrlRequestMarshaller

+(AmazonServiceRequest *)createRequest:(SQSGetQueueUrlRequest *)getQueueUrlRequest
{
    AmazonServiceRequest *request = [[SQSRequest alloc] init];

    [request setParameterValue:@"GetQueueUrl"           forKey:@"Action"];
    [request setParameterValue:@"2012-11-05"   forKey:@"Version"];

    [request setDelegate:[getQueueUrlRequest delegate]];
    [request setCredentials:[getQueueUrlRequest credentials]];
    [request setEndpoint:[getQueueUrlRequest requestEndpoint]];
    [request setRequestTag:[getQueueUrlRequest requestTag]];

    if (getQueueUrlRequest != nil) {
        if (getQueueUrlRequest.queueName != nil) {
            [request setParameterValue:[NSString stringWithFormat:@"%@", getQueueUrlRequest.queueName] forKey:[NSString stringWithFormat:@"%@", @"QueueName"]];
        }
    }
    if (getQueueUrlRequest != nil) {
        if (getQueueUrlRequest.queueOwnerAWSAccountId != nil) {
            [request setParameterValue:[NSString stringWithFormat:@"%@", getQueueUrlRequest.queueOwnerAWSAccountId] forKey:[NSString stringWithFormat:@"%@", @"QueueOwnerAWSAccountId"]];
        }
    }


    return [request autorelease];
}

@end

