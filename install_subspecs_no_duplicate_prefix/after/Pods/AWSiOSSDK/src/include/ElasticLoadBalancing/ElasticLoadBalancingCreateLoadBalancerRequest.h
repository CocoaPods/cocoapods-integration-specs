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

#import "ElasticLoadBalancingListener.h"

#ifdef AWS_MULTI_FRAMEWORK
#import <AWSRuntime/AmazonServiceRequestConfig.h>
#else
#import "../AmazonServiceRequestConfig.h"
#endif



/**
 * Create Load Balancer Request
 */

@interface ElasticLoadBalancingCreateLoadBalancerRequest:AmazonServiceRequestConfig

{
    NSString       *loadBalancerName;
    NSMutableArray *listeners;
    NSMutableArray *availabilityZones;
    NSMutableArray *subnets;
    NSMutableArray *securityGroups;
    NSString       *scheme;
}



/**
 * The name associated with the load balancer. The name must be unique
 * within your set of load balancers.
 */
@property (nonatomic, retain) NSString *loadBalancerName;

/**
 * A list of the following tuples: LoadBalancerPort, InstancePort, and
 * Protocol.
 */
@property (nonatomic, retain) NSMutableArray *listeners;

/**
 * A list of Availability Zones. <p> At least one Availability Zone must
 * be specified. Specified Availability Zones must be in the same EC2
 * Region as the load balancer. Traffic will be equally distributed
 * across all zones. <p> You can later add more Availability Zones after
 * the creation of the load balancer by calling
 * <a>EnableAvailabilityZonesForLoadBalancer</a> action.
 */
@property (nonatomic, retain) NSMutableArray *availabilityZones;

/**
 * A list of subnet IDs in your VPC to attach to your load balancer.
 * Specify one subnet per Availability Zone.
 */
@property (nonatomic, retain) NSMutableArray *subnets;

/**
 * The security groups to assign to your load balancer within your VPC.
 */
@property (nonatomic, retain) NSMutableArray *securityGroups;

/**
 * The type of a load balancer. <p>By default, Elastic Load Balancing
 * creates an Internet-facing load balancer with a publicly resolvable
 * DNS name, which resolves to public IP addresses. For more
 * informationabout Internet-facing and Internal load balancers, see <a
 * ing/latest/DeveloperGuide/vpc-loadbalancer-types.html">Internet-facing
 * and Internal Load Balancers</a>. <p>Specify the value
 * <code>internal</code> for this option to create an internal load
 * balancer with a DNS name that resolves to private IP addresses. <note>
 * <p>This option is only available for load balancers created within
 * EC2-VPC. </note>
 */
@property (nonatomic, retain) NSString *scheme;


/**
 * Default constructor for a new CreateLoadBalancerRequest object.  Callers should use the
 * property methods to initialize this object after creating it.
 */
-(id)init;

/**
 * Constructs a new CreateLoadBalancerRequest object.
 * Callers should use properties to initialize any additional object members.
 *
 * @param theLoadBalancerName The name associated with the load balancer.
 * The name must be unique within your set of load balancers.
 */
-(id)initWithLoadBalancerName:(NSString *)theLoadBalancerName;

/**
 * Constructs a new CreateLoadBalancerRequest object.
 * Callers should use properties to initialize any additional object members.
 *
 * @param theLoadBalancerName The name associated with the load balancer.
 * The name must be unique within your set of load balancers.
 * @param theListeners A list of the following tuples: LoadBalancerPort,
 * InstancePort, and Protocol.
 * @param theAvailabilityZones A list of Availability Zones. <p> At least
 * one Availability Zone must be specified. Specified Availability Zones
 * must be in the same EC2 Region as the load balancer. Traffic will be
 * equally distributed across all zones. <p> You can later add more
 * Availability Zones after the creation of the load balancer by calling
 * <a>EnableAvailabilityZonesForLoadBalancer</a> action.
 */
-(id)initWithLoadBalancerName:(NSString *)theLoadBalancerName andListeners:(NSMutableArray *)theListeners andAvailabilityZones:(NSMutableArray *)theAvailabilityZones;

/**
 * Adds a single object to listeners.
 * This function will alloc and init listeners if not already done.
 */
-(void)addListener:(ElasticLoadBalancingListener *)listenerObject;

/**
 * Adds a single object to availabilityZones.
 * This function will alloc and init availabilityZones if not already done.
 */
-(void)addAvailabilityZone:(NSString *)availabilityZoneObject;

/**
 * Adds a single object to subnets.
 * This function will alloc and init subnets if not already done.
 */
-(void)addSubnet:(NSString *)subnetObject;

/**
 * Adds a single object to securityGroups.
 * This function will alloc and init securityGroups if not already done.
 */
-(void)addSecurityGroup:(NSString *)securityGroupObject;

/**
 * Returns a string representation of this object; useful for testing and
 * debugging.
 *
 * @return A string representation of this object.
 */
-(NSString *)description;


@end
