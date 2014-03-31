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

#import "EC2Placement.h"
#import "EC2BlockDeviceMapping.h"
#import "EC2InstanceLicenseSpecification.h"
#import "EC2InstanceNetworkInterfaceSpecification.h"
#import "EC2IamInstanceProfileSpecification.h"

#ifdef AWS_MULTI_FRAMEWORK
#import <AWSRuntime/AmazonServiceRequestConfig.h>
#else
#import "../AmazonServiceRequestConfig.h"
#endif



/**
 * Run Instances Request
 */

@interface EC2RunInstancesRequest:AmazonServiceRequestConfig

{
    BOOL                               dryRun;
    BOOL                               dryRunIsSet;
    NSString                           *imageId;
    NSNumber                           *minCount;
    NSNumber                           *maxCount;
    NSString                           *keyName;
    NSMutableArray                     *securityGroups;
    NSMutableArray                     *securityGroupIds;
    NSString                           *userData;
    NSString                           *instanceType;
    EC2Placement                       *placement;
    NSString                           *kernelId;
    NSString                           *ramdiskId;
    NSMutableArray                     *blockDeviceMappings;
    BOOL                               monitoring;
    BOOL                               monitoringIsSet;
    NSString                           *subnetId;
    BOOL                               disableApiTermination;
    BOOL                               disableApiTerminationIsSet;
    NSString                           *instanceInitiatedShutdownBehavior;
    EC2InstanceLicenseSpecification    *license;
    NSString                           *privateIpAddress;
    NSString                           *clientToken;
    NSString                           *additionalInfo;
    NSMutableArray                     *networkInterfaces;
    EC2IamInstanceProfileSpecification *iamInstanceProfile;
    BOOL                               ebsOptimized;
    BOOL                               ebsOptimizedIsSet;
}



/**
 * The value of the DryRun property for this object.
 */
@property (nonatomic) BOOL           dryRun;

@property (nonatomic, readonly) BOOL dryRunIsSet;

/**
 * Unique ID of a machine image, returned by a call to DescribeImages.
 */
@property (nonatomic, retain) NSString *imageId;

/**
 * Minimum number of instances to launch. If the value is more than
 * Amazon EC2 can launch, no instances are launched at all.
 */
@property (nonatomic, retain) NSNumber *minCount;

/**
 * Maximum number of instances to launch. If the value is more than
 * Amazon EC2 can launch, the largest possible number above minCount will
 * be launched instead. <p> Between 1 and the maximum number allowed for
 * your account (default: 20).
 */
@property (nonatomic, retain) NSNumber *maxCount;

/**
 * The name of the key pair.
 */
@property (nonatomic, retain) NSString *keyName;

/**
 * The names of the security groups into which the instances will be
 * launched.
 */
@property (nonatomic, retain) NSMutableArray *securityGroups;

/**
 * The value of the SecurityGroupIds property for this object.
 */
@property (nonatomic, retain) NSMutableArray *securityGroupIds;

/**
 * Specifies additional information to make available to the instance(s).
 * This parameter must be passed as a Base64-encoded string.
 */
@property (nonatomic, retain) NSString *userData;

/**
 * Specifies the instance type for the launched instances.
 * <p>
 * <b>Constraints:</b><br/>
 * <b>Allowed Values: </b>t1.micro, m1.small, m1.medium, m1.large, m1.xlarge, m3.xlarge, m3.2xlarge, m2.xlarge, m2.2xlarge, m2.4xlarge, cr1.8xlarge, hi1.4xlarge, hs1.8xlarge, c1.medium, c1.xlarge, c3.large, c3.xlarge, c3.2xlarge, c3.4xlarge, c3.8xlarge, cc1.4xlarge, cc2.8xlarge, g2.2xlarge, cg1.4xlarge
 */
@property (nonatomic, retain) NSString *instanceType;

/**
 * Specifies the placement constraints (Availability Zones) for launching
 * the instances.
 */
@property (nonatomic, retain) EC2Placement *placement;

/**
 * The ID of the kernel with which to launch the instance.
 */
@property (nonatomic, retain) NSString *kernelId;

/**
 * The ID of the RAM disk with which to launch the instance. Some kernels
 * require additional drivers at launch. Check the kernel requirements
 * for information on whether you need to specify a RAM disk. To find
 * kernel requirements, go to the Resource Center and search for the
 * kernel ID.
 */
