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

#import "S3ListPartsRequest.h"

@implementation S3ListPartsRequest

-(id)init
{
    if (self = [super init])
    {
        _maxParts = 1000;
        _partNumberMarker = 0;
    }
    return self;
}

-(id)initWithMultipartUpload:(S3MultipartUpload *)multipartUpload
{
    if(self = [self init])
    {
        self.bucket   = multipartUpload.bucket;
        self.key      = multipartUpload.key;
        self.uploadId = multipartUpload.uploadId;
    }

    return self;
}

-(NSMutableURLRequest *)configureURLRequest
{
    NSMutableString *subresource = [NSMutableString stringWithFormat:@"%@=%@", kS3QueryParamUploadId, self.uploadId];

    if (self.maxParts != 1000) {
        [subresource appendFormat:@"&%@=%d", kS3QueryParamMaxParts, self.maxParts];
    }

    if (self.partNumberMarker != 0) {
        [subresource appendFormat:@"&%@=%d", kS3QueryParamPartNumberMarker, self.partNumberMarker];
    }

    self.subResource = [NSString stringWithString:subresource];

    [super configureURLRequest];

    [urlRequest setHTTPMethod:kHttpMethodGet];

    return urlRequest;
}

-(void)dealloc
{
    [_uploadId release];

    [super dealloc];
}

@end
