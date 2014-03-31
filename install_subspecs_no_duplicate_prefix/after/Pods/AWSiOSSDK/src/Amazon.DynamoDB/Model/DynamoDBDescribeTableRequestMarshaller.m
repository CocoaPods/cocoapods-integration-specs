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

#import "DynamoDBDescribeTableRequestMarshaller.h"
#import "DynamoDBAttributeValue.h"
#import "AmazonJSON.h"
#import "AmazonSDKUtil.h"

@implementation DynamoDBDescribeTableRequestMarshaller

+(AmazonServiceRequest *)createRequest:(DynamoDBDescribeTableRequest *)describeTableRequest
{
    DynamoDBRequest *request = [[DynamoDBRequest alloc] init];

    [request setDelegate:[describeTableRequest delegate]];
    [request setCredentials:[describeTableRequest credentials]];
    [request setEndpoint:[describeTableRequest requestEndpoint]];
    [request setRequestTag:[describeTableRequest requestTag]];


    [request addValue:@"DynamoDB_20120810.DescribeTable" forHeader:@"X-Amz-Target"];
    [request addValue:@"application/x-amz-json-1.0"     forHeader:@"Content-Type"];


    NSMutableDictionary *json = [[[NSMutableDictionary alloc] init] autorelease];

    if (describeTableRequest.tableName != nil) {
        [json setValue:describeTableRequest.tableName forKey:@"TableName"];
    }



    request.content = [AmazonJSON JSONRepresentation:json];
    [request addValue:[NSString stringWithFormat:@"%lu", (unsigned long)[[request.content dataUsingEncoding:NSUTF8StringEncoding] length]]    forHeader:@"Content-Length"];

    return [request autorelease];
}

@end

