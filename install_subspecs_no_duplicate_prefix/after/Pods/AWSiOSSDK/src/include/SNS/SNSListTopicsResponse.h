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

#import "SNSTopic.h"

#import "SNSResponse.h"

#import "SNSAuthorizationErrorException.h"
#import "SNSInternalErrorException.h"
#import "SNSInvalidParameterException.h"


/**
 * List Topics Result
 */

@interface SNSListTopicsResponse:SNSResponse

{
    NSMutableArray *topics;
    NSString       *nextToken;
}



-(void)setException:(AmazonServiceException *)theException;


/**
 * Default constructor for a new  object.  Callers should use the
 * property methods to initialize this object after creating it.
 */
-(id)init;

/**
 * A list of topic ARNs.
 */
@property (nonatomic, retain) NSMutableArray *topics;

/**
 * Token to pass along to the next <code>ListTopics</code> request. This
 * element is returned if there are additional topics to retrieve.
 */
@property (nonatomic, retain) NSString *nextToken;



/**
 * Returns a value from the topics array for the specified index
 */
-(SNSTopic *)topicsObjectAtIndex:(int)index;

/**
 * Returns a string representation of this object; useful for testing and
 * debugging.
 *
 * @return A string representation of this object.
 */
-(NSString *)description;


@end
