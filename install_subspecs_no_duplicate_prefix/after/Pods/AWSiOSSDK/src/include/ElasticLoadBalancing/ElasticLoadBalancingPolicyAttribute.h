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
 * Policy Attribute
 */

@interface ElasticLoadBalancingPolicyAttribute:NSObject

{
    NSString *attributeName;
    NSString *attributeValue;
}



/**
 * The name of the attribute associated with the policy.
 */
@property (nonatomic, retain) NSString *attributeName;

/**
 * The value of the attribute associated with the policy.
 */
@property (nonatomic, retain) NSString *attributeValue;


/**
 * Default constructor for a new PolicyAttribute object.  Callers should use the
 * property methods to initialize this object after creating it.
 */
-(id)init;

/**
 * Constructs a new PolicyAttribute object.
 * Callers should use properties to initialize any additional object members.
 *
 * @param theAttributeName The name of the attribute associated with the
 * policy.
 * @param theAttributeValue The value of the attribute associated with
 * the policy.
 */
-(id)initWithAttributeName:(NSString *)theAttributeName andAttributeValue:(NSString *)theAttributeValue;

/**
 * Returns a string representation of this object; useful for testing and
 * debugging.
 *
 * @return A string representation of this object.
 */
-(NSString *)description;


@end
