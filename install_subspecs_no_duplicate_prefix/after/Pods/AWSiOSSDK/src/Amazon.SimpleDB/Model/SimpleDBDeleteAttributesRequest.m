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

#import "SimpleDBDeleteAttributesRequest.h"


@implementation SimpleDBDeleteAttributesRequest

@synthesize domainName;
@synthesize itemName;
@synthesize attributes;
@synthesize expected;


-(id)init
{
    if (self = [super init]) {
        domainName = nil;
        itemName   = nil;
        attributes = [[NSMutableArray alloc] initWithCapacity:1];
        expected   = nil;
    }

    return self;
}

-(id)initWithDomainName:(NSString *)theDomainName andItemName:(NSString *)theItemName
{
    if (self = [self init]) {
        self.domainName = theDomainName;
        self.itemName   = theItemName;
    }

    return self;
}

-(id)initWithDomainName:(NSString *)theDomainName andItemName:(NSString *)theItemName andAttributes:(NSMutableArray *)theAttributes
{
    if (self = [self init]) {
        self.domainName = theDomainName;
        self.itemName   = theItemName;
        self.attributes = theAttributes;
    }

    return self;
}

-(id)initWithDomainName:(NSString *)theDomainName andItemName:(NSString *)theItemName andAttributes:(NSMutableArray *)theAttributes andExpected:(SimpleDBUpdateCondition *)theExpected
{
    if (self = [self init]) {
        self.domainName = theDomainName;
        self.itemName   = theItemName;
        self.attributes = theAttributes;
        self.expected   = theExpected;
    }

    return self;
}


-(void)addAttribute:(SimpleDBAttribute *)attributeObject
{
    if (attributes == nil) {
        attributes = [[NSMutableArray alloc] initWithCapacity:1];
    }

    [attributes addObject:attributeObject];
}


-(NSString *)description
{
    NSMutableString *buffer = [[NSMutableString alloc] initWithCapacity:256];

    [buffer appendString:@"{"];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"DomainName: %@,", domainName] autorelease]];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"ItemName: %@,", itemName] autorelease]];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"Attributes: %@,", attributes] autorelease]];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"Expected: %@,", expected] autorelease]];
    [buffer appendString:[super description]];
    [buffer appendString:@"}"];

    return [buffer autorelease];
}



-(void)dealloc
{
    [domainName release];
    [itemName release];
    [attributes release];
    [expected release];

    [super dealloc];
}


@end
