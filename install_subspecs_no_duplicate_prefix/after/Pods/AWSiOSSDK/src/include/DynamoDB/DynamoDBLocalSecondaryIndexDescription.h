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

#import "DynamoDBKeySchemaElement.h"
#import "DynamoDBProjection.h"



/**
 * Local Secondary Index Description
 */

@interface DynamoDBLocalSecondaryIndexDescription:NSObject

{
    NSString           *indexName;
    NSMutableArray     *keySchema;
    DynamoDBProjection *projection;
    NSNumber           *indexSizeBytes;
    NSNumber           *itemCount;
}




/**
 * Default constructor for a new  object.  Callers should use the
 * property methods to initialize this object after creating it.
 */
-(id)init;

/**
 * Represents the name of the local secondary index.
 * <p>
 * <b>Constraints:</b><br/>
 * <b>Length: </b>3 - 255<br/>
 * <b>Pattern: </b>[a-zA-Z0-9_.-]+<br/>
 */
@property (nonatomic, retain) NSString *indexName;

/**
 * The complete index key schema, which consists of one or more pairs of
 * attribute names and key types (<code>HASH</code> or
 * <code>RANGE</code>).
 * <p>
 * <b>Constraints:</b><br/>
 * <b>Length: </b>1 - 2<br/>
 */
@property (nonatomic, retain) NSMutableArray *keySchema;

/**
 * Represents attributes that are copied (projected) from the table into
 * an index. These are in addition to the primary key attributes and
 * index key attributes, which are automatically projected.
 */
@property (nonatomic, retain) DynamoDBProjection *projection;

/**
 * The total size of the specified index, in bytes. Amazon DynamoDB
 * updates this value approximately every six hours. Recent changes might
 * not be reflected in this value.
 */
@property (nonatomic, retain) NSNumber *indexSizeBytes;

/**
 * The number of items in the specified index. Amazon DynamoDB updates
 * this value approximately every six hours. Recent changes might not be
 * reflected in this value.
 */
@property (nonatomic, retain) NSNumber *itemCount;

/**
 * Adds a single object to keySchema.
 * This function will alloc and init keySchema if not already done.
 */
-(void)addKeySchema:(DynamoDBKeySchemaElement *)keySchemaObject;

/**
 * Returns a string representation of this object; useful for testing and
 * debugging.
 *
 * @return A string representation of this object.
 */
-(NSString *)description;


@end
