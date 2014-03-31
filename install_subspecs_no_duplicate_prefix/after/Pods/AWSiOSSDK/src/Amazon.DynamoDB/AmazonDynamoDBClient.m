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

#import "AmazonDynamoDBClient.h"
#import "AmazonEndpoints.h"
#import "AmazonServiceRequest.h"
#import "DynamoDBScanResponseUnmarshaller.h"
#import "DynamoDBScanRequestMarshaller.h"
#import "DynamoDBUpdateTableResponseUnmarshaller.h"
#import "DynamoDBUpdateTableRequestMarshaller.h"
#import "DynamoDBDeleteTableResponseUnmarshaller.h"
#import "DynamoDBDeleteTableRequestMarshaller.h"
#import "DynamoDBBatchWriteItemResponseUnmarshaller.h"
#import "DynamoDBBatchWriteItemRequestMarshaller.h"
#import "DynamoDBDescribeTableResponseUnmarshaller.h"
#import "DynamoDBDescribeTableRequestMarshaller.h"
#import "DynamoDBGetItemResponseUnmarshaller.h"
#import "DynamoDBGetItemRequestMarshaller.h"
#import "DynamoDBDeleteItemResponseUnmarshaller.h"
#import "DynamoDBDeleteItemRequestMarshaller.h"
#import "DynamoDBCreateTableResponseUnmarshaller.h"
#import "DynamoDBCreateTableRequestMarshaller.h"
#import "DynamoDBQueryResponseUnmarshaller.h"
#import "DynamoDBQueryRequestMarshaller.h"
#import "DynamoDBPutItemResponseUnmarshaller.h"
#import "DynamoDBPutItemRequestMarshaller.h"
#import "DynamoDBListTablesResponseUnmarshaller.h"
#import "DynamoDBListTablesRequestMarshaller.h"
#import "DynamoDBUpdateItemResponseUnmarshaller.h"
#import "DynamoDBUpdateItemRequestMarshaller.h"
#import "DynamoDBBatchGetItemResponseUnmarshaller.h"
#import "DynamoDBBatchGetItemRequestMarshaller.h"



@implementation AmazonDynamoDBClient

-(id)initWithCredentials:(AmazonCredentials *)theCredentials
{
    if (self = [super initWithCredentials:theCredentials]) {
        self.endpoint = AMAZON_DDB_US_EAST_1_ENDPOINT_SECURE;
    }
    return self;
}

-(id)initWithCredentialsProvider:(id<AmazonCredentialsProvider> )theProvider
{
    if (self = [super initWithCredentialsProvider:theProvider]) {
        self.endpoint = AMAZON_DDB_US_EAST_1_ENDPOINT_SECURE;
    }
    return self;
}

-(DynamoDBScanResponse *)scan:(DynamoDBScanRequest *)scanRequest
{
    AmazonServiceRequest *request = [DynamoDBScanRequestMarshaller createRequest:scanRequest];

    return (DynamoDBScanResponse *)[self invoke:request rawRequest:scanRequest unmarshallerDelegate:[DynamoDBScanResponseUnmarshaller class]];
}

-(DynamoDBUpdateTableResponse *)updateTable:(DynamoDBUpdateTableRequest *)updateTableRequest
{
    AmazonServiceRequest *request = [DynamoDBUpdateTableRequestMarshaller createRequest:updateTableRequest];

    return (DynamoDBUpdateTableResponse *)[self invoke:request rawRequest:updateTableRequest unmarshallerDelegate:[DynamoDBUpdateTableResponseUnmarshaller class]];
}

-(DynamoDBDeleteTableResponse *)deleteTable:(DynamoDBDeleteTableRequest *)deleteTableRequest
{
    AmazonServiceRequest *request = [DynamoDBDeleteTableRequestMarshaller createRequest:deleteTableRequest];

    return (DynamoDBDeleteTableResponse *)[self invoke:request rawRequest:deleteTableRequest unmarshallerDelegate:[DynamoDBDeleteTableResponseUnmarshaller class]];
}

