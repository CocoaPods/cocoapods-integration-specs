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
 * Create Security Group Request
 */

@interface EC2CreateSecurityGroupRequest:AmazonServiceRequestConfig

{
    BOOL     dryRun;
    BOOL     dryRunIsSet;
    NSString *groupName;
    NSString *descriptionValue;
    NSString *vpcId;
}



/**
 * The value of the DryRun property for this object.
 */
@property (nonatomic) BOOL           dryRun;

@property (nonatomic, readonly) BOOL dryRunIsSet;

/**
 * Name of the security group.
 */
@property (nonatomic, retain) NSString *groupName;

/**
 * Description of the group. This is informational only.
 */
@property (nonatomic, retain) NSString *descriptionValue;

/**
 * ID of the VPC.
 */
@property (nonatomic, retain) NSString *vpcId;


/**
 * Default constructor for a new CreateSecurityGroupRequest object.  Callers should use the
 * property methods to initialize this object after creating it.
 */
-(id)init;

/**
 * Constructs a new CreateSecurityGroupRequest object.
 * Callers should use properties to initialize any additional object members.
 *
 * @param theGroupName Name of the security group.
 * @param theDescriptionValue Description of the group. This is
 * informational only.
 */
-(id)initWithGroupName:(NSString *)theGroupName andDescriptionValue:(NSString *)theDescriptionValue;

/**
 * Returns a string representation of this object; useful for testing and
 * debugging.
 *
 * @return A string representation of this object.
 */
-(NSString *)description;


@end
