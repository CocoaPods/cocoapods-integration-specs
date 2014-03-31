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
#import "DynamoDBItemCollectionMetrics.h"

#import "DynamoDBResponse.h"

#import "DynamoDBItemCollectionSizeLimitExceededException.h"
#import "DynamoDBResourceNotFoundException.h"
#import "DynamoDBConditionalCheckFailedException.h"
#import "DynamoDBProvisionedThroughputExceededException.h"
#import "DynamoDBInternalServerErrorException.h"


/**
 * Put Item Result
 */

@interface DynamoDBPutItemResponse:DynamoDBResponse

{
    NSMutableDictionary           *attributes;
    DynamoDBConsumedCapacity      *consumedCapacity;
    DynamoDBItemCollectionMetrics *itemCollectionMetrics;
}



-(void)setException:(AmazonServiceException *)theException;


/**
 * Default constructor for a new  object.  Callers should use the
 * property methods to initialize this object after creating it.
 */
-(id)init;

/**
 * The attribute values as they appeared before the <i>PutItem</i>
 * operation, but only if <i>ReturnValues</i> is specified as
 * <code>ALL_OLD</code> in the request. Each element consists of an
 * attribute name and an attribute value.
 */
@property (nonatomic, retain) NSMutableDictionary *attributes;

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
 * Information about item collections, if any, that were affected by the
 * operation. <i>ItemCollectionMetrics</i> is only returned if it was
 * asked for in the request. If the table does not have any local
 * secondary indexes, this information is not returned in the response.
 * <p>Each <i>ItemCollectionMetrics</i> element consists of: <ul>
 * <li><p><i>ItemCollectionKey</i> - The hash key value of the item
 * collection. This is the same as the hash key of the item.</li>
 * <li><p><i>SizeEstimateRange</i> - An estimate of item collection size,
 * measured in gigabytes. This is a two-element array containing a lower
 * bound and an upper bound for the estimate. The estimate includes the
 * size of all the items in the table, plus the size of all attributes
 * projected into all of the local secondary indexes on that table. Use
 * this estimate to measure whether a local secondary index is
 * approaching its size limit. <p>The estimate is subject to change over
 * time; therefore, do not rely on the precision or accuracy of the
 * estimate. </li> </ul>
 */
@property (nonatomic, retain) DynamoDBItemCollectionMetrics *itemCollectionMetrics;

/**
 * Returns a value from the attributes dictionary for the specified key.
 */
-(DynamoDBAttributeValue *)attributesValueForKey:(NSString *)theKey;

/**
 * Returns a string representation of this object; useful for testing and
 * debugging.
 *
 * @return A string representation of this object.
 */
-(NSString *)description;


@end
