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
 * Describe Reserved Instances Modifications Request
 */

@interface EC2DescribeReservedInstancesModificationsRequest:AmazonServiceRequestConfig

{
    NSMutableArray *reservedInstancesModificationIds;
    NSString       *nextToken;
    NSMutableArray *filters;
}




/**
 * Default constructor for a new  object.  Callers should use the
 * property methods to initialize this object after creating it.
 */
-(id)init;

/**
 * An optional list of Reserved Instances modification IDs to describe.
 */
@property (nonatomic, retain) NSMutableArray *reservedInstancesModificationIds;

/**
 * A string specifying the next paginated set of results to return.
 */
@property (nonatomic, retain) NSString *nextToken;

/**
 * A list of filters used to match properties for
 * ReservedInstancesModifications. For a complete reference to the
 * available filter keys for this operation, see the <a
 * "http://docs.amazonwebservices.com/AWSEC2/latest/APIReference/">Amazon
 * EC2 API reference</a>.
 */
@property (nonatomic, retain) NSMutableArray *filters;

/**
 * Adds a single object to reservedInstancesModificationIds.
 * This function will alloc and init reservedInstancesModificationIds if not already done.
 */
-(void)addReservedInstancesModificationId:(NSString *)reservedInstancesModificationIdObject;

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
