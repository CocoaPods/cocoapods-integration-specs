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
 * Suspend Processes Request
 */

@interface AutoScalingSuspendProcessesRequest:AmazonServiceRequestConfig

{
    NSString       *autoScalingGroupName;
    NSMutableArray *scalingProcesses;
}




/**
 * Default constructor for a new  object.  Callers should use the
 * property methods to initialize this object after creating it.
 */
-(id)init;

/**
 * The name or Amazon Resource Name (ARN) of the Auto Scaling group.
 * <p>
 * <b>Constraints:</b><br/>
 * <b>Length: </b>1 - 1600<br/>
 * <b>Pattern: </b>[\u0020-\uD7FF\uE000-\uFFFD\uD800\uDC00-\uDBFF\uDFFF\r\n\t]*<br/>
 */
@property (nonatomic, retain) NSString *autoScalingGroupName;

/**
 * The processes that you want to suspend or resume, which can include
 * one or more of the following: <ul> <li>Launch</li> <li>Terminate</li>
 * <li>HealthCheck</li> <li>ReplaceUnhealthy</li> <li>AZRebalance</li>
 * <li>AlarmNotification</li> <li>ScheduledActions</li>
 * <li>AddToLoadBalancer</li> </ul> <p> To suspend all process types,
 * omit this parameter.
 */
@property (nonatomic, retain) NSMutableArray *scalingProcesses;

/**
 * Adds a single object to scalingProcesses.
 * This function will alloc and init scalingProcesses if not already done.
 */
-(void)addScalingProcesse:(NSString *)scalingProcesseObject;

/**
 * Returns a string representation of this object; useful for testing and
 * debugging.
 *
 * @return A string representation of this object.
 */
-(NSString *)description;


@end
