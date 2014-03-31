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
 * Set Load Balancer Policies For Backend Server Request
 */

@interface ElasticLoadBalancingSetLoadBalancerPoliciesForBackendServerRequest:AmazonServiceRequestConfig

{
    NSString       *loadBalancerName;
    NSNumber       *instancePort;
    NSMutableArray *policyNames;
}




/**
 * Default constructor for a new  object.  Callers should use the
 * property methods to initialize this object after creating it.
 */
-(id)init;

/**
 * The mnemonic name associated with the load balancer. This name must be
 * unique within the set of your load balancers.
 */
@property (nonatomic, retain) NSString *loadBalancerName;

/**
 * The port number associated with the back-end server.
 */
@property (nonatomic, retain) NSNumber *instancePort;

/**
 * List of policy names to be set. If the list is empty, then all current
 * polices are removed from the back-end server.
 */
@property (nonatomic, retain) NSMutableArray *policyNames;

/**
 * Adds a single object to policyNames.
 * This function will alloc and init policyNames if not already done.
 */
-(void)addPolicyName:(NSString *)policyNameObject;

/**
 * Returns a string representation of this object; useful for testing and
 * debugging.
 *
 * @return A string representation of this object.
 */
-(NSString *)description;


@end
