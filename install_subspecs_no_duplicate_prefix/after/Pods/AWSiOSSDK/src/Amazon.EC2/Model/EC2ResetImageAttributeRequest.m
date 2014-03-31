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

#import "EC2ResetImageAttributeRequest.h"


@implementation EC2ResetImageAttributeRequest

@synthesize dryRun;
@synthesize dryRunIsSet;
@synthesize imageId;
@synthesize attribute;


-(id)init
{
    if (self = [super init]) {
        dryRun      = NO;
        dryRunIsSet = NO;
        imageId     = nil;
        attribute   = nil;
    }

    return self;
}

-(id)initWithImageId:(NSString *)theImageId andAttribute:(NSString *)theAttribute
{
    if (self = [self init]) {
        self.imageId   = theImageId;
        self.attribute = theAttribute;
    }

    return self;
}



-(NSString *)description
{
    NSMutableString *buffer = [[NSMutableString alloc] initWithCapacity:256];

    [buffer appendString:@"{"];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"DryRun: %d,", dryRun] autorelease]];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"ImageId: %@,", imageId] autorelease]];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"Attribute: %@,", attribute] autorelease]];
    [buffer appendString:[super description]];
    [buffer appendString:@"}"];

    return [buffer autorelease];
}


-(void)setDryRun:(BOOL)theValue
{
    dryRun      = theValue;
    dryRunIsSet = YES;
}


-(void)dealloc
{
    [imageId release];
    [attribute release];

    [super dealloc];
}


@end
