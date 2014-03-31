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

#import "ElasticLoadBalancingInstance.h"

#ifdef AWS_MULTI_FRAMEWORK
#import <AWSRuntime/AmazonServiceRequestConfig.h>
#else
#import "../AmazonServiceRequestConfig.h"
#endif



/**
 * Describe Instance Health Request
 */

@interface ElasticLoadBalancingDescribeInstanceHealthRequest:AmazonServiceRequestConfig

{
    NSString       *loadBalancerName;
    NSMutableArray *instances;
}



/**
 * The name of the load balancer.
 */
@property (nonatomic, retain) NSString *loadBalancerName;

/**
 * A list of instance IDs whose states are being queried.
 */
@property (nonatomic, retain) NSMutableArray *instances;


/**
 * Default constructor for a new DescribeInstanceHealthRequest object.  Callers should use the
 * property methods to initialize this object after creating it.
 */
-(id)init;

/**
 * Constructs a new DescribeInstanceHealthRequest object.
 * Callers should use properties to initialize any additional object members.
 *
 * @param theLoadBalancerName The name of the load balancer.
 */
-(id)initWithLoadBalancerName:(NSString *)theLoadBalancerName;

/**
 * Adds a single object to instances.
 * This function will alloc and init instances if not already done.
 */
-(void)addInstance:(ElasticLoadBalancingInstance *)instanceObject;

/**
 * Returns a string representation of this object; useful for testing and
 * debugging.
 *
 * @return A string representation of this object.
 */
-(NSString *)description;


@end
