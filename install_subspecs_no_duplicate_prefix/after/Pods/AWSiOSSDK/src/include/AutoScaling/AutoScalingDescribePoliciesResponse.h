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

#import "AutoScalingScalingPolicy.h"

#import "AutoScalingResponse.h"

#import "AutoScalingInvalidNextTokenException.h"


/**
 * Describe Policies Result
 */

@interface AutoScalingDescribePoliciesResponse:AutoScalingResponse

{
    NSMutableArray *scalingPolicies;
    NSString       *nextToken;
}



-(void)setException:(AmazonServiceException *)theException;


/**
 * Default constructor for a new  object.  Callers should use the
 * property methods to initialize this object after creating it.
 */
-(id)init;

/**
 * A list of scaling policies.
 */
@property (nonatomic, retain) NSMutableArray *scalingPolicies;

/**
 * A string that marks the start of the next batch of returned results.
 * <p>
 * <b>Constraints:</b><br/>
 * <b>Pattern: </b>[\u0020-\uD7FF\uE000-\uFFFD\uD800\uDC00-\uDBFF\uDFFF\r\n\t]*<br/>
 */
@property (nonatomic, retain) NSString *nextToken;



/**
 * Returns a value from the scalingPolicies array for the specified index
 */
-(AutoScalingScalingPolicy *)scalingPoliciesObjectAtIndex:(int)index;

/**
 * Returns a string representation of this object; useful for testing and
 * debugging.
 *
 * @return A string representation of this object.
 */
-(NSString *)description;


@end
