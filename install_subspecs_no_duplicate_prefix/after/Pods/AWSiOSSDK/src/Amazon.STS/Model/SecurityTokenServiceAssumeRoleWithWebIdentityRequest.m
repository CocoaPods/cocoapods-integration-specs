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

#import "SecurityTokenServiceAssumeRoleWithWebIdentityRequest.h"


@implementation SecurityTokenServiceAssumeRoleWithWebIdentityRequest

@synthesize roleArn;
@synthesize roleSessionName;
@synthesize webIdentityToken;
@synthesize providerId;
@synthesize policy;
@synthesize durationSeconds;


-(id)init
{
    if (self = [super init]) {
        roleArn          = nil;
        roleSessionName  = nil;
        webIdentityToken = nil;
        providerId       = nil;
        policy           = nil;
        durationSeconds  = nil;
    }

    return self;
}



-(NSString *)description
{
    NSMutableString *buffer = [[NSMutableString alloc] initWithCapacity:256];

    [buffer appendString:@"{"];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"RoleArn: %@,", roleArn] autorelease]];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"RoleSessionName: %@,", roleSessionName] autorelease]];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"WebIdentityToken: %@,", webIdentityToken] autorelease]];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"ProviderId: %@,", providerId] autorelease]];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"Policy: %@,", policy] autorelease]];
    [buffer appendString:[[[NSString alloc] initWithFormat:@"DurationSeconds: %@,", durationSeconds] autorelease]];
    [buffer appendString:[super description]];
    [buffer appendString:@"}"];

    return [buffer autorelease];
}



-(void)dealloc
{
    [roleArn release];
    [roleSessionName release];
    [webIdentityToken release];
    [providerId release];
    [policy release];
    [durationSeconds release];

    [super dealloc];
}


@end