-(DynamoDBBatchWriteItemResponse *)batchWriteItem:(DynamoDBBatchWriteItemRequest *)batchWriteItemRequest
{
    AmazonServiceRequest *request = [DynamoDBBatchWriteItemRequestMarshaller createRequest:batchWriteItemRequest];

    return (DynamoDBBatchWriteItemResponse *)[self invoke:request rawRequest:batchWriteItemRequest unmarshallerDelegate:[DynamoDBBatchWriteItemResponseUnmarshaller class]];
}

-(DynamoDBDescribeTableResponse *)describeTable:(DynamoDBDescribeTableRequest *)describeTableRequest
{
    AmazonServiceRequest *request = [DynamoDBDescribeTableRequestMarshaller createRequest:describeTableRequest];

    return (DynamoDBDescribeTableResponse *)[self invoke:request rawRequest:describeTableRequest unmarshallerDelegate:[DynamoDBDescribeTableResponseUnmarshaller class]];
}

-(DynamoDBGetItemResponse *)getItem:(DynamoDBGetItemRequest *)getItemRequest
{
    AmazonServiceRequest *request = [DynamoDBGetItemRequestMarshaller createRequest:getItemRequest];

    return (DynamoDBGetItemResponse *)[self invoke:request rawRequest:getItemRequest unmarshallerDelegate:[DynamoDBGetItemResponseUnmarshaller class]];
}

-(DynamoDBDeleteItemResponse *)deleteItem:(DynamoDBDeleteItemRequest *)deleteItemRequest
{
    AmazonServiceRequest *request = [DynamoDBDeleteItemRequestMarshaller createRequest:deleteItemRequest];

    return (DynamoDBDeleteItemResponse *)[self invoke:request rawRequest:deleteItemRequest unmarshallerDelegate:[DynamoDBDeleteItemResponseUnmarshaller class]];
}

-(DynamoDBCreateTableResponse *)createTable:(DynamoDBCreateTableRequest *)createTableRequest
{
    AmazonServiceRequest *request = [DynamoDBCreateTableRequestMarshaller createRequest:createTableRequest];

    return (DynamoDBCreateTableResponse *)[self invoke:request rawRequest:createTableRequest unmarshallerDelegate:[DynamoDBCreateTableResponseUnmarshaller class]];
}

-(DynamoDBQueryResponse *)query:(DynamoDBQueryRequest *)queryRequest
{
    AmazonServiceRequest *request = [DynamoDBQueryRequestMarshaller createRequest:queryRequest];

    return (DynamoDBQueryResponse *)[self invoke:request rawRequest:queryRequest unmarshallerDelegate:[DynamoDBQueryResponseUnmarshaller class]];
}

-(DynamoDBPutItemResponse *)putItem:(DynamoDBPutItemRequest *)putItemRequest
{
    AmazonServiceRequest *request = [DynamoDBPutItemRequestMarshaller createRequest:putItemRequest];

    return (DynamoDBPutItemResponse *)[self invoke:request rawRequest:putItemRequest unmarshallerDelegate:[DynamoDBPutItemResponseUnmarshaller class]];
}

-(DynamoDBListTablesResponse *)listTables:(DynamoDBListTablesRequest *)listTablesRequest
{
    AmazonServiceRequest *request = [DynamoDBListTablesRequestMarshaller createRequest:listTablesRequest];

    return (DynamoDBListTablesResponse *)[self invoke:request rawRequest:listTablesRequest unmarshallerDelegate:[DynamoDBListTablesResponseUnmarshaller class]];
}

-(DynamoDBUpdateItemResponse *)updateItem:(DynamoDBUpdateItemRequest *)updateItemRequest
{
    AmazonServiceRequest *request = [DynamoDBUpdateItemRequestMarshaller createRequest:updateItemRequest];

    return (DynamoDBUpdateItemResponse *)[self invoke:request rawRequest:updateItemRequest unmarshallerDelegate:[DynamoDBUpdateItemResponseUnmarshaller class]];
}

-(DynamoDBBatchGetItemResponse *)batchGetItem:(DynamoDBBatchGetItemRequest *)batchGetItemRequest
{
    AmazonServiceRequest *request = [DynamoDBBatchGetItemRequestMarshaller createRequest:batchGetItemRequest];

    return (DynamoDBBatchGetItemResponse *)[self invoke:request rawRequest:batchGetItemRequest unmarshallerDelegate:[DynamoDBBatchGetItemResponseUnmarshaller class]];
}



@end

