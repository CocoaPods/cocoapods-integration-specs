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


#import "SNSResponse.h"

#import "SNSNotFoundException.h"
#import "SNSAuthorizationErrorException.h"
#import "SNSInternalErrorException.h"
#import "SNSInvalidParameterException.h"


/**
 * Get Topic Attributes Result
 */

@interface SNSGetTopicAttributesResponse:SNSResponse

{
    NSMutableDictionary *attributes;
}



-(void)setException:(AmazonServiceException *)theException;


/**
 * Default constructor for a new  object.  Callers should use the
 * property methods to initialize this object after creating it.
 */
-(id)init;

/**
 * A map of the topic's attributes. Attributes in this map include the
 * following: <ul> <li><code>TopicArn</code> -- the topic's ARN</li>
 * <li><code>Owner</code> -- the AWS account ID of the topic's owner</li>
 * <li><code>Policy</code> -- the JSON serialization of the topic's
 * access control policy</li> <li><code>DisplayName</code> -- the
 * human-readable name used in the "From" field for notifications to
 * email and email-json endpoints</li>
 * <li><code>SubscriptionsPending</code> -- the number of subscriptions
 * pending confirmation on this topic</li>
 * <li><code>SubscriptionsConfirmed</code> -- the number of confirmed
 * subscriptions on this topic</li> <li><code>SubscriptionsDeleted</code>
 * -- the number of deleted subscriptions on this topic</li>
 * <li><code>DeliveryPolicy</code> -- the JSON serialization of the
 * topic's delivery policy</li> <li><code>EffectiveDeliveryPolicy</code>
 * -- the JSON serialization of the effective delivery policy that takes
 * into account system defaults</li> </ul>
 */
@property (nonatomic, retain) NSMutableDictionary *attributes;

/**
 * Returns a value from the attributes dictionary for the specified key.
 */
-(NSString *)attributesValueForKey:(NSString *)theKey;

/**
 * Returns a string representation of this object; useful for testing and
 * debugging.
 *
 * @return A string representation of this object.
 */
-(NSString *)description;


@end
