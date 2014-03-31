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
 * List Subscriptions By Topic Request
 */

@interface SNSListSubscriptionsByTopicRequest:AmazonServiceRequestConfig

{
    NSString *topicArn;
    NSString *nextToken;
}



/**
 * The ARN of the topic for which you wish to find subscriptions.
 */
@property (nonatomic, retain) NSString *topicArn;

/**
 * Token returned by the previous <code>ListSubscriptionsByTopic</code>
 * request.
 */
@property (nonatomic, retain) NSString *nextToken;


/**
 * Default constructor for a new ListSubscriptionsByTopicRequest object.  Callers should use the
 * property methods to initialize this object after creating it.
 */
-(id)init;

/**
 * Constructs a new ListSubscriptionsByTopicRequest object.
 * Callers should use properties to initialize any additional object members.
 *
 * @param theTopicArn The ARN of the topic for which you wish to find
 * subscriptions.
 */
-(id)initWithTopicArn:(NSString *)theTopicArn;

/**
 * Constructs a new ListSubscriptionsByTopicRequest object.
 * Callers should use properties to initialize any additional object members.
 *
 * @param theTopicArn The ARN of the topic for which you wish to find
 * subscriptions.
 * @param theNextToken Token returned by the previous
 * <code>ListSubscriptionsByTopic</code> request.
 */
-(id)initWithTopicArn:(NSString *)theTopicArn andNextToken:(NSString *)theNextToken;

/**
 * Returns a string representation of this object; useful for testing and
 * debugging.
 *
 * @return A string representation of this object.
 */
-(NSString *)description;


@end
