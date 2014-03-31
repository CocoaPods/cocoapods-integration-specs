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
 * Volume Status Action
 */

@interface EC2VolumeStatusAction:NSObject

{
    NSString *code;
    NSString *descriptionValue;
    NSString *eventType;
    NSString *eventId;
}




/**
 * Default constructor for a new  object.  Callers should use the
 * property methods to initialize this object after creating it.
 */
-(id)init;

/**
 * The value of the Code property for this object.
 */
@property (nonatomic, retain) NSString *code;

/**
 * The value of the Description property for this object.
 */
@property (nonatomic, retain) NSString *descriptionValue;

/**
 * The value of the EventType property for this object.
 */
@property (nonatomic, retain) NSString *eventType;

/**
 * The value of the EventId property for this object.
 */
@property (nonatomic, retain) NSString *eventId;

/**
 * Returns a string representation of this object; useful for testing and
 * debugging.
 *
 * @return A string representation of this object.
 */
-(NSString *)description;


@end
