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

#import "SESContent.h"
#import "SESContent.h"



/**
 * Body
 */

@interface SESBody:NSObject

{
    SESContent *text;
    SESContent *html;
}




/**
 * Default constructor for a new  object.  Callers should use the
 * property methods to initialize this object after creating it.
 */
-(id)init;

/**
 * The content of the message, in text format. Use this for text-based
 * email clients, or clients on high-latency networks (such as mobile
 * devices).
 */
@property (nonatomic, retain) SESContent *text;

/**
 * The content of the message, in HTML format. Use this for email clients
 * that can process HTML. You can include clickable links, formatted
 * text, and much more in an HTML message.
 */
@property (nonatomic, retain) SESContent *html;

/**
 * Returns a string representation of this object; useful for testing and
 * debugging.
 *
 * @return A string representation of this object.
 */
-(NSString *)description;


@end
