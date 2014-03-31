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

#import "EC2PriceScheduleSpecification.h"


@implementation EC2PriceScheduleSpecification

@synthesize term;
@synthesize price;
@synthesize currencyCode;


-(id)init
{
    if (self = [super init]) {
        term         = nil;
        price        = nil;
        currencyCode = nil;
    }

    return self;
}



-(NSString *)description
{
    NSMutableString *buffer = [[NSMutableString alloc] initWithCapacity:256];

    [buffer appendString:@"{"];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"Term: %@,", term] autorelease]];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"Price: %@,", price] autorelease]];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"CurrencyCode: %@,", currencyCode] autorelease]];
    [buffer appendString:[super description]];
    [buffer appendString:@"}"];

    return [buffer autorelease];
}



-(void)dealloc
{
    [term release];
    [price release];
    [currencyCode release];

    [super dealloc];
}


@end
