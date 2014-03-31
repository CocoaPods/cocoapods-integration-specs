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

#import "EC2DescribeReservedInstancesOfferingsRequestMarshaller.h"

@implementation EC2DescribeReservedInstancesOfferingsRequestMarshaller

+(AmazonServiceRequest *)createRequest:(EC2DescribeReservedInstancesOfferingsRequest *)describeReservedInstancesOfferingsRequest
{
    AmazonServiceRequest *request = [[EC2Request alloc] init];

    [request setParameterValue:@"DescribeReservedInstancesOfferings"           forKey:@"Action"];
    [request setParameterValue:@"2013-10-15"   forKey:@"Version"];

    [request setDelegate:[describeReservedInstancesOfferingsRequest delegate]];
    [request setCredentials:[describeReservedInstancesOfferingsRequest credentials]];
    [request setEndpoint:[describeReservedInstancesOfferingsRequest requestEndpoint]];
    [request setRequestTag:[describeReservedInstancesOfferingsRequest requestTag]];

    if (describeReservedInstancesOfferingsRequest != nil) {
        if (describeReservedInstancesOfferingsRequest.dryRunIsSet) {
            [request setParameterValue:(describeReservedInstancesOfferingsRequest.dryRun ? @"true":@"false") forKey:[NSString stringWithFormat:@"%@", @"DryRun"]];
        }
    }

    if (describeReservedInstancesOfferingsRequest != nil) {
        int reservedInstancesOfferingIdsListIndex = 1;
        for (NSString *reservedInstancesOfferingIdsListValue in describeReservedInstancesOfferingsRequest.reservedInstancesOfferingIds) {
            if (reservedInstancesOfferingIdsListValue != nil) {
                [request setParameterValue:[NSString stringWithFormat:@"%@", reservedInstancesOfferingIdsListValue] forKey:[NSString stringWithFormat:@"%@.%d", @"ReservedInstancesOfferingId", reservedInstancesOfferingIdsListIndex]];
            }

            reservedInstancesOfferingIdsListIndex++;
        }
    }
    if (describeReservedInstancesOfferingsRequest != nil) {
        if (describeReservedInstancesOfferingsRequest.instanceType != nil) {
            [request setParameterValue:[NSString stringWithFormat:@"%@", describeReservedInstancesOfferingsRequest.instanceType] forKey:[NSString stringWithFormat:@"%@", @"InstanceType"]];
        }
    }
    if (describeReservedInstancesOfferingsRequest != nil) {
        if (describeReservedInstancesOfferingsRequest.availabilityZone != nil) {
            [request setParameterValue:[NSString stringWithFormat:@"%@", describeReservedInstancesOfferingsRequest.availabilityZone] forKey:[NSString stringWithFormat:@"%@", @"AvailabilityZone"]];
        }
    }
    if (describeReservedInstancesOfferingsRequest != nil) {
        if (describeReservedInstancesOfferingsRequest.productDescription != nil) {
            [request setParameterValue:[NSString stringWithFormat:@"%@", describeReservedInstancesOfferingsRequest.productDescription] forKey:[NSString stringWithFormat:@"%@", @"ProductDescription"]];
        }
    }

    if (describeReservedInstancesOfferingsRequest != nil) {
        int filtersListIndex = 1;
        for (EC2Filter *filtersListValue in describeReservedInstancesOfferingsRequest.filters) {
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
    if (describeReservedInstancesOfferingsRequest != nil) {
        if (describeReservedInstancesOfferingsRequest.instanceTenancy != nil) {
            [request setParameterValue:[NSString stringWithFormat:@"%@", describeReservedInstancesOfferingsRequest.instanceTenancy] forKey:[NSString stringWithFormat:@"%@", @"InstanceTenancy"]];
        }
    }
    if (describeReservedInstancesOfferingsRequest != nil) {
        if (describeReservedInstancesOfferingsRequest.offeringType != nil) {
            [request setParameterValue:[NSString stringWithFormat:@"%@", describeReservedInstancesOfferingsRequest.offeringType] forKey:[NSString stringWithFormat:@"%@", @"OfferingType"]];
        }
    }
    if (describeReservedInstancesOfferingsRequest != nil) {
        if (describeReservedInstancesOfferingsRequest.nextToken != nil) {
            [request setParameterValue:[NSString stringWithFormat:@"%@", describeReservedInstancesOfferingsRequest.nextToken] forKey:[NSString stringWithFormat:@"%@", @"NextToken"]];
        }
    }
    if (describeReservedInstancesOfferingsRequest != nil) {
        if (describeReservedInstancesOfferingsRequest.maxResults != nil) {
            [request setParameterValue:[NSString stringWithFormat:@"%@", describeReservedInstancesOfferingsRequest.maxResults] forKey:[NSString stringWithFormat:@"%@", @"MaxResults"]];
        }
    }
    if (describeReservedInstancesOfferingsRequest != nil) {
        if (describeReservedInstancesOfferingsRequest.includeMarketplaceIsSet) {
            [request setParameterValue:(describeReservedInstancesOfferingsRequest.includeMarketplace ? @"true":@"false") forKey:[NSString stringWithFormat:@"%@", @"IncludeMarketplace"]];
        }
    }
    if (describeReservedInstancesOfferingsRequest != nil) {
        if (describeReservedInstancesOfferingsRequest.minDuration != nil) {
            [request setParameterValue:[NSString stringWithFormat:@"%@", describeReservedInstancesOfferingsRequest.minDuration] forKey:[NSString stringWithFormat:@"%@", @"MinDuration"]];
        }
    }
    if (describeReservedInstancesOfferingsRequest != nil) {
        if (describeReservedInstancesOfferingsRequest.maxDuration != nil) {
            [request setParameterValue:[NSString stringWithFormat:@"%@", describeReservedInstancesOfferingsRequest.maxDuration] forKey:[NSString stringWithFormat:@"%@", @"MaxDuration"]];
        }
    }
    if (describeReservedInstancesOfferingsRequest != nil) {
        if (describeReservedInstancesOfferingsRequest.maxInstanceCount != nil) {
            [request setParameterValue:[NSString stringWithFormat:@"%@", describeReservedInstancesOfferingsRequest.maxInstanceCount] forKey:[NSString stringWithFormat:@"%@", @"MaxInstanceCount"]];
        }
    }


    return [request autorelease];
}

@end

