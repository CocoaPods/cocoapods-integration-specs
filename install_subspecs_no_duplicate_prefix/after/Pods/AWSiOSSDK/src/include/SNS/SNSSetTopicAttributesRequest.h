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
 * Set Topic Attributes Request
 */

@interface SNSSetTopicAttributesRequest:AmazonServiceRequestConfig

{
    NSString *topicArn;
    NSString *attributeName;
    NSString *attributeValue;
}



/**
 * The ARN of the topic to modify.
 */
@property (nonatomic, retain) NSString *topicArn;

/**
 * The name of the attribute you want to set. Only a subset of the
 * topic's attributes are mutable. <p>Valid values: <code>Policy</code> |
 * <code>DisplayName</code> | <code>DeliveryPolicy</code>
 */
@property (nonatomic, retain) NSString *attributeName;

/**
 * The new value for the attribute.
 */
@property (nonatomic, retain) NSString *attributeValue;


/**
 * Default constructor for a new SetTopicAttributesRequest object.  Callers should use the
 * property methods to initialize this object after creating it.
 */
-(id)init;

/**
 * Constructs a new SetTopicAttributesRequest object.
 * Callers should use properties to initialize any additional object members.
 *
 * @param theTopicArn The ARN of the topic to modify.
 * @param theAttributeName The name of the attribute you want to set.
 * Only a subset of the topic's attributes are mutable. <p>Valid values:
 * <code>Policy</code> | <code>DisplayName</code> |
 * <code>DeliveryPolicy</code>
 * @param theAttributeValue The new value for the attribute.
 */
-(id)initWithTopicArn:(NSString *)theTopicArn andAttributeName:(NSString *)theAttributeName andAttributeValue:(NSString *)theAttributeValue;

/**
 * Returns a string representation of this object; useful for testing and
 * debugging.
 *
 * @return A string representation of this object.
 */
-(NSString *)description;


@end
