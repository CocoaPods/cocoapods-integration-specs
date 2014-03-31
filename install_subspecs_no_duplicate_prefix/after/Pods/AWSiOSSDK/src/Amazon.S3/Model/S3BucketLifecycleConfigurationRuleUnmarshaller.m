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

#import "S3BucketLifecycleConfigurationRuleUnmarshaller.h"
#import "S3BucketLifecycleConfigurationTransitionUnmarshaller.h"
#import "AmazonSDKUtil.h"

@implementation S3BucketLifecycleConfigurationRuleUnmarshaller

@synthesize rule;

#pragma mark - NSXMLParserDelegate implementation

-(void) parser:(NSXMLParser *)parser didStartElement:(NSString *)elementName namespaceURI:(NSString *)namespaceURI qualifiedName:(NSString *)qualifiedName attributes:(NSDictionary *)attributeDict
{
    [super parser:parser didStartElement:elementName namespaceURI:namespaceURI qualifiedName:qualifiedName attributes:attributeDict];
    
    if ([elementName isEqualToString:@"Transition"])
    {
        [parser setDelegate:[[[S3BucketLifecycleConfigurationTransitionUnmarshaller alloc] initWithCaller:self withParentObject:[self rule].transitions withSetter:@selector(addObject:)] autorelease]];
    }
}

-(void) parser:(NSXMLParser *)parser didEndElement:(NSString *)elementName namespaceURI:(NSString *)namespaceURI qualifiedName:(NSString *)qName
{
    [super parser:parser didEndElement:elementName namespaceURI:namespaceURI qualifiedName:qName];
    
    if ([elementName isEqualToString:@"ID"])
    {
        self.rule.ruleId = self.currentText;
    }
    else if ([elementName isEqualToString:@"Status"])
    {
        self.rule.status = self.currentText;
    }
    else if ([elementName isEqualToString:@"Prefix"])
    {
        self.rule.prefix = self.currentText;
    }
    else if ([elementName isEqualToString:@"Days"])
    {
        self.rule.expirationInDays = [self.currentText integerValue];
    }
    else if ([elementName isEqualToString:@"Date"])
    {
        self.rule.expirationDate = [AmazonSDKUtil convertStringToDate:self.currentText];
    }
    else if ([elementName isEqualToString:@"Rule"])
    {
        if (caller != nil) {
            [parser setDelegate:caller];
        }
        
        if (parentObject != nil && [parentObject respondsToSelector:parentSetter]) {
            [parentObject performSelector:parentSetter withObject:self.rule];
        }
        
        return;
    }
}

#pragma mark - Unmarshalled object property

-(S3BucketLifecycleConfigurationRule *)rule
{
    if (rule == nil)
    {
        rule = [[S3BucketLifecycleConfigurationRule alloc] init];
        rule.transitions = [NSMutableArray arrayWithCapacity:1];
    }
    
    return rule;
}

#pragma mark -

-(void)dealloc
{
    [rule release];
    
    [super dealloc];
}

@end
