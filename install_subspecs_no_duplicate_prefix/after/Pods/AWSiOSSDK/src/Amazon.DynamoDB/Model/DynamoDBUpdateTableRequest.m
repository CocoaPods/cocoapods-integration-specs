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

#import "DynamoDBUpdateTableRequest.h"


@implementation DynamoDBUpdateTableRequest

@synthesize tableName;
@synthesize provisionedThroughput;
@synthesize globalSecondaryIndexUpdates;


-(id)init
{
    if (self = [super init]) {
        tableName                   = nil;
        provisionedThroughput       = nil;
        globalSecondaryIndexUpdates = [[NSMutableArray alloc] initWithCapacity:1];
    }

    return self;
}

-(id)initWithTableName:(NSString *)theTableName andProvisionedThroughput:(DynamoDBProvisionedThroughput *)theProvisionedThroughput
{
    if (self = [self init]) {
        self.tableName             = theTableName;
        self.provisionedThroughput = theProvisionedThroughput;
    }

    return self;
}


-(void)addGlobalSecondaryIndexUpdate:(DynamoDBGlobalSecondaryIndexUpdate *)globalSecondaryIndexUpdateObject
{
    if (globalSecondaryIndexUpdates == nil) {
        globalSecondaryIndexUpdates = [[NSMutableArray alloc] initWithCapacity:1];
    }

    [globalSecondaryIndexUpdates addObject:globalSecondaryIndexUpdateObject];
}


-(NSString *)description
{
    NSMutableString *buffer = [[NSMutableString alloc] initWithCapacity:256];

    [buffer appendString:@"{"];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"TableName: %@,", tableName] autorelease]];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"ProvisionedThroughput: %@,", provisionedThroughput] autorelease]];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"GlobalSecondaryIndexUpdates: %@,", globalSecondaryIndexUpdates] autorelease]];
    [buffer appendString:[super description]];
    [buffer appendString:@"}"];

    return [buffer autorelease];
}



-(void)dealloc
{
    [tableName release];
    [provisionedThroughput release];
    [globalSecondaryIndexUpdates release];

    [super dealloc];
}


@end
