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

#import "ElasticLoadBalancingListenerUnmarshaller.h"
#ifdef AWS_MULTI_FRAMEWORK
#import <AWSRuntime/AmazonServiceExceptionUnmarshaller.h>
#else
#import "../AmazonServiceExceptionUnmarshaller.h"
#endif

@implementation ElasticLoadBalancingListenerUnmarshaller


-(void)parser:(NSXMLParser *)parser didStartElement:(NSString *)elementName namespaceURI:(NSString *)namespaceURI qualifiedName:(NSString *)qName attributes:(NSDictionary *)attributeDict
{
    [super parser:parser didStartElement:elementName namespaceURI:namespaceURI qualifiedName:qName attributes:attributeDict];




    if ([elementName isEqualToString:@"Error"]) {
        [parser setDelegate:[[[AmazonServiceExceptionUnmarshaller alloc] initWithCaller:self withParentObject:self.response withSetter:@selector(setException:)] autorelease]];
    }
}

-(void)parser:(NSXMLParser *)parser didEndElement:(NSString *)elementName namespaceURI:(NSString *)namespaceURI qualifiedName:(NSString *)qName
{
    [super parser:parser didEndElement:elementName namespaceURI:namespaceURI qualifiedName:qName];


    if ([elementName isEqualToString:@"Protocol"]) {
        self.response.protocol = self.currentText;
        return;
    }

    if ([elementName isEqualToString:@"LoadBalancerPort"]) {
        self.response.loadBalancerPort = [AmazonSDKUtil convertStringToNumber:self.currentText];
        return;
    }

    if ([elementName isEqualToString:@"InstanceProtocol"]) {
        self.response.instanceProtocol = self.currentText;
        return;
    }

    if ([elementName isEqualToString:@"InstancePort"]) {
        self.response.instancePort = [AmazonSDKUtil convertStringToNumber:self.currentText];
        return;
    }

    if ([elementName isEqualToString:@"SSLCertificateId"]) {
        self.response.sSLCertificateId = self.currentText;
        return;
    }

    if ([elementName isEqualToString:@"Listener"]) {
        if (caller != nil) {
            [parser setDelegate:caller];
        }

        if (parentObject != nil && [parentObject respondsToSelector:parentSetter]) {
            [parentObject performSelector:parentSetter withObject:self.response];
        }

        return;
    }
}

-(ElasticLoadBalancingListener *)response
{
    if (nil == response) {
        response = [[ElasticLoadBalancingListener alloc] init];
    }
    return response;
}


-(void)dealloc
{
    [response release];
    [super dealloc];
}

@end
