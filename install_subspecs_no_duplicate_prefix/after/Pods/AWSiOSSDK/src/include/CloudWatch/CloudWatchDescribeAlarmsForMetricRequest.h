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

#import "CloudWatchDimension.h"

#ifdef AWS_MULTI_FRAMEWORK
#import <AWSRuntime/AmazonServiceRequestConfig.h>
#else
#import "../AmazonServiceRequestConfig.h"
#endif



/**
 * Describe Alarms For Metric Request
 */

@interface CloudWatchDescribeAlarmsForMetricRequest:AmazonServiceRequestConfig

{
    NSString       *metricName;
    NSString       *namespace;
    NSString       *statistic;
    NSMutableArray *dimensions;
    NSNumber       *period;
    NSString       *unit;
}




/**
 * Default constructor for a new  object.  Callers should use the
 * property methods to initialize this object after creating it.
 */
-(id)init;

/**
 * The name of the metric.
 * <p>
 * <b>Constraints:</b><br/>
 * <b>Length: </b>1 - 255<br/>
 */
@property (nonatomic, retain) NSString *metricName;

/**
 * The namespace of the metric.
 * <p>
 * <b>Constraints:</b><br/>
 * <b>Length: </b>1 - 255<br/>
 * <b>Pattern: </b>[^:].*<br/>
 */
@property (nonatomic, retain) NSString *namespace;

/**
 * The statistic for the metric.
 * <p>
 * <b>Constraints:</b><br/>
 * <b>Allowed Values: </b>SampleCount, Average, Sum, Minimum, Maximum
 */
@property (nonatomic, retain) NSString *statistic;

/**
 * The list of dimensions associated with the metric.
 * <p>
 * <b>Constraints:</b><br/>
 * <b>Length: </b>0 - 10<br/>
 */
@property (nonatomic, retain) NSMutableArray *dimensions;

/**
 * The period in seconds over which the statistic is applied.
 * <p>
 * <b>Constraints:</b><br/>
 * <b>Range: </b>60 - <br/>
 */
@property (nonatomic, retain) NSNumber *period;

/**
 * The unit for the metric.
 * <p>
 * <b>Constraints:</b><br/>
 * <b>Allowed Values: </b>Seconds, Microseconds, Milliseconds, Bytes, Kilobytes, Megabytes, Gigabytes, Terabytes, Bits, Kilobits, Megabits, Gigabits, Terabits, Percent, Count, Bytes/Second, Kilobytes/Second, Megabytes/Second, Gigabytes/Second, Terabytes/Second, Bits/Second, Kilobits/Second, Megabits/Second, Gigabits/Second, Terabits/Second, Count/Second, None
 */
@property (nonatomic, retain) NSString *unit;

/**
 * Adds a single object to dimensions.
 * This function will alloc and init dimensions if not already done.
 */
-(void)addDimension:(CloudWatchDimension *)dimensionObject;

/**
 * Returns a string representation of this object; useful for testing and
 * debugging.
 *
 * @return A string representation of this object.
 */
-(NSString *)description;


@end
