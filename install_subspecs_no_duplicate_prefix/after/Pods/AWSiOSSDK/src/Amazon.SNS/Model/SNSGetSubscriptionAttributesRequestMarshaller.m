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

#import "SNSGetSubscriptionAttributesRequestMarshaller.h"

@implementation SNSGetSubscriptionAttributesRequestMarshaller

+(AmazonServiceRequest *)createRequest:(SNSGetSubscriptionAttributesRequest *)getSubscriptionAttributesRequest
{
    AmazonServiceRequest *request = [[SNSRequest alloc] init];

    [request setParameterValue:@"GetSubscriptionAttributes"           forKey:@"Action"];
    [request setParameterValue:@"2010-03-31"   forKey:@"Version"];

    [request setDelegate:[getSubscriptionAttributesRequest delegate]];
    [request setCredentials:[getSubscriptionAttributesRequest credentials]];
    [request setEndpoint:[getSubscriptionAttributesRequest requestEndpoint]];
    [request setRequestTag:[getSubscriptionAttributesRequest requestTag]];

    if (getSubscriptionAttributesRequest != nil) {
        if (getSubscriptionAttributesRequest.subscriptionArn != nil) {
            [request setParameterValue:[NSString stringWithFormat:@"%@", getSubscriptionAttributesRequest.subscriptionArn] forKey:[NSString stringWithFormat:@"%@", @"SubscriptionArn"]];
        }
    }


    return [request autorelease];
}

@end

