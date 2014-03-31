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


#ifdef AWS_MULTI_FRAMEWORK
#import <AWSRuntime/AmazonServiceRequestConfig.h>
#else
#import "../AmazonServiceRequestConfig.h"
#endif



/**
 * Describe Load Balancers Request
 */

@interface ElasticLoadBalancingDescribeLoadBalancersRequest:AmazonServiceRequestConfig

{
    NSMutableArray *loadBalancerNames;
    NSString       *marker;
}



/**
 * A list of load balancer names associated with the account.
 */
@property (nonatomic, retain) NSMutableArray *loadBalancerNames;

/**
 * An optional parameter reserved for future use.
 */
@property (nonatomic, retain) NSString *marker;


/**
 * Default constructor for a new DescribeLoadBalancersRequest object.  Callers should use the
 * property methods to initialize this object after creating it.
 */
-(id)init;

/**
 * Constructs a new DescribeLoadBalancersRequest object.
 * Callers should use properties to initialize any additional object members.
 *
 * @param theLoadBalancerNames A list of load balancer names associated
 * with the account.
 */
-(id)initWithLoadBalancerNames:(NSMutableArray *)theLoadBalancerNames;

/**
 * Adds a single object to loadBalancerNames.
 * This function will alloc and init loadBalancerNames if not already done.
 */
-(void)addLoadBalancerName:(NSString *)loadBalancerNameObject;

/**
 * Returns a string representation of this object; useful for testing and
 * debugging.
 *
 * @return A string representation of this object.
 */
-(NSString *)description;


@end
