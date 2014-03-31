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

#import "S3CompleteMultipartUploadResponse.h"
#import "S3CompleteMultipartUploadResultUnmarshaller.h"


@implementation S3CompleteMultipartUploadResponse

-(void)processBody
{
    NSXMLParser                                 *parser       = [[NSXMLParser alloc] initWithData:self.body];
    S3CompleteMultipartUploadResultUnmarshaller *unmarshaller = [[S3CompleteMultipartUploadResultUnmarshaller alloc] init];

    [parser setDelegate:unmarshaller];
    [parser parse];

    if (completeMultipartUploadResult != nil) {
        [completeMultipartUploadResult release];
    }

    completeMultipartUploadResult = [unmarshaller.completeMultipartUploadResult retain];

    [unmarshaller release];
    [parser release];
}

-(S3CompleteMultipartUploadResult *)completeMultipartUploadResult
{
    if (nil == completeMultipartUploadResult) {
        completeMultipartUploadResult = [[S3CompleteMultipartUploadResult alloc] init];
    }
    return completeMultipartUploadResult;
}

-(void)dealloc
{
    [completeMultipartUploadResult release];

    [super dealloc];
}

@end
