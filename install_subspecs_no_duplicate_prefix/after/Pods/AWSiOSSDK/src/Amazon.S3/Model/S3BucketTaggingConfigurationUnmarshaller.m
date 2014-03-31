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

#import "S3BucketTaggingConfigurationUnmarshaller.h"
#import "S3BucketTagSetUnmarshaller.h"

@implementation S3BucketTaggingConfigurationUnmarshaller

#pragma mark NSXMLParserDelegate implementation

-(void) parser:(NSXMLParser *)parser didStartElement:(NSString *)elementName namespaceURI:(NSString *)namespaceURI qualifiedName:(NSString *)qualifiedName attributes:(NSDictionary *)attributeDict
{
    [super parser:parser didStartElement:elementName namespaceURI:namespaceURI qualifiedName:qualifiedName attributes:attributeDict];
    
    if ([elementName isEqualToString:@"TagSet"])
    {
        [parser setDelegate:[[[S3BucketTagSetUnmarshaller alloc] initWithCaller:self withParentObject:[self configuration].tagsets withSetter:@selector(addObject:)] autorelease]];
    }
}

#pragma mark - Unmarshalled object property

-(S3BucketTaggingConfiguration *)configuration
{
    if (nil == configuration)
    {
        configuration = [[S3BucketTaggingConfiguration alloc] init];
        configuration.tagsets = [NSMutableArray arrayWithCapacity:1];
    }
    return configuration;
}

-(void)dealloc
{
    [configuration release];
    [super dealloc];
}

@end
