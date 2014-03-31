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

#import "DynamoDBBatchWriteItemResponse.h"


@implementation DynamoDBBatchWriteItemResponse

@synthesize unprocessedItems;
@synthesize itemCollectionMetrics;
@synthesize consumedCapacity;


-(id)init
{
    if (self = [super init]) {
        unprocessedItems      = [[NSMutableDictionary alloc] initWithCapacity:1];
        itemCollectionMetrics = [[NSMutableDictionary alloc] initWithCapacity:1];
        consumedCapacity      = [[NSMutableArray alloc] initWithCapacity:1];
    }

    return self;
}


-(void)setException:(AmazonServiceException *)theException
{
    AmazonServiceException *newException = nil;

    if ([[theException errorCode] isEqualToString:@"ItemCollectionSizeLimitExceededException"]) {
        [newException release];
        newException = [[DynamoDBItemCollectionSizeLimitExceededException alloc] initWithMessage:@""];
    }

    if ([[theException errorCode] isEqualToString:@"ResourceNotFoundException"]) {
        [newException release];
        newException = [[DynamoDBResourceNotFoundException alloc] initWithMessage:@""];
    }

    if ([[theException errorCode] isEqualToString:@"ProvisionedThroughputExceededException"]) {
        [newException release];
        newException = [[DynamoDBProvisionedThroughputExceededException alloc] initWithMessage:@""];
    }

    if ([[theException errorCode] isEqualToString:@"InternalServerError"]) {
        [newException release];
        newException = [[DynamoDBInternalServerErrorException alloc] initWithMessage:@""];
    }

    if (newException != nil) {
        [newException setPropertiesWithException:theException];
        [exception release];
        exception = newException;
    }
    else {
        [exception release];
        exception = [theException retain];
    }
}


-(NSArray *)unprocessedItemsValueForKey:(NSString *)theKey
{
    return (NSArray *)[unprocessedItems valueForKey:theKey];
}

-(NSArray *)itemCollectionMetricsValueForKey:(NSString *)theKey
{
    return (NSArray *)[itemCollectionMetrics valueForKey:theKey];
}


-(DynamoDBConsumedCapacity *)consumedCapacityObjectAtIndex:(int)index
{
    return (DynamoDBConsumedCapacity *)[consumedCapacity objectAtIndex:index];
}


-(NSString *)description
{
    NSMutableString *buffer = [[NSMutableString alloc] initWithCapacity:256];

    [buffer appendString:@"{"];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"UnprocessedItems: %@,", unprocessedItems] autorelease]];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"ItemCollectionMetrics: %@,", itemCollectionMetrics] autorelease]];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"ConsumedCapacity: %@,", consumedCapacity] autorelease]];
    [buffer appendString:[super description]];
    [buffer appendString:@"}"];

    return [buffer autorelease];
}



-(void)dealloc
{
    [unprocessedItems release];
    [itemCollectionMetrics release];
    [consumedCapacity release];

    [super dealloc];
}


@end
