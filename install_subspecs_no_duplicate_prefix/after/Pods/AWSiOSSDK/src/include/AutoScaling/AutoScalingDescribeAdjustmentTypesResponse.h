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

#import "AutoScalingAdjustmentType.h"

#import "AutoScalingResponse.h"



/**
 * Describe Adjustment Types Result
 */

@interface AutoScalingDescribeAdjustmentTypesResponse:AutoScalingResponse

{
    NSMutableArray *adjustmentTypes;
}



-(void)setException:(AmazonServiceException *)theException;


/**
 * Default constructor for a new  object.  Callers should use the
 * property methods to initialize this object after creating it.
 */
-(id)init;

/**
 * A list of specific policy adjustment types.
 */
@property (nonatomic, retain) NSMutableArray *adjustmentTypes;



/**
 * Returns a value from the adjustmentTypes array for the specified index
 */
-(AutoScalingAdjustmentType *)adjustmentTypesObjectAtIndex:(int)index;

/**
 * Returns a string representation of this object; useful for testing and
 * debugging.
 *
 * @return A string representation of this object.
 */
-(NSString *)description;


@end
