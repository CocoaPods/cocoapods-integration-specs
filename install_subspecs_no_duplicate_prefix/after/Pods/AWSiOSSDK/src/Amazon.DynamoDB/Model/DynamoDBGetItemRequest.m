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

#import "DynamoDBGetItemRequest.h"


@implementation DynamoDBGetItemRequest

@synthesize tableName;
@synthesize key;
@synthesize attributesToGet;
@synthesize consistentRead;
@synthesize consistentReadIsSet;
@synthesize returnConsumedCapacity;


-(id)init
{
    if (self = [super init]) {
        tableName              = nil;
        key                    = [[NSMutableDictionary alloc] initWithCapacity:1];
        attributesToGet        = [[NSMutableArray alloc] initWithCapacity:1];
        consistentRead         = NO;
        consistentReadIsSet    = NO;
        returnConsumedCapacity = nil;
    }

    return self;
}

-(id)initWithTableName:(NSString *)theTableName andKey:(NSMutableDictionary *)theKey
{
    if (self = [self init]) {
        self.tableName = theTableName;
        self.key       = theKey;
    }

    return self;
}


-(void)setKeyValue:(DynamoDBAttributeValue *)theValue forKey:(NSString *)theKey
{
    if (key == nil) {
        key = [[NSMutableDictionary alloc] initWithCapacity:1];
    }

    [key setValue:theValue forKey:theKey];
}

-(void)addAttributesToGet:(NSString *)attributesToGetObject
{
    if (attributesToGet == nil) {
        attributesToGet = [[NSMutableArray alloc] initWithCapacity:1];
    }

    [attributesToGet addObject:attributesToGetObject];
}


-(NSString *)description
{
    NSMutableString *buffer = [[NSMutableString alloc] initWithCapacity:256];

    [buffer appendString:@"{"];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"TableName: %@,", tableName] autorelease]];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"Key: %@,", key] autorelease]];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"AttributesToGet: %@,", attributesToGet] autorelease]];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"ConsistentRead: %d,", consistentRead] autorelease]];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"ReturnConsumedCapacity: %@,", returnConsumedCapacity] autorelease]];
    [buffer appendString:[super description]];
    [buffer appendString:@"}"];

    return [buffer autorelease];
}


-(void)setConsistentRead:(BOOL)theValue
{
    consistentRead      = theValue;
    consistentReadIsSet = YES;
}


-(void)dealloc
{
    [tableName release];
    [key release];
    [attributesToGet release];
    [returnConsumedCapacity release];

    [super dealloc];
}


@end
