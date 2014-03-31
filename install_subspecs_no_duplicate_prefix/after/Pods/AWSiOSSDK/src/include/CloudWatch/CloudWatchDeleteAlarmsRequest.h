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
 * Delete Alarms Request
 */

@interface CloudWatchDeleteAlarmsRequest:AmazonServiceRequestConfig

{
    NSMutableArray *alarmNames;
}




/**
 * Default constructor for a new  object.  Callers should use the
 * property methods to initialize this object after creating it.
 */
-(id)init;

/**
 * A list of alarms to be deleted.
 * <p>
 * <b>Constraints:</b><br/>
 * <b>Length: </b>0 - 100<br/>
 */
@property (nonatomic, retain) NSMutableArray *alarmNames;

/**
 * Adds a single object to alarmNames.
 * This function will alloc and init alarmNames if not already done.
 */
-(void)addAlarmName:(NSString *)alarmNameObject;

/**
 * Returns a string representation of this object; useful for testing and
 * debugging.
 *
 * @return A string representation of this object.
 */
-(NSString *)description;


@end
