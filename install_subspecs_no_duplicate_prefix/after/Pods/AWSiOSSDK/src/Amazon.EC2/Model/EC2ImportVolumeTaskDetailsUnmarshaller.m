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

#import "EC2ImportVolumeTaskDetailsUnmarshaller.h"
#ifdef AWS_MULTI_FRAMEWORK
#import <AWSRuntime/AmazonServiceExceptionUnmarshaller.h>
#else
#import "../AmazonServiceExceptionUnmarshaller.h"
#endif

@implementation EC2ImportVolumeTaskDetailsUnmarshaller


-(void)parser:(NSXMLParser *)parser didStartElement:(NSString *)elementName namespaceURI:(NSString *)namespaceURI qualifiedName:(NSString *)qName attributes:(NSDictionary *)attributeDict
{
    [super parser:parser didStartElement:elementName namespaceURI:namespaceURI qualifiedName:qName attributes:attributeDict];


    if ([elementName isEqualToString:@"image"]) {
        EC2DiskImageDescriptionUnmarshaller *unmarshaller = [[[EC2DiskImageDescriptionUnmarshaller alloc] initWithCaller:self withParentObject:self.response withSetter:@selector(setImage:)] autorelease];
        unmarshaller.endElementTagName = @"image";
        [parser setDelegate:unmarshaller];
    }

    if ([elementName isEqualToString:@"volume"]) {
        EC2DiskImageVolumeDescriptionUnmarshaller *unmarshaller = [[[EC2DiskImageVolumeDescriptionUnmarshaller alloc] initWithCaller:self withParentObject:self.response withSetter:@selector(setVolume:)] autorelease];
        unmarshaller.endElementTagName = @"volume";
        [parser setDelegate:unmarshaller];
    }



    if ([elementName isEqualToString:@"Error"]) {
        [parser setDelegate:[[[AmazonServiceExceptionUnmarshaller alloc] initWithCaller:self withParentObject:self.response withSetter:@selector(setException:)] autorelease]];
    }
}

-(void)parser:(NSXMLParser *)parser didEndElement:(NSString *)elementName namespaceURI:(NSString *)namespaceURI qualifiedName:(NSString *)qName
{
    [super parser:parser didEndElement:elementName namespaceURI:namespaceURI qualifiedName:qName];


    if ([[elementName lowercaseString] isEqualToString:@"requestid"]) {
        if (parentObject != nil && [parentObject respondsToSelector:@selector(setRequestId:)]) {
            [parentObject performSelector:@selector(setRequestId:) withObject:self.currentText];
        }
    }

    if ([elementName isEqualToString:@"bytesConverted"]) {
        self.response.bytesConverted = [AmazonSDKUtil convertStringToNumber:self.currentText];
        return;
    }

    if ([elementName isEqualToString:@"availabilityZone"]) {
        self.response.availabilityZone = self.currentText;
        return;
    }

    if ([elementName isEqualToString:@"description"]) {
        self.response.descriptionValue = self.currentText;
        return;
    }

    if ([elementName isEqualToString:@"importVolumeTaskDetails"]) {
        if (caller != nil) {
            [parser setDelegate:caller];
        }

        if (parentObject != nil && [parentObject respondsToSelector:parentSetter]) {
            [parentObject performSelector:parentSetter withObject:self.response];
        }

        return;
    }
}

-(EC2ImportVolumeTaskDetails *)response
{
    if (nil == response) {
        response = [[EC2ImportVolumeTaskDetails alloc] init];
    }
    return response;
}


-(void)dealloc
{
    [response release];
    [super dealloc];
}

@end
