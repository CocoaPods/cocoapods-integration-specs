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
 * Put Scaling Policy Request
 */

@interface AutoScalingPutScalingPolicyRequest:AmazonServiceRequestConfig

{
    NSString *autoScalingGroupName;
    NSString *policyName;
    NSNumber *scalingAdjustment;
    NSString *adjustmentType;
    NSNumber *cooldown;
    NSNumber *minAdjustmentStep;
}




/**
 * Default constructor for a new  object.  Callers should use the
 * property methods to initialize this object after creating it.
 */
-(id)init;

/**
 * The name or ARN of the Auto Scaling group.
 * <p>
 * <b>Constraints:</b><br/>
 * <b>Length: </b>1 - 1600<br/>
 * <b>Pattern: </b>[\u0020-\uD7FF\uE000-\uFFFD\uD800\uDC00-\uDBFF\uDFFF\r\n\t]*<br/>
 */
@property (nonatomic, retain) NSString *autoScalingGroupName;

/**
 * The name of the policy you want to create or update.
 * <p>
 * <b>Constraints:</b><br/>
 * <b>Length: </b>1 - 255<br/>
 * <b>Pattern: </b>[\u0020-\uD7FF\uE000-\uFFFD\uD800\uDC00-\uDBFF\uDFFF\r\n\t]*<br/>
 */
@property (nonatomic, retain) NSString *policyName;

/**
 * The number of instances by which to scale. <code>AdjustmentType</code>
 * determines the interpretation of this number (e.g., as an absolute
 * number or as a percentage of the existing Auto Scaling group size). A
 * positive increment adds to the current capacity and a negative value
 * removes from the current capacity.
 */
@property (nonatomic, retain) NSNumber *scalingAdjustment;

/**
 * Specifies whether the <code>ScalingAdjustment</code> is an absolute
 * number or a percentage of the current capacity. Valid values are
 * <code>ChangeInCapacity</code>, <code>ExactCapacity</code>, and
 * <code>PercentChangeInCapacity</code>. <p>For more information about
 * the adjustment types supported by Auto Scaling, see <a
 * AutoScaling/latest/DeveloperGuide/as-scale-based-on-demand.html">Scale
 * Based on Demand</a>.
 * <p>
 * <b>Constraints:</b><br/>
 * <b>Length: </b>1 - 255<br/>
 * <b>Pattern: </b>[\u0020-\uD7FF\uE000-\uFFFD\uD800\uDC00-\uDBFF\uDFFF\r\n\t]*<br/>
 */
@property (nonatomic, retain) NSString *adjustmentType;

/**
 * The amount of time, in seconds, after a scaling activity completes and
 * before the next scaling activity can start. <p>For more information,
 * see <a
 * /AutoScaling/latest/DeveloperGuide/AS_Concepts.html#Cooldown">Cooldown
 * Period</a>
 */
@property (nonatomic, retain) NSNumber *cooldown;

/**
 * Used with <code>AdjustmentType</code> with the value
 * <code>PercentChangeInCapacity</code>, the scaling policy changes the
 * <code>DesiredCapacity</code> of the Auto Scaling group by at least the
 * number of instances specified in the value. <p> You will get a
 * <code>ValidationError</code> if you use <code>MinAdjustmentStep</code>
 * on a policy with an <code>AdjustmentType</code> other than
 * <code>PercentChangeInCapacity</code>.
 */
@property (nonatomic, retain) NSNumber *minAdjustmentStep;

/**
 * Returns a string representation of this object; useful for testing and
 * debugging.
 *
 * @return A string representation of this object.
 */
-(NSString *)description;


@end
