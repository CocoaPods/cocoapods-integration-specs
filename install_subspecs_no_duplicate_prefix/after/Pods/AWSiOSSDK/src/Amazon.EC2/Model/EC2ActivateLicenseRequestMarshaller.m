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

#import "EC2ActivateLicenseRequestMarshaller.h"

@implementation EC2ActivateLicenseRequestMarshaller

+(AmazonServiceRequest *)createRequest:(EC2ActivateLicenseRequest *)activateLicenseRequest
{
    AmazonServiceRequest *request = [[EC2Request alloc] init];

    [request setParameterValue:@"ActivateLicense"           forKey:@"Action"];
    [request setParameterValue:@"2013-10-15"   forKey:@"Version"];

    [request setDelegate:[activateLicenseRequest delegate]];
    [request setCredentials:[activateLicenseRequest credentials]];
    [request setEndpoint:[activateLicenseRequest requestEndpoint]];
    [request setRequestTag:[activateLicenseRequest requestTag]];

    if (activateLicenseRequest != nil) {
        if (activateLicenseRequest.dryRunIsSet) {
            [request setParameterValue:(activateLicenseRequest.dryRun ? @"true":@"false") forKey:[NSString stringWithFormat:@"%@", @"DryRun"]];
        }
    }
    if (activateLicenseRequest != nil) {
        if (activateLicenseRequest.licenseId != nil) {
            [request setParameterValue:[NSString stringWithFormat:@"%@", activateLicenseRequest.licenseId] forKey:[NSString stringWithFormat:@"%@", @"LicenseId"]];
        }
    }
    if (activateLicenseRequest != nil) {
        if (activateLicenseRequest.capacity != nil) {
            [request setParameterValue:[NSString stringWithFormat:@"%@", activateLicenseRequest.capacity] forKey:[NSString stringWithFormat:@"%@", @"Capacity"]];
        }
    }


    return [request autorelease];
}

@end

