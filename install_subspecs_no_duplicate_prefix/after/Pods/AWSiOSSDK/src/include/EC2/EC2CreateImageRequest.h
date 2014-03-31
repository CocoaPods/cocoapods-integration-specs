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

#import "EC2BlockDeviceMapping.h"

#ifdef AWS_MULTI_FRAMEWORK
#import <AWSRuntime/AmazonServiceRequestConfig.h>
#else
#import "../AmazonServiceRequestConfig.h"
#endif



/**
 * Create Image Request
 */

@interface EC2CreateImageRequest:AmazonServiceRequestConfig

{
    BOOL           dryRun;
    BOOL           dryRunIsSet;
    NSString       *instanceId;
    NSString       *name;
    NSString       *descriptionValue;
    BOOL           noReboot;
    BOOL           noRebootIsSet;
    NSMutableArray *blockDeviceMappings;
}



/**
 * The value of the DryRun property for this object.
 */
@property (nonatomic) BOOL           dryRun;

@property (nonatomic, readonly) BOOL dryRunIsSet;

/**
 * The ID of the instance from which to create the new image.
 */
@property (nonatomic, retain) NSString *instanceId;

/**
 * The name for the new AMI being created.
 */
@property (nonatomic, retain) NSString *name;

/**
 * The description for the new AMI being created.
 */
@property (nonatomic, retain) NSString *descriptionValue;

/**
 * By default this property is set to <code>false</code>, which means
 * Amazon EC2 attempts to cleanly shut down the instance before image
 * creation and reboots the instance afterwards. When set to true, Amazon
 * EC2 will not shut down the instance before creating the image. When
 * this option is used, file system integrity on the created image cannot
 * be guaranteed.
 */
@property (nonatomic) BOOL           noReboot;

@property (nonatomic, readonly) BOOL noRebootIsSet;

/**
 * The value of the BlockDeviceMappings property for this object.
 */
@property (nonatomic, retain) NSMutableArray *blockDeviceMappings;


/**
 * Default constructor for a new CreateImageRequest object.  Callers should use the
 * property methods to initialize this object after creating it.
 */
-(id)init;

/**
 * Constructs a new CreateImageRequest object.
 * Callers should use properties to initialize any additional object members.
 *
 * @param theInstanceId The ID of the instance from which to create the
 * new image.
 * @param theName The name for the new AMI being created.
 */
-(id)initWithInstanceId:(NSString *)theInstanceId andName:(NSString *)theName;

/**
 * Adds a single object to blockDeviceMappings.
 * This function will alloc and init blockDeviceMappings if not already done.
 */
-(void)addBlockDeviceMapping:(EC2BlockDeviceMapping *)blockDeviceMappingObject;

/**
 * Returns a string representation of this object; useful for testing and
 * debugging.
 *
 * @return A string representation of this object.
 */
-(NSString *)description;


@end
