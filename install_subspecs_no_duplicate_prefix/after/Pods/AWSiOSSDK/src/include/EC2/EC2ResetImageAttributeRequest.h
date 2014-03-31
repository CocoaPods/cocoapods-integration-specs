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
 * Reset Image Attribute Request
 */

@interface EC2ResetImageAttributeRequest:AmazonServiceRequestConfig

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
 * The ID of the AMI whose attribute is being reset.
 */
@property (nonatomic, retain) NSString *imageId;

/**
 * The name of the attribute being reset. <p> Available attribute names:
 * <code>launchPermission</code>
 * <p>
 * <b>Constraints:</b><br/>
 * <b>Allowed Values: </b>launchPermission
 */
@property (nonatomic, retain) NSString *attribute;


/**
 * Default constructor for a new ResetImageAttributeRequest object.  Callers should use the
 * property methods to initialize this object after creating it.
 */
-(id)init;

/**
 * Constructs a new ResetImageAttributeRequest object.
 * Callers should use properties to initialize any additional object members.
 *
 * @param theImageId The ID of the AMI whose attribute is being reset.
 * @param theAttribute The name of the attribute being reset. <p>
 * Available attribute names: <code>launchPermission</code>
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
