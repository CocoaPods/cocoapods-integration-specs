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

#import "S3GetBucketWebsiteConfigurationRequest.h"

@implementation S3GetBucketWebsiteConfigurationRequest

-(id)initWithBucketName:(NSString *)theBucketName
{
    self = [super init];
    if (self)
    {
        self.bucket = theBucketName;
    }

    return self;
}

+(id)requestWithBucketName:(NSString *)theBucketName
{
    return [[[S3GetBucketWebsiteConfigurationRequest alloc] initWithBucketName:theBucketName] autorelease];
}

-(NSMutableURLRequest *)configureURLRequest
{
    [self setSubResource:kS3SubResourceWebsite];

    [super configureURLRequest];

    [self.urlRequest setHTTPMethod:kHttpMethodGet];

    return urlRequest;
}

@end