@property (nonatomic, retain) NSString *ramdiskId;

/**
 * Specifies how block devices are exposed to the instance. Each mapping
 * is made up of a virtualName and a deviceName.
 */
@property (nonatomic, retain) NSMutableArray *blockDeviceMappings;

/**
 * Enables monitoring for the instance.
 */
@property (nonatomic) BOOL           monitoring;

@property (nonatomic, readonly) BOOL monitoringIsSet;

/**
 * Specifies the subnet ID within which to launch the instance(s) for
 * Amazon Virtual Private Cloud.
 */
@property (nonatomic, retain) NSString *subnetId;

/**
 * Specifies whether the instance can be terminated using the APIs. You
 * must modify this attribute before you can terminate any "locked"
 * instances from the APIs.
 */
@property (nonatomic) BOOL           disableApiTermination;

@property (nonatomic, readonly) BOOL disableApiTerminationIsSet;

/**
 * Specifies whether the instance's Amazon EBS volumes are stopped or
 * terminated when the instance is shut down.
 * <p>
 * <b>Constraints:</b><br/>
 * <b>Allowed Values: </b>stop, terminate
 */
@property (nonatomic, retain) NSString *instanceInitiatedShutdownBehavior;

/**
 * Specifies active licenses in use and attached to an Amazon EC2
 * instance.
 */
@property (nonatomic, retain) EC2InstanceLicenseSpecification *license;

/**
 * If you're using Amazon Virtual Private Cloud, you can optionally use
 * this parameter to assign the instance a specific available IP address
 * from the subnet.
 */
@property (nonatomic, retain) NSString *privateIpAddress;

/**
 * Unique, case-sensitive identifier you provide to ensure idempotency of
 * the request. For more information, go to How to Ensure Idempotency in
 * the Amazon Elastic Compute Cloud User Guide.
 */
@property (nonatomic, retain) NSString *clientToken;

/**
 * Do not use. Reserved for internal use.
 */
@property (nonatomic, retain) NSString *additionalInfo;

/**
 * List of network interfaces associated with the instance.
 */
@property (nonatomic, retain) NSMutableArray *networkInterfaces;

/**
 * The value of the IamInstanceProfile property for this object.
 */
@property (nonatomic, retain) EC2IamInstanceProfileSpecification *iamInstanceProfile;

/**
 * The value of the EbsOptimized property for this object.
 */
@property (nonatomic) BOOL           ebsOptimized;

@property (nonatomic, readonly) BOOL ebsOptimizedIsSet;


/**
 * Default constructor for a new RunInstancesRequest object.  Callers should use the
 * property methods to initialize this object after creating it.
 */
-(id)init;

/**
 * Constructs a new RunInstancesRequest object.
 * Callers should use properties to initialize any additional object members.
 *
 * @param theImageId Unique ID of a machine image, returned by a call to
 * DescribeImages.
 * @param theMinCount Minimum number of instances to launch. If the value
 * is more than Amazon EC2 can launch, no instances are launched at all.
 * @param theMaxCount Maximum number of instances to launch. If the value
 * is more than Amazon EC2 can launch, the largest possible number above
 * minCount will be launched instead. <p> Between 1 and the maximum
 * number allowed for your account (default: 20).
 */
-(id)initWithImageId:(NSString *)theImageId andMinCount:(NSNumber *)theMinCount andMaxCount:(NSNumber *)theMaxCount;

/**
 * Adds a single object to securityGroups.
 * This function will alloc and init securityGroups if not already done.
 */
-(void)addSecurityGroup:(NSString *)securityGroupObject;

/**
 * Adds a single object to securityGroupIds.
 * This function will alloc and init securityGroupIds if not already done.
 */
-(void)addSecurityGroupId:(NSString *)securityGroupIdObject;

/**
 * Adds a single object to blockDeviceMappings.
 * This function will alloc and init blockDeviceMappings if not already done.
 */
-(void)addBlockDeviceMapping:(EC2BlockDeviceMapping *)blockDeviceMappingObject;

/**
 * Adds a single object to networkInterfaces.
 * This function will alloc and init networkInterfaces if not already done.
 */
-(void)addNetworkInterface:(EC2InstanceNetworkInterfaceSpecification *)networkInterfaceObject;

/**
 * Returns a string representation of this object; useful for testing and
 * debugging.
 *
 * @return A string representation of this object.
 */
-(NSString *)description;


@end
