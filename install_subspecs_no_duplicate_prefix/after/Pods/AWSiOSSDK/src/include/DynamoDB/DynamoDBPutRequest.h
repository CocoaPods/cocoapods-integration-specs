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

#import "DynamoDBAttributeValue.h"

#ifdef AWS_MULTI_FRAMEWORK
#import <AWSRuntime/AmazonServiceRequestConfig.h>
#else
#import "../AmazonServiceRequestConfig.h"
#endif



/**
 * Put Request
 */

@interface DynamoDBPutRequest:AmazonServiceRequestConfig

{
    NSMutableDictionary *item;
}




/**
 * Default constructor for a new  object.  Callers should use the
 * property methods to initialize this object after creating it.
 */
-(id)init;

/**
 * A map of attribute name to attribute values, representing the primary
 * key of an item to be processed by <i>PutItem</i>. All of the table's
 * primary key attributes must be specified, and their data types must
 * match those of the table's key schema. If any attributes are present
 * in the item which are part of an index key schema for the table, their
 * types must match the index key schema.
 */
@property (nonatomic, retain) NSMutableDictionary *item;


/**
 * Set a value in the dictionary item for the specified key.
 * This function will alloc and init item if not already done.
 */
-(void)setItemValue:(DynamoDBAttributeValue *)theValue forKey:(NSString *)theKey;

/**
 * Returns a string representation of this object; useful for testing and
 * debugging.
 *
 * @return A string representation of this object.
 */
-(NSString *)description;


@end
