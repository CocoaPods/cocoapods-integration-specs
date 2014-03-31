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

#import "EC2PriceScheduleSpecification.h"

#ifdef AWS_MULTI_FRAMEWORK
#import <AWSRuntime/AmazonServiceRequestConfig.h>
#else
#import "../AmazonServiceRequestConfig.h"
#endif



/**
 * Create Reserved Instances Listing Request
 */

@interface EC2CreateReservedInstancesListingRequest:AmazonServiceRequestConfig

{
    NSString       *reservedInstancesId;
    NSNumber       *instanceCount;
    NSMutableArray *priceSchedules;
    NSString       *clientToken;
}




/**
 * Default constructor for a new  object.  Callers should use the
 * property methods to initialize this object after creating it.
 */
-(id)init;

/**
 * The value of the ReservedInstancesId property for this object.
 */
@property (nonatomic, retain) NSString *reservedInstancesId;

/**
 * The value of the InstanceCount property for this object.
 */
@property (nonatomic, retain) NSNumber *instanceCount;

/**
 * The value of the PriceSchedules property for this object.
 */
@property (nonatomic, retain) NSMutableArray *priceSchedules;

/**
 * The value of the ClientToken property for this object.
 */
@property (nonatomic, retain) NSString *clientToken;

/**
 * Adds a single object to priceSchedules.
 * This function will alloc and init priceSchedules if not already done.
 */
-(void)addPriceSchedule:(EC2PriceScheduleSpecification *)priceScheduleObject;

/**
 * Returns a string representation of this object; useful for testing and
 * debugging.
 *
 * @return A string representation of this object.
 */
-(NSString *)description;


@end
