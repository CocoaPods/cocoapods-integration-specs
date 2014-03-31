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

#import "SNSUnsubscribeRequestMarshaller.h"

@implementation SNSUnsubscribeRequestMarshaller

+(AmazonServiceRequest *)createRequest:(SNSUnsubscribeRequest *)unsubscribeRequest
{
    AmazonServiceRequest *request = [[SNSRequest alloc] init];

    [request setParameterValue:@"Unsubscribe"           forKey:@"Action"];
    [request setParameterValue:@"2010-03-31"   forKey:@"Version"];

    [request setDelegate:[unsubscribeRequest delegate]];
    [request setCredentials:[unsubscribeRequest credentials]];
    [request setEndpoint:[unsubscribeRequest requestEndpoint]];
    [request setRequestTag:[unsubscribeRequest requestTag]];

    if (unsubscribeRequest != nil) {
        if (unsubscribeRequest.subscriptionArn != nil) {
            [request setParameterValue:[NSString stringWithFormat:@"%@", unsubscribeRequest.subscriptionArn] forKey:[NSString stringWithFormat:@"%@", @"SubscriptionArn"]];
        }
    }


    return [request autorelease];
}

@end

