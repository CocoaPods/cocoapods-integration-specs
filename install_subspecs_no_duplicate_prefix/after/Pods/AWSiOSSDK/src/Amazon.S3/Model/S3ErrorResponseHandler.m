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

#import "S3ErrorResponseHandler.h"
#import "AmazonUnmarshallerXMLParserDelegate.h"

@interface S3ErrorResponseHandler () {
}
@property (nonatomic, retain) AmazonServiceException *exception;
@property (nonatomic, assign) int32_t httpStatusCode;

@end


@implementation S3ErrorResponseHandler

-(id)initWithStatusCode:(int32_t)statusCode
{
    if (self = [super init])
    {
        _httpStatusCode = statusCode;
    }
    return self;
}

-(void)parser:(NSXMLParser *)parser didEndElement:(NSString *)elementName namespaceURI:(NSString *)namespaceURI qualifiedName:(NSString *)qName
{
    [super parser:parser didEndElement:elementName namespaceURI:namespaceURI qualifiedName:qName];

    if ([elementName isEqualToString:@"Message"]) {
        self.exception.message = self.currentText;
        return;
    }

    if ([elementName isEqualToString:@"Code"]) {
        self.exception.errorCode = self.currentText;
        return;
    }

    if ([elementName isEqualToString:@"RequestId"]) {
        self.exception.requestId = self.currentText;
        return;
    }
}

-(AmazonServiceException *)exception
{
    if (_exception == nil) {
        _exception = [[AmazonServiceException exceptionWithStatusCode:self.httpStatusCode] retain];
    }
    
    return _exception;
}

-(void)dealloc
{
    [_exception release];

    [super dealloc];
}


@end
