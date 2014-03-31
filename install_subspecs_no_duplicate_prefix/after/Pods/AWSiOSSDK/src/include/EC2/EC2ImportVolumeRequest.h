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

#import "EC2DiskImageDetail.h"
#import "EC2VolumeDetail.h"

#ifdef AWS_MULTI_FRAMEWORK
#import <AWSRuntime/AmazonServiceRequestConfig.h>
#else
#import "../AmazonServiceRequestConfig.h"
#endif



/**
 * Import Volume Request
 */

@interface EC2ImportVolumeRequest:AmazonServiceRequestConfig

{
    BOOL               dryRun;
    BOOL               dryRunIsSet;
    NSString           *availabilityZone;
    EC2DiskImageDetail *image;
    NSString           *descriptionValue;
    EC2VolumeDetail    *volume;
}




/**
 * Default constructor for a new  object.  Callers should use the
 * property methods to initialize this object after creating it.
 */
-(id)init;

/**
 * The value of the DryRun property for this object.
 */
@property (nonatomic) BOOL           dryRun;

@property (nonatomic, readonly) BOOL dryRunIsSet;

/**
 * The value of the AvailabilityZone property for this object.
 */
@property (nonatomic, retain) NSString *availabilityZone;

/**
 * The value of the Image property for this object.
 */
@property (nonatomic, retain) EC2DiskImageDetail *image;

/**
 * The value of the Description property for this object.
 */
@property (nonatomic, retain) NSString *descriptionValue;

/**
 * The value of the Volume property for this object.
 */
@property (nonatomic, retain) EC2VolumeDetail *volume;

/**
 * Returns a string representation of this object; useful for testing and
 * debugging.
 *
 * @return A string representation of this object.
 */
-(NSString *)description;


@end
