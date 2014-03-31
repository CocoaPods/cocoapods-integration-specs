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
 * Product Code
 */

@interface EC2ProductCode:NSObject

{
    NSString *productCodeId;
    NSString *productCodeType;
}




/**
 * Default constructor for a new  object.  Callers should use the
 * property methods to initialize this object after creating it.
 */
-(id)init;

/**
 * The unique ID of an AWS DevPay product code.
 */
@property (nonatomic, retain) NSString *productCodeId;

/**
 * The value of the ProductCodeType property for this object.
 * <p>
 * <b>Constraints:</b><br/>
 * <b>Allowed Values: </b>devpay, marketplace
 */
@property (nonatomic, retain) NSString *productCodeType;

/**
 * Returns a string representation of this object; useful for testing and
 * debugging.
 *
 * @return A string representation of this object.
 */
-(NSString *)description;


@end
