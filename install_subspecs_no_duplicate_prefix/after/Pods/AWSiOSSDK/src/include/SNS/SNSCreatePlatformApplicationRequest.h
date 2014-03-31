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
 * Create Platform Application Request
 */

@interface SNSCreatePlatformApplicationRequest:AmazonServiceRequestConfig

{
    NSString            *name;
    NSString            *platform;
    NSMutableDictionary *attributes;
}




/**
 * Default constructor for a new  object.  Callers should use the
 * property methods to initialize this object after creating it.
 */
-(id)init;

/**
 * Application names must be made up of only uppercase and lowercase
 * ASCII letters, numbers, underscores, hyphens, and periods, and must be
 * between 1 and 256 characters long.
 */
@property (nonatomic, retain) NSString *name;

/**
 * The following platforms are supported: ADM (Amazon Device Messaging),
 * APNS (Apple Push Notification Service), APNS_SANDBOX, and GCM (Google
 * Cloud Messaging).
 */
@property (nonatomic, retain) NSString *platform;

/**
 * For a list of attributes, see <a
 * atformApplicationAttributes.html">SetPlatformApplicationAttributes</a>
 */
@property (nonatomic, retain) NSMutableDictionary *attributes;


/**
 * Set a value in the dictionary attributes for the specified key.
 * This function will alloc and init attributes if not already done.
 */
-(void)setAttributesValue:(NSString *)theValue forKey:(NSString *)theKey;

/**
 * Returns a string representation of this object; useful for testing and
 * debugging.
 *
 * @return A string representation of this object.
 */
-(NSString *)description;


@end
