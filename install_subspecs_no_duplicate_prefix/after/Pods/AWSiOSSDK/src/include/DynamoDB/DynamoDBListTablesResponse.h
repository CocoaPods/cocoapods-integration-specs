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


#import "DynamoDBResponse.h"

#import "DynamoDBInternalServerErrorException.h"


/**
 * List Tables Result
 */

@interface DynamoDBListTablesResponse:DynamoDBResponse

{
    NSMutableArray *tableNames;
    NSString       *lastEvaluatedTableName;
}



-(void)setException:(AmazonServiceException *)theException;


/**
 * Default constructor for a new  object.  Callers should use the
 * property methods to initialize this object after creating it.
 */
-(id)init;

/**
 * The names of the tables associated with the current account at the
 * current endpoint.
 */
@property (nonatomic, retain) NSMutableArray *tableNames;

/**
 * The name of the last table in the current list, only if some tables
 * for the account and endpoint have not been returned. This value does
 * not exist in a response if all table names are already returned. Use
 * this value as the <i>ExclusiveStartTableName</i> in a new request to
 * continue the list until all the table names are returned.
 * <p>
 * <b>Constraints:</b><br/>
 * <b>Length: </b>3 - 255<br/>
 * <b>Pattern: </b>[a-zA-Z0-9_.-]+<br/>
 */
@property (nonatomic, retain) NSString *lastEvaluatedTableName;



/**
 * Returns a value from the tableNames array for the specified index
 */
-(NSString *)tableNamesObjectAtIndex:(int)index;

/**
 * Returns a string representation of this object; useful for testing and
 * debugging.
 *
 * @return A string representation of this object.
 */
-(NSString *)description;


@end
