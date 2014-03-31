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

#import "DynamoDBUpdateTableRequestMarshaller.h"
#import "DynamoDBAttributeValue.h"
#import "AmazonJSON.h"
#import "AmazonSDKUtil.h"

@implementation DynamoDBUpdateTableRequestMarshaller

+(AmazonServiceRequest *)createRequest:(DynamoDBUpdateTableRequest *)updateTableRequest
{
    DynamoDBRequest *request = [[DynamoDBRequest alloc] init];

    [request setDelegate:[updateTableRequest delegate]];
    [request setCredentials:[updateTableRequest credentials]];
    [request setEndpoint:[updateTableRequest requestEndpoint]];
    [request setRequestTag:[updateTableRequest requestTag]];


    [request addValue:@"DynamoDB_20120810.UpdateTable" forHeader:@"X-Amz-Target"];
    [request addValue:@"application/x-amz-json-1.0"     forHeader:@"Content-Type"];


    NSMutableDictionary *json = [[[NSMutableDictionary alloc] init] autorelease];

    if (updateTableRequest.tableName != nil) {
        [json setValue:updateTableRequest.tableName forKey:@"TableName"];
    }
    if (updateTableRequest != nil) {
        DynamoDBProvisionedThroughput *provisionedThroughput = updateTableRequest.provisionedThroughput;
        if (provisionedThroughput != nil) {
            NSMutableDictionary *provisionedThroughputJson = [[[NSMutableDictionary alloc] init] autorelease];
            [json setValue:provisionedThroughputJson forKey:@"ProvisionedThroughput"];


            if (provisionedThroughput.readCapacityUnits != nil) {
                [provisionedThroughputJson setValue:provisionedThroughput.readCapacityUnits forKey:@"ReadCapacityUnits"];
            }

            if (provisionedThroughput.writeCapacityUnits != nil) {
                [provisionedThroughputJson setValue:provisionedThroughput.writeCapacityUnits forKey:@"WriteCapacityUnits"];
            }
        }
    }


    if (updateTableRequest.globalSecondaryIndexUpdates != nil) {
        NSArray *globalSecondaryIndexUpdatesList = updateTableRequest.globalSecondaryIndexUpdates;
        if (globalSecondaryIndexUpdatesList != nil && [globalSecondaryIndexUpdatesList count] > 0) {
            NSMutableArray *globalSecondaryIndexUpdatesArray = [[[NSMutableArray alloc] init] autorelease];
            [json setValue:globalSecondaryIndexUpdatesArray forKey:@"GlobalSecondaryIndexUpdates"];
            for (DynamoDBGlobalSecondaryIndexUpdate *globalSecondaryIndexUpdatesListValue in globalSecondaryIndexUpdatesList) {
                NSMutableDictionary *globalSecondaryIndexUpdatesArrayObject = [[[NSMutableDictionary alloc] init] autorelease];
                [globalSecondaryIndexUpdatesArray addObject:globalSecondaryIndexUpdatesArrayObject];
                if (globalSecondaryIndexUpdatesListValue != nil) {
                    DynamoDBUpdateGlobalSecondaryIndexAction *update = globalSecondaryIndexUpdatesListValue.update;
                    if (update != nil) {
                        NSMutableDictionary *updateJson = [[[NSMutableDictionary alloc] init] autorelease];
                        [globalSecondaryIndexUpdatesArrayObject setValue:updateJson forKey:@"Update"];


                        if (update.indexName != nil) {
                            [updateJson setValue:update.indexName forKey:@"IndexName"];
                        }
                        if (update != nil) {
                            DynamoDBProvisionedThroughput *provisionedThroughput = update.provisionedThroughput;
                            if (provisionedThroughput != nil) {
                                NSMutableDictionary *provisionedThroughputJson = [[[NSMutableDictionary alloc] init] autorelease];
                                [updateJson setValue:provisionedThroughputJson forKey:@"ProvisionedThroughput"];


                                if (provisionedThroughput.readCapacityUnits != nil) {
                                    [provisionedThroughputJson setValue:provisionedThroughput.readCapacityUnits forKey:@"ReadCapacityUnits"];
                                }

                                if (provisionedThroughput.writeCapacityUnits != nil) {
                                    [provisionedThroughputJson setValue:provisionedThroughput.writeCapacityUnits forKey:@"WriteCapacityUnits"];
                                }
                            }
                        }
                    }
                }
            }
        }
    }



    request.content = [AmazonJSON JSONRepresentation:json];
    [request addValue:[NSString stringWithFormat:@"%lu", (unsigned long)[[request.content dataUsingEncoding:NSUTF8StringEncoding] length]]    forHeader:@"Content-Length"];

    return [request autorelease];
}

@end

