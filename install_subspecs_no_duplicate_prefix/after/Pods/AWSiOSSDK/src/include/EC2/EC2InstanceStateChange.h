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

#import "EC2InstanceState.h"
#import "EC2InstanceState.h"



/**
 * Instance State Change
 */

@interface EC2InstanceStateChange:NSObject

{
    NSString         *instanceId;
    EC2InstanceState *currentState;
    EC2InstanceState *previousState;
}




/**
 * Default constructor for a new  object.  Callers should use the
 * property methods to initialize this object after creating it.
 */
-(id)init;

/**
 * The ID of the instance whose state changed.
 */
@property (nonatomic, retain) NSString *instanceId;

/**
 * The current state of the specified instance.
 */
@property (nonatomic, retain) EC2InstanceState *currentState;

/**
 * The previous state of the specified instance.
 */
@property (nonatomic, retain) EC2InstanceState *previousState;

/**
 * Returns a string representation of this object; useful for testing and
 * debugging.
 *
 * @return A string representation of this object.
 */
-(NSString *)description;


@end
