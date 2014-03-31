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
 * Get Item Request
 */

@interface DynamoDBGetItemRequest:AmazonServiceRequestConfig

{
    NSString            *tableName;
    NSMutableDictionary *key;
    NSMutableArray      *attributesToGet;
    BOOL                consistentRead;
    BOOL                consistentReadIsSet;
    NSString            *returnConsumedCapacity;
}



/**
 * The name of the table containing the requested item.
 * <p>
 * <b>Constraints:</b><br/>
 * <b>Length: </b>3 - 255<br/>
 * <b>Pattern: </b>[a-zA-Z0-9_.-]+<br/>
 */
@property (nonatomic, retain) NSString *tableName;

/**
 * A map of attribute names to <i>AttributeValue</i> objects,
 * representing the primary key of the item to retrieve.
 */
@property (nonatomic, retain) NSMutableDictionary *key;

/**
 * The names of one or more attributes to retrieve. If no attribute names
 * are specified, then all attributes will be returned. If any of the
 * requested attributes are not found, they will not appear in the
 * result.
 * <p>
 * <b>Constraints:</b><br/>
 * <b>Length: </b>1 - <br/>
 */
@property (nonatomic, retain) NSMutableArray *attributesToGet;

/**
 * If set to <code>true</code>, then the operation uses strongly
 * consistent reads; otherwise, eventually consistent reads are used.
 */
@property (nonatomic) BOOL           consistentRead;

@property (nonatomic, readonly) BOOL consistentReadIsSet;

/**
 * If set to <code>TOTAL</code>, the response includes
 * <i>ConsumedCapacity</i> data for tables and indexes. If set to
 * <code>INDEXES</code>, the repsonse includes <i>ConsumedCapacity</i>
 * for indexes. If set to <code>NONE</code> (the default),
 * <i>ConsumedCapacity</i> is not included in the response.
 * <p>
 * <b>Constraints:</b><br/>
 * <b>Allowed Values: </b>INDEXES, TOTAL, NONE
 */
@property (nonatomic, retain) NSString *returnConsumedCapacity;


/**
 * Default constructor for a new GetItemRequest object.  Callers should use the
 * property methods to initialize this object after creating it.
 */
-(id)init;

/**
 * Constructs a new GetItemRequest object.
 * Callers should use properties to initialize any additional object members.
 *
 * @param theTableName The name of the table containing the requested
 * item.
 * @param theKey A map of attribute names to <i>AttributeValue</i>
 * objects, representing the primary key of the item to retrieve.
 */
-(id)initWithTableName:(NSString *)theTableName andKey:(NSMutableDictionary *)theKey;


/**
 * Set a value in the dictionary key for the specified key.
 * This function will alloc and init key if not already done.
 */
-(void)setKeyValue:(DynamoDBAttributeValue *)theValue forKey:(NSString *)theKey;

/**
 * Adds a single object to attributesToGet.
 * This function will alloc and init attributesToGet if not already done.
 */
-(void)addAttributesToGet:(NSString *)attributesToGetObject;

/**
 * Returns a string representation of this object; useful for testing and
 * debugging.
 *
 * @return A string representation of this object.
 */
-(NSString *)description;


@end
