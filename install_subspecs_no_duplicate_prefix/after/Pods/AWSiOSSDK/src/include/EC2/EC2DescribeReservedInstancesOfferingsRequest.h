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

#import "EC2Filter.h"

#ifdef AWS_MULTI_FRAMEWORK
#import <AWSRuntime/AmazonServiceRequestConfig.h>
#else
#import "../AmazonServiceRequestConfig.h"
#endif



/**
 * Describe Reserved Instances Offerings Request
 */

@interface EC2DescribeReservedInstancesOfferingsRequest:AmazonServiceRequestConfig

{
    BOOL           dryRun;
    BOOL           dryRunIsSet;
    NSMutableArray *reservedInstancesOfferingIds;
    NSString       *instanceType;
    NSString       *availabilityZone;
    NSString       *productDescription;
    NSMutableArray *filters;
    NSString       *instanceTenancy;
    NSString       *offeringType;
    NSString       *nextToken;
    NSNumber       *maxResults;
    BOOL           includeMarketplace;
    BOOL           includeMarketplaceIsSet;
    NSNumber       *minDuration;
    NSNumber       *maxDuration;
    NSNumber       *maxInstanceCount;
}




/**
 * Default constructor for a new  object.  Callers should use the
 * property methods to initialize this object after creating it.
 */
-(id)init;

/**
 * The value of the DryRun property for this object.
 */
@property (nonatomic) BOOL           dryRun;

@property (nonatomic, readonly) BOOL dryRunIsSet;

/**
 * An optional list of the unique IDs of the Reserved Instance offerings
 * to describe.
 */
@property (nonatomic, retain) NSMutableArray *reservedInstancesOfferingIds;

/**
 * The instance type on which the Reserved Instance can be used.
 * <p>
 * <b>Constraints:</b><br/>
 * <b>Allowed Values: </b>t1.micro, m1.small, m1.medium, m1.large, m1.xlarge, m3.xlarge, m3.2xlarge, m2.xlarge, m2.2xlarge, m2.4xlarge, cr1.8xlarge, hi1.4xlarge, hs1.8xlarge, c1.medium, c1.xlarge, c3.large, c3.xlarge, c3.2xlarge, c3.4xlarge, c3.8xlarge, cc1.4xlarge, cc2.8xlarge, g2.2xlarge, cg1.4xlarge
 */
@property (nonatomic, retain) NSString *instanceType;

/**
 * The Availability Zone in which the Reserved Instance can be used.
 */
@property (nonatomic, retain) NSString *availabilityZone;

/**
 * The Reserved Instance product description.
 * <p>
 * <b>Constraints:</b><br/>
 * <b>Allowed Values: </b>Linux/UNIX, Linux/UNIX (Amazon VPC), Windows, Windows (Amazon VPC)
 */
@property (nonatomic, retain) NSString *productDescription;

/**
 * A list of filters used to match properties for
 * ReservedInstancesOfferings. For a complete reference to the available
 * filter keys for this operation, see the <a
 * "http://docs.amazonwebservices.com/AWSEC2/latest/APIReference/">Amazon
 * EC2 API reference</a>.
 */
@property (nonatomic, retain) NSMutableArray *filters;

/**
 * The tenancy of the Reserved Instance offering. A Reserved Instance
 * with tenancy of dedicated will run on single-tenant hardware and can
 * only be launched within a VPC.
 * <p>
 * <b>Constraints:</b><br/>
 * <b>Allowed Values: </b>default, dedicated
 */
@property (nonatomic, retain) NSString *instanceTenancy;

/**
 * The Reserved Instance offering type.
 * <p>
 * <b>Constraints:</b><br/>
 * <b>Allowed Values: </b>Heavy Utilization, Medium Utilization, Light Utilization
 */
@property (nonatomic, retain) NSString *offeringType;

/**
 * The value of the NextToken property for this object.
 */
@property (nonatomic, retain) NSString *nextToken;

/**
 * The value of the MaxResults property for this object.
 */
@property (nonatomic, retain) NSNumber *maxResults;

/**
 * Include Marketplace offerings in the response.
 */
@property (nonatomic) BOOL           includeMarketplace;

@property (nonatomic, readonly) BOOL includeMarketplaceIsSet;

/**
 * Minimum duration (in seconds) to filter when searching for offerings.
 */
@property (nonatomic, retain) NSNumber *minDuration;

/**
 * Maximum duration (in seconds) to filter when searching for offerings.
 */
@property (nonatomic, retain) NSNumber *maxDuration;

/**
 * The value of the MaxInstanceCount property for this object.
 */
@property (nonatomic, retain) NSNumber *maxInstanceCount;

/**
 * Adds a single object to reservedInstancesOfferingIds.
 * This function will alloc and init reservedInstancesOfferingIds if not already done.
 */
-(void)addReservedInstancesOfferingId:(NSString *)reservedInstancesOfferingIdObject;

/**
 * Adds a single object to filters.
 * This function will alloc and init filters if not already done.
 */
-(void)addFilter:(EC2Filter *)filterObject;

/**
 * Returns a string representation of this object; useful for testing and
 * debugging.
 *
 * @return A string representation of this object.
 */
-(NSString *)description;


@end
