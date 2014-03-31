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
 * Delete Key Pair Request
 */

@interface EC2DeleteKeyPairRequest:AmazonServiceRequestConfig

{
    BOOL     dryRun;
    BOOL     dryRunIsSet;
    NSString *keyName;
}



/**
 * The value of the DryRun property for this object.
 */
@property (nonatomic) BOOL           dryRun;

@property (nonatomic, readonly) BOOL dryRunIsSet;

/**
 * The name of the Amazon EC2 key pair to delete.
 */
@property (nonatomic, retain) NSString *keyName;


/**
 * Default constructor for a new DeleteKeyPairRequest object.  Callers should use the
 * property methods to initialize this object after creating it.
 */
-(id)init;

/**
 * Constructs a new DeleteKeyPairRequest object.
 * Callers should use properties to initialize any additional object members.
 *
 * @param theKeyName The name of the Amazon EC2 key pair to delete.
 */
-(id)initWithKeyName:(NSString *)theKeyName;

/**
 * Returns a string representation of this object; useful for testing and
 * debugging.
 *
 * @return A string representation of this object.
 */
-(NSString *)description;


@end
