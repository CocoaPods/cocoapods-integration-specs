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




/**
 * Create Volume Permission
 */

@interface EC2CreateVolumePermission:NSObject

{
    NSString *userId;
    NSString *group;
}




/**
 * Default constructor for a new  object.  Callers should use the
 * property methods to initialize this object after creating it.
 */
-(id)init;

/**
 * The user ID of the user that can create volumes from the snapshot.
 */
@property (nonatomic, retain) NSString *userId;

/**
 * The group that is allowed to create volumes from the snapshot
 * (currently supports "all").
 * <p>
 * <b>Constraints:</b><br/>
 * <b>Allowed Values: </b>all
 */
@property (nonatomic, retain) NSString *group;

/**
 * Returns a string representation of this object; useful for testing and
 * debugging.
 *
 * @return A string representation of this object.
 */
-(NSString *)description;


@end
