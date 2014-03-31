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




/**
 * Disk Image Description
 */

@interface EC2DiskImageDescription:NSObject

{
    NSString *format;
    NSNumber *size;
    NSString *importManifestUrl;
    NSString *checksum;
}




/**
 * Default constructor for a new  object.  Callers should use the
 * property methods to initialize this object after creating it.
 */
-(id)init;

/**
 * The value of the Format property for this object.
 * <p>
 * <b>Constraints:</b><br/>
 * <b>Allowed Values: </b>VMDK, RAW, VHD
 */
@property (nonatomic, retain) NSString *format;

/**
 * The value of the Size property for this object.
 */
@property (nonatomic, retain) NSNumber *size;

/**
 * The value of the ImportManifestUrl property for this object.
 */
@property (nonatomic, retain) NSString *importManifestUrl;

/**
 * The value of the Checksum property for this object.
 */
@property (nonatomic, retain) NSString *checksum;

/**
 * Returns a string representation of this object; useful for testing and
 * debugging.
 *
 * @return A string representation of this object.
 */
-(NSString *)description;


@end
