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

#import "SimpleDBAttribute.h"

#import "SimpleDBResponse.h"

#import "SimpleDBInvalidParameterValueException.h"
#import "SimpleDBNoSuchDomainException.h"
#import "SimpleDBMissingParameterException.h"


/**
 * Get Attributes Result
 */

@interface SimpleDBGetAttributesResponse:SimpleDBResponse

{
    NSMutableArray *attributes;
}



-(void)setException:(AmazonServiceException *)theException;


/**
 * Default constructor for a new  object.  Callers should use the
 * property methods to initialize this object after creating it.
 */
-(id)init;

/**
 * The list of attributes returned by the operation.
 */
@property (nonatomic, retain) NSMutableArray *attributes;



/**
 * Returns a value from the attributes array for the specified index
 */
-(SimpleDBAttribute *)attributesObjectAtIndex:(int)index;

/**
 * Returns a string representation of this object; useful for testing and
 * debugging.
 *
 * @return A string representation of this object.
 */
-(NSString *)description;


@end
