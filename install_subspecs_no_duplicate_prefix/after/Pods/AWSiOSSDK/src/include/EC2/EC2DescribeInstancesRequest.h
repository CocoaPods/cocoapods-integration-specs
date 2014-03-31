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

#import "EC2Filter.h"

#ifdef AWS_MULTI_FRAMEWORK
#import <AWSRuntime/AmazonServiceRequestConfig.h>
#else
#import "../AmazonServiceRequestConfig.h"
#endif



/**
 * Describe Instances Request
 */

@interface EC2DescribeInstancesRequest:AmazonServiceRequestConfig

{
    BOOL           dryRun;
    BOOL           dryRunIsSet;
    NSMutableArray *instanceIds;
    NSMutableArray *filters;
    NSString       *nextToken;
    NSNumber       *maxResults;
}




/**
 * Default constructor for a new  object.  Callers should use the
 * property methods to initialize this object after creating it.
 */
-(id)init;

/**
 * The value of the DryRun property for this object.
 */
@property (nonatomic) BOOL           dryRun;

@property (nonatomic, readonly) BOOL dryRunIsSet;

/**
 * An optional list of the instances to describe.
 */
@property (nonatomic, retain) NSMutableArray *instanceIds;

/**
 * A list of filters used to match properties for Instances. For a
 * complete reference to the available filter keys for this operation,
 * see the <a
 * Reference/index.html?ApiReference-query-DescribeInstances.html">Amazon
 * EC2 API reference</a>.
 */
@property (nonatomic, retain) NSMutableArray *filters;

/**
 * The value of the NextToken property for this object.
 */
@property (nonatomic, retain) NSString *nextToken;

/**
 * The value of the MaxResults property for this object.
 */
@property (nonatomic, retain) NSNumber *maxResults;

/**
 * Adds a single object to instanceIds.
 * This function will alloc and init instanceIds if not already done.
 */
-(void)addInstanceId:(NSString *)instanceIdObject;

/**
 * Adds a single object to filters.
 * This function will alloc and init filters if not already done.
 */
-(void)addFilter:(EC2Filter *)filterObject;

/**
 * Returns a string representation of this object; useful for testing and
 * debugging.
 *
 * @return A string representation of this object.
 */
-(NSString *)description;


@end
