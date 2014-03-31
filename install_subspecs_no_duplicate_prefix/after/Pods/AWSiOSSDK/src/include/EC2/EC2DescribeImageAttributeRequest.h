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
 * Describe Image Attribute Request
 */

@interface EC2DescribeImageAttributeRequest:AmazonServiceRequestConfig

{
    BOOL     dryRun;
    BOOL     dryRunIsSet;
    NSString *imageId;
    NSString *attribute;
}



/**
 * The value of the DryRun property for this object.
 */
@property (nonatomic) BOOL           dryRun;

@property (nonatomic, readonly) BOOL dryRunIsSet;

/**
 * The ID of the AMI whose attribute is to be described.
 */
@property (nonatomic, retain) NSString *imageId;

/**
 * The name of the attribute to describe. <p> Available attribute names:
 * <code>productCodes</code>, <code>kernel</code>, <code>ramdisk</code>,
 * <code>launchPermisson</code>, <code>blockDeviceMapping</code>
 * <p>
 * <b>Constraints:</b><br/>
 * <b>Allowed Values: </b>description, kernel, ramdisk, launchPermission, productCodes, blockDeviceMapping
 */
@property (nonatomic, retain) NSString *attribute;


/**
 * Default constructor for a new DescribeImageAttributeRequest object.  Callers should use the
 * property methods to initialize this object after creating it.
 */
-(id)init;

/**
 * Constructs a new DescribeImageAttributeRequest object.
 * Callers should use properties to initialize any additional object members.
 *
 * @param theImageId The ID of the AMI whose attribute is to be
 * described.
 * @param theAttribute The name of the attribute to describe. <p>
 * Available attribute names: <code>productCodes</code>,
 * <code>kernel</code>, <code>ramdisk</code>,
 * <code>launchPermisson</code>, <code>blockDeviceMapping</code>
 */
-(id)initWithImageId:(NSString *)theImageId andAttribute:(NSString *)theAttribute;

/**
 * Returns a string representation of this object; useful for testing and
 * debugging.
 *
 * @return A string representation of this object.
 */
-(NSString *)description;


@end
