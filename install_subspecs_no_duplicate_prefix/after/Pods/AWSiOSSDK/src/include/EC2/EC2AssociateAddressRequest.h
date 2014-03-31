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
 * Associate Address Request
 */

@interface EC2AssociateAddressRequest:AmazonServiceRequestConfig

{
    BOOL     dryRun;
    BOOL     dryRunIsSet;
    NSString *instanceId;
    NSString *publicIp;
    NSString *allocationId;
    NSString *networkInterfaceId;
    NSString *privateIpAddress;
    BOOL     allowReassociation;
    BOOL     allowReassociationIsSet;
}



/**
 * The value of the DryRun property for this object.
 */
@property (nonatomic) BOOL           dryRun;

@property (nonatomic, readonly) BOOL dryRunIsSet;

/**
 * The instance to associate with the IP address.
 */
@property (nonatomic, retain) NSString *instanceId;

/**
 * IP address that you are assigning to the instance.
 */
@property (nonatomic, retain) NSString *publicIp;

/**
 * The allocation ID that AWS returned when you allocated the elastic IP
 * address for use with Amazon VPC.
 */
@property (nonatomic, retain) NSString *allocationId;

/**
 * The value of the NetworkInterfaceId property for this object.
 */
@property (nonatomic, retain) NSString *networkInterfaceId;

/**
 * The value of the PrivateIpAddress property for this object.
 */
@property (nonatomic, retain) NSString *privateIpAddress;

/**
 * The value of the AllowReassociation property for this object.
 */
@property (nonatomic) BOOL           allowReassociation;

@property (nonatomic, readonly) BOOL allowReassociationIsSet;


/**
 * Default constructor for a new AssociateAddressRequest object.  Callers should use the
 * property methods to initialize this object after creating it.
 */
-(id)init;

/**
 * Constructs a new AssociateAddressRequest object.
 * Callers should use properties to initialize any additional object members.
 *
 * @param theInstanceId The instance to associate with the IP address.
 * @param thePublicIp IP address that you are assigning to the instance.
 */
-(id)initWithInstanceId:(NSString *)theInstanceId andPublicIp:(NSString *)thePublicIp;

/**
 * Returns a string representation of this object; useful for testing and
 * debugging.
 *
 * @return A string representation of this object.
 */
-(NSString *)description;


@end
