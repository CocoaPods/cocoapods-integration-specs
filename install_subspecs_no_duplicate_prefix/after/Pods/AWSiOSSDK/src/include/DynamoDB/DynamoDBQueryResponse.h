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
#import "DynamoDBConsumedCapacity.h"

#import "DynamoDBResponse.h"

#import "DynamoDBResourceNotFoundException.h"
#import "DynamoDBProvisionedThroughputExceededException.h"
#import "DynamoDBInternalServerErrorException.h"


/**
 * Query Result
 */

@interface DynamoDBQueryResponse:DynamoDBResponse

{
    NSMutableArray           *items;
    NSNumber                 *count;
    NSMutableDictionary      *lastEvaluatedKey;
    DynamoDBConsumedCapacity *consumedCapacity;
}



-(void)setException:(AmazonServiceException *)theException;


/**
 * Default constructor for a new  object.  Callers should use the
 * property methods to initialize this object after creating it.
 */
-(id)init;

/**
 * An array of item attributes that match the query criteria. Each
 * element in this array consists of an attribute name and the value for
 * that attribute.
 */
@property (nonatomic, retain) NSMutableArray *items;

/**
 * The number of items in the response.
 */
@property (nonatomic, retain) NSNumber *count;

/**
 * The primary key of the item where the operation stopped, inclusive of
 * the previous result set. Use this value to start a new operation,
 * excluding this value in the new request. <p>If <i>LastEvaluatedKey</i>
 * is null, then the "last page" of results has been processed and there
 * is no more data to be retrieved. <p>If <i>LastEvaluatedKey</i> is
 * anything other than null, this does not necessarily mean that there is
 * more data in the result set. The only way to know when you have
 * reached the end of the result set is when <i>LastEvaluatedKey</i> is
 * null.
 */
@property (nonatomic, retain) NSMutableDictionary *lastEvaluatedKey;

/**
 * Represents the capacity units consumed by an operation. The data
 * returned includes the total provisioned throughput consumed, along
 * with statistics for the table and any indexes involved in the
 * operation. <i>ConsumedCapacity</i> is only returned if it was asked
 * for in the request. For more information, see <a
 * odb/latest/developerguide/ProvisionedThroughputIntro.html">Provisioned
 * Throughput</a> in the Amazon DynamoDB Developer Guide.
 */
@property (nonatomic, retain) DynamoDBConsumedCapacity *consumedCapacity;



/**
 * Returns a value from the items array for the specified index
 */
-(NSDictionary *)itemsObjectAtIndex:(int)index;

/**
 * Returns a value from the lastEvaluatedKey dictionary for the specified key.
 */
-(DynamoDBAttributeValue *)lastEvaluatedKeyValueForKey:(NSString *)theKey;

/**
 * Returns a string representation of this object; useful for testing and
 * debugging.
 *
 * @return A string representation of this object.
 */
-(NSString *)description;


@end
