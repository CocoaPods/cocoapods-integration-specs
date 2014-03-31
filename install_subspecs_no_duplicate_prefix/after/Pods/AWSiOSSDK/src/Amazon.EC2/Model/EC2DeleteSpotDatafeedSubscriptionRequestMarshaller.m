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

#import "EC2DeleteSpotDatafeedSubscriptionRequestMarshaller.h"

@implementation EC2DeleteSpotDatafeedSubscriptionRequestMarshaller

+(AmazonServiceRequest *)createRequest:(EC2DeleteSpotDatafeedSubscriptionRequest *)deleteSpotDatafeedSubscriptionRequest
{
    AmazonServiceRequest *request = [[EC2Request alloc] init];

    [request setParameterValue:@"DeleteSpotDatafeedSubscription"           forKey:@"Action"];
    [request setParameterValue:@"2013-10-15"   forKey:@"Version"];

    [request setDelegate:[deleteSpotDatafeedSubscriptionRequest delegate]];
    [request setCredentials:[deleteSpotDatafeedSubscriptionRequest credentials]];
    [request setEndpoint:[deleteSpotDatafeedSubscriptionRequest requestEndpoint]];
    [request setRequestTag:[deleteSpotDatafeedSubscriptionRequest requestTag]];

    if (deleteSpotDatafeedSubscriptionRequest != nil) {
        if (deleteSpotDatafeedSubscriptionRequest.dryRunIsSet) {
            [request setParameterValue:(deleteSpotDatafeedSubscriptionRequest.dryRun ? @"true":@"false") forKey:[NSString stringWithFormat:@"%@", @"DryRun"]];
        }
    }


    return [request autorelease];
}

@end

