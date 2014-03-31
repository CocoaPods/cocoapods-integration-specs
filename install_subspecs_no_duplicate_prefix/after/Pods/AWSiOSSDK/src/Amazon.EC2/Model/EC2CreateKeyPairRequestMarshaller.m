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

#import "EC2CreateKeyPairRequestMarshaller.h"

@implementation EC2CreateKeyPairRequestMarshaller

+(AmazonServiceRequest *)createRequest:(EC2CreateKeyPairRequest *)createKeyPairRequest
{
    AmazonServiceRequest *request = [[EC2Request alloc] init];

    [request setParameterValue:@"CreateKeyPair"           forKey:@"Action"];
    [request setParameterValue:@"2013-10-15"   forKey:@"Version"];

    [request setDelegate:[createKeyPairRequest delegate]];
    [request setCredentials:[createKeyPairRequest credentials]];
    [request setEndpoint:[createKeyPairRequest requestEndpoint]];
    [request setRequestTag:[createKeyPairRequest requestTag]];

    if (createKeyPairRequest != nil) {
        if (createKeyPairRequest.dryRunIsSet) {
            [request setParameterValue:(createKeyPairRequest.dryRun ? @"true":@"false") forKey:[NSString stringWithFormat:@"%@", @"DryRun"]];
        }
    }
    if (createKeyPairRequest != nil) {
        if (createKeyPairRequest.keyName != nil) {
            [request setParameterValue:[NSString stringWithFormat:@"%@", createKeyPairRequest.keyName] forKey:[NSString stringWithFormat:@"%@", @"KeyName"]];
        }
    }


    return [request autorelease];
}

@end

