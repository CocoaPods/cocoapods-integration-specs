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

#import "SNSConfirmSubscriptionRequestMarshaller.h"

@implementation SNSConfirmSubscriptionRequestMarshaller

+(AmazonServiceRequest *)createRequest:(SNSConfirmSubscriptionRequest *)confirmSubscriptionRequest
{
    AmazonServiceRequest *request = [[SNSRequest alloc] init];

    [request setParameterValue:@"ConfirmSubscription"           forKey:@"Action"];
    [request setParameterValue:@"2010-03-31"   forKey:@"Version"];

    [request setDelegate:[confirmSubscriptionRequest delegate]];
    [request setCredentials:[confirmSubscriptionRequest credentials]];
    [request setEndpoint:[confirmSubscriptionRequest requestEndpoint]];
    [request setRequestTag:[confirmSubscriptionRequest requestTag]];

    if (confirmSubscriptionRequest != nil) {
        if (confirmSubscriptionRequest.topicArn != nil) {
            [request setParameterValue:[NSString stringWithFormat:@"%@", confirmSubscriptionRequest.topicArn] forKey:[NSString stringWithFormat:@"%@", @"TopicArn"]];
        }
    }
    if (confirmSubscriptionRequest != nil) {
        if (confirmSubscriptionRequest.token != nil) {
            [request setParameterValue:[NSString stringWithFormat:@"%@", confirmSubscriptionRequest.token] forKey:[NSString stringWithFormat:@"%@", @"Token"]];
        }
    }
    if (confirmSubscriptionRequest != nil) {
        if (confirmSubscriptionRequest.authenticateOnUnsubscribe != nil) {
            [request setParameterValue:[NSString stringWithFormat:@"%@", confirmSubscriptionRequest.authenticateOnUnsubscribe] forKey:[NSString stringWithFormat:@"%@", @"AuthenticateOnUnsubscribe"]];
        }
    }


    return [request autorelease];
}

@end

