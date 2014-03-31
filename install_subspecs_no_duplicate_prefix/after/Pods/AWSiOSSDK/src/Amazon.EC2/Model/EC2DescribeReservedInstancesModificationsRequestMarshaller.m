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

#import "EC2DescribeReservedInstancesModificationsRequestMarshaller.h"

@implementation EC2DescribeReservedInstancesModificationsRequestMarshaller

+(AmazonServiceRequest *)createRequest:(EC2DescribeReservedInstancesModificationsRequest *)describeReservedInstancesModificationsRequest
{
    AmazonServiceRequest *request = [[EC2Request alloc] init];

    [request setParameterValue:@"DescribeReservedInstancesModifications"           forKey:@"Action"];
    [request setParameterValue:@"2013-10-15"   forKey:@"Version"];

    [request setDelegate:[describeReservedInstancesModificationsRequest delegate]];
    [request setCredentials:[describeReservedInstancesModificationsRequest credentials]];
    [request setEndpoint:[describeReservedInstancesModificationsRequest requestEndpoint]];
    [request setRequestTag:[describeReservedInstancesModificationsRequest requestTag]];


    if (describeReservedInstancesModificationsRequest != nil) {
        int reservedInstancesModificationIdsListIndex = 1;
        for (NSString *reservedInstancesModificationIdsListValue in describeReservedInstancesModificationsRequest.reservedInstancesModificationIds) {
            if (reservedInstancesModificationIdsListValue != nil) {
                [request setParameterValue:[NSString stringWithFormat:@"%@", reservedInstancesModificationIdsListValue] forKey:[NSString stringWithFormat:@"%@.%d", @"ReservedInstancesModificationId", reservedInstancesModificationIdsListIndex]];
            }

            reservedInstancesModificationIdsListIndex++;
        }
    }
    if (describeReservedInstancesModificationsRequest != nil) {
        if (describeReservedInstancesModificationsRequest.nextToken != nil) {
            [request setParameterValue:[NSString stringWithFormat:@"%@", describeReservedInstancesModificationsRequest.nextToken] forKey:[NSString stringWithFormat:@"%@", @"NextToken"]];
        }
    }

    if (describeReservedInstancesModificationsRequest != nil) {
        int filtersListIndex = 1;
        for (EC2Filter *filtersListValue in describeReservedInstancesModificationsRequest.filters) {
            if (filtersListValue != nil) {
                if (filtersListValue.name != nil) {
                    [request setParameterValue:[NSString stringWithFormat:@"%@", filtersListValue.name] forKey:[NSString stringWithFormat:@"%@.%d.%@", @"Filter", filtersListIndex, @"Name"]];
                }
            }

            if (filtersListValue != nil) {
                int valuesListIndex = 1;
                for (NSString *valuesListValue in filtersListValue.values) {
                    if (valuesListValue != nil) {
                        [request setParameterValue:[NSString stringWithFormat:@"%@", valuesListValue] forKey:[NSString stringWithFormat:@"%@.%d.%@.%d", @"Filter", filtersListIndex, @"Value", valuesListIndex]];
                    }

                    valuesListIndex++;
                }
            }

            filtersListIndex++;
        }
    }


    return [request autorelease];
}

@end

