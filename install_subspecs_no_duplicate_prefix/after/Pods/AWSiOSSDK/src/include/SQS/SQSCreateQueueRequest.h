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
 * Create Queue Request
 */

@interface SQSCreateQueueRequest:AmazonServiceRequestConfig

{
    NSString            *queueName;
    NSMutableDictionary *attributes;
}



/**
 * The name for the queue to be created.
 */
@property (nonatomic, retain) NSString *queueName;

/**
 * A map of attributes with their corresponding values.
 */
@property (nonatomic, retain) NSMutableDictionary *attributes;


/**
 * Default constructor for a new CreateQueueRequest object.  Callers should use the
 * property methods to initialize this object after creating it.
 */
-(id)init;

/**
 * Constructs a new CreateQueueRequest object.
 * Callers should use properties to initialize any additional object members.
 *
 * @param theQueueName The name for the queue to be created.
 */
-(id)initWithQueueName:(NSString *)theQueueName;


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
