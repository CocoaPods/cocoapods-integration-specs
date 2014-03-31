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
 * Activate License Request
 */

@interface EC2ActivateLicenseRequest:AmazonServiceRequestConfig

{
    BOOL     dryRun;
    BOOL     dryRunIsSet;
    NSString *licenseId;
    NSNumber *capacity;
}



/**
 * The value of the DryRun property for this object.
 */
@property (nonatomic) BOOL           dryRun;

@property (nonatomic, readonly) BOOL dryRunIsSet;

/**
 * Specifies the ID for the specific license to activate against.
 */
@property (nonatomic, retain) NSString *licenseId;

/**
 * Specifies the additional number of licenses to activate.
 */
@property (nonatomic, retain) NSNumber *capacity;


/**
 * Default constructor for a new ActivateLicenseRequest object.  Callers should use the
 * property methods to initialize this object after creating it.
 */
-(id)init;

/**
 * Constructs a new ActivateLicenseRequest object.
 * Callers should use properties to initialize any additional object members.
 *
 * @param theLicenseId Specifies the ID for the specific license to
 * activate against.
 * @param theCapacity Specifies the additional number of licenses to
 * activate.
 */
-(id)initWithLicenseId:(NSString *)theLicenseId andCapacity:(NSNumber *)theCapacity;

/**
 * Returns a string representation of this object; useful for testing and
 * debugging.
 *
 * @return A string representation of this object.
 */
-(NSString *)description;


@end
