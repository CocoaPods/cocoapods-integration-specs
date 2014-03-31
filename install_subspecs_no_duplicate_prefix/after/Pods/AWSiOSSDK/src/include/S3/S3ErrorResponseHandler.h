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

#import <Foundation/Foundation.h>

#ifdef AWS_MULTI_FRAMEWORK
#import <AWSRuntime/AmazonServiceException.h>
#import <AWSRuntime/AmazonUnmarshallerXMLParserDelegate.h>
#else
#import "../AmazonServiceException.h"
#import "../AmazonUnmarshallerXMLParserDelegate.h"
#endif

/** Parse an error response from Amazon S3 and construct the corresponding
 * AWSServiceException object.
 *
 */
@interface S3ErrorResponseHandler:AmazonUnmarshallerXMLParserDelegate {
}

/** The exception represented by the XML */
@property (nonatomic, readonly) AmazonServiceException *exception;

/** Initialize the object with the an HTTP status code */
-(id)initWithStatusCode:(int32_t)statusCode;

@end
