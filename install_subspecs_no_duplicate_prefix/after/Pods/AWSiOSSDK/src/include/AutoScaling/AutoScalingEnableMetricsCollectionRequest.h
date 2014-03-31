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
 * Enable Metrics Collection Request
 */

@interface AutoScalingEnableMetricsCollectionRequest:AmazonServiceRequestConfig

{
    NSString       *autoScalingGroupName;
    NSMutableArray *metrics;
    NSString       *granularity;
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
 * The list of metrics to collect. If no metrics are specified, all
 * metrics are enabled. The following metrics are supported: <ul>
 * <li><p>GroupMinSize</li> <li><p>GroupMaxSize</li>
 * <li><p>GroupDesiredCapacity</li> <li><p>GroupInServiceInstances</li>
 * <li><p>GroupPendingInstances</li>
 * <li><p>GroupTerminatingInstances</li> <li><p>GroupTotalInstances</li>
 * </ul>
 */
@property (nonatomic, retain) NSMutableArray *metrics;

/**
 * The granularity to associate with the metrics to collect. Currently,
 * the only legal granularity is "1Minute".
 * <p>
 * <b>Constraints:</b><br/>
 * <b>Length: </b>1 - 255<br/>
 * <b>Pattern: </b>[\u0020-\uD7FF\uE000-\uFFFD\uD800\uDC00-\uDBFF\uDFFF\r\n\t]*<br/>
 */
@property (nonatomic, retain) NSString *granularity;

/**
 * Adds a single object to metrics.
 * This function will alloc and init metrics if not already done.
 */
-(void)addMetric:(NSString *)metricObject;

/**
 * Returns a string representation of this object; useful for testing and
 * debugging.
 *
 * @return A string representation of this object.
 */
-(NSString *)description;


@end
