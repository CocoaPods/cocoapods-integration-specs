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

#import "SESRawMessage.h"

#ifdef AWS_MULTI_FRAMEWORK
#import <AWSRuntime/AmazonServiceRequestConfig.h>
#else
#import "../AmazonServiceRequestConfig.h"
#endif



/**
 * Send Raw Email Request
 */

@interface SESSendRawEmailRequest:AmazonServiceRequestConfig

{
    NSString       *source;
    NSMutableArray *destinations;
    SESRawMessage  *rawMessage;
}




/**
 * Default constructor for a new  object.  Callers should use the
 * property methods to initialize this object after creating it.
 */
-(id)init;

/**
 * The identity's email address. <p> By default, the string must be 7-bit
 * ASCII. If the text must contain any other characters, then you must
 * use MIME encoded-word syntax (RFC 2047) instead of a literal string.
 * MIME encoded-word syntax uses the following form:
 * <code>=?charset?encoding?encoded-text?=</code>. For more information,
 * see <a href="http://tools.ietf.org/html/rfc2047">RFC 2047</a>.
 * <note>If you specify the <code>Source</code> parameter, then bounce
 * notifications and complaints will be sent to this email address. This
 * takes precedence over any <i>Return-Path</i> header that you might
 * include in the raw text of the message. </note>
 */
@property (nonatomic, retain) NSString *source;

/**
 * A list of destinations for the message.
 */
@property (nonatomic, retain) NSMutableArray *destinations;

/**
 * The raw text of the message. The client is responsible for ensuring
 * the following: <p> <ul> <li>Message must contain a header and a body,
 * separated by a blank line.</li> <li>All required header fields must be
 * present.</li> <li>Each part of a multipart MIME message must be
 * formatted properly.</li> <li>MIME content types must be among those
 * supported by Amazon SES. For more information, go to the <a
 * /docs.aws.amazon.com/ses/latest/DeveloperGuide/mime-types.html">Amazon
 * SES Developer Guide</a>. </li> <li>Content must be base64-encoded, if
 * MIME requires it.</li> </ul>
 */
@property (nonatomic, retain) SESRawMessage *rawMessage;

/**
 * Adds a single object to destinations.
 * This function will alloc and init destinations if not already done.
 */
-(void)addDestination:(NSString *)destinationObject;

/**
 * Returns a string representation of this object; useful for testing and
 * debugging.
 *
 * @return A string representation of this object.
 */
-(NSString *)description;


@end
