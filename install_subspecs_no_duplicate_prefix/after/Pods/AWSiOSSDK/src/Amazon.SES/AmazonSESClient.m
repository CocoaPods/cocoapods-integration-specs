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

#import "AmazonSESClient.h"
#import "AmazonEndpoints.h"
#import "AmazonServiceRequest.h"
#import "SESDeleteIdentityResponseUnmarshaller.h"
#import "SESDeleteIdentityRequestMarshaller.h"
#import "SESListVerifiedEmailAddressesResponseUnmarshaller.h"
#import "SESListVerifiedEmailAddressesRequestMarshaller.h"
#import "SESGetSendStatisticsResponseUnmarshaller.h"
#import "SESGetSendStatisticsRequestMarshaller.h"
#import "SESVerifyEmailIdentityResponseUnmarshaller.h"
#import "SESVerifyEmailIdentityRequestMarshaller.h"
#import "SESGetIdentityNotificationAttributesResponseUnmarshaller.h"
#import "SESGetIdentityNotificationAttributesRequestMarshaller.h"
#import "SESVerifyDomainDkimResponseUnmarshaller.h"
#import "SESVerifyDomainDkimRequestMarshaller.h"
#import "SESGetIdentityDkimAttributesResponseUnmarshaller.h"
#import "SESGetIdentityDkimAttributesRequestMarshaller.h"
#import "SESVerifyEmailAddressResponseUnmarshaller.h"
#import "SESVerifyEmailAddressRequestMarshaller.h"
#import "SESSendRawEmailResponseUnmarshaller.h"
#import "SESSendRawEmailRequestMarshaller.h"
#import "SESListIdentitiesResponseUnmarshaller.h"
#import "SESListIdentitiesRequestMarshaller.h"
#import "SESGetIdentityVerificationAttributesResponseUnmarshaller.h"
#import "SESGetIdentityVerificationAttributesRequestMarshaller.h"
#import "SESSetIdentityDkimEnabledResponseUnmarshaller.h"
#import "SESSetIdentityDkimEnabledRequestMarshaller.h"
#import "SESGetSendQuotaResponseUnmarshaller.h"
#import "SESGetSendQuotaRequestMarshaller.h"
#import "SESSetIdentityFeedbackForwardingEnabledResponseUnmarshaller.h"
#import "SESSetIdentityFeedbackForwardingEnabledRequestMarshaller.h"
#import "SESVerifyDomainIdentityResponseUnmarshaller.h"
#import "SESVerifyDomainIdentityRequestMarshaller.h"
#import "SESSendEmailResponseUnmarshaller.h"
#import "SESSendEmailRequestMarshaller.h"
#import "SESDeleteVerifiedEmailAddressResponseUnmarshaller.h"
#import "SESDeleteVerifiedEmailAddressRequestMarshaller.h"
#import "SESSetIdentityNotificationTopicResponseUnmarshaller.h"
#import "SESSetIdentityNotificationTopicRequestMarshaller.h"


@implementation AmazonSESClient

-(id)initWithAccessKey:(NSString *)theAccessKey withSecretKey:(NSString *)theSecretKey
{
    if (self = [super initWithAccessKey:theAccessKey withSecretKey:theSecretKey]) {
        self.endpoint = AMAZON_SES_US_EAST_1_ENDPOINT_SECURE;
    }
    return self;
}

-(id)initWithCredentials:(AmazonCredentials *)theCredentials
{
    if (self = [super initWithCredentials:theCredentials]) {
        self.endpoint = AMAZON_SES_US_EAST_1_ENDPOINT_SECURE;
    }
    return self;
}

-(id)initWithCredentialsProvider:(id<AmazonCredentialsProvider> )theProvider
{
    if (self = [super initWithCredentialsProvider:theProvider]) {
        self.endpoint = AMAZON_SES_US_EAST_1_ENDPOINT_SECURE;
    }
    return self;
}

-(SESDeleteIdentityResponse *)deleteIdentity:(SESDeleteIdentityRequest *)deleteIdentityRequest
{
    AmazonServiceRequest *request = [SESDeleteIdentityRequestMarshaller createRequest:deleteIdentityRequest];

    return (SESDeleteIdentityResponse *)[self invoke:request rawRequest:deleteIdentityRequest unmarshallerDelegate:[SESDeleteIdentityResponseUnmarshaller class]];
}

-(SESListVerifiedEmailAddressesResponse *)listVerifiedEmailAddresses:(SESListVerifiedEmailAddressesRequest *)listVerifiedEmailAddressesRequest
{
    AmazonServiceRequest *request = [SESListVerifiedEmailAddressesRequestMarshaller createRequest:listVerifiedEmailAddressesRequest];

    return (SESListVerifiedEmailAddressesResponse *)[self invoke:request rawRequest:listVerifiedEmailAddressesRequest unmarshallerDelegate:[SESListVerifiedEmailAddressesResponseUnmarshaller class]];
}

-(SESGetSendStatisticsResponse *)getSendStatistics:(SESGetSendStatisticsRequest *)getSendStatisticsRequest
{
    AmazonServiceRequest *request = [SESGetSendStatisticsRequestMarshaller createRequest:getSendStatisticsRequest];

    return (SESGetSendStatisticsResponse *)[self invoke:request rawRequest:getSendStatisticsRequest unmarshallerDelegate:[SESGetSendStatisticsResponseUnmarshaller class]];
}

-(SESVerifyEmailIdentityResponse *)verifyEmailIdentity:(SESVerifyEmailIdentityRequest *)verifyEmailIdentityRequest
{
    AmazonServiceRequest *request = [SESVerifyEmailIdentityRequestMarshaller createRequest:verifyEmailIdentityRequest];

    return (SESVerifyEmailIdentityResponse *)[self invoke:request rawRequest:verifyEmailIdentityRequest unmarshallerDelegate:[SESVerifyEmailIdentityResponseUnmarshaller class]];
}

-(SESGetIdentityNotificationAttributesResponse *)getIdentityNotificationAttributes:(SESGetIdentityNotificationAttributesRequest *)getIdentityNotificationAttributesRequest
{
    AmazonServiceRequest *request = [SESGetIdentityNotificationAttributesRequestMarshaller createRequest:getIdentityNotificationAttributesRequest];

    return (SESGetIdentityNotificationAttributesResponse *)[self invoke:request rawRequest:getIdentityNotificationAttributesRequest unmarshallerDelegate:[SESGetIdentityNotificationAttributesResponseUnmarshaller class]];
}

-(SESVerifyDomainDkimResponse *)verifyDomainDkim:(SESVerifyDomainDkimRequest *)verifyDomainDkimRequest
{
    AmazonServiceRequest *request = [SESVerifyDomainDkimRequestMarshaller createRequest:verifyDomainDkimRequest];

    return (SESVerifyDomainDkimResponse *)[self invoke:request rawRequest:verifyDomainDkimRequest unmarshallerDelegate:[SESVerifyDomainDkimResponseUnmarshaller class]];
}

-(SESGetIdentityDkimAttributesResponse *)getIdentityDkimAttributes:(SESGetIdentityDkimAttributesRequest *)getIdentityDkimAttributesRequest
{
    AmazonServiceRequest *request = [SESGetIdentityDkimAttributesRequestMarshaller createRequest:getIdentityDkimAttributesRequest];

    return (SESGetIdentityDkimAttributesResponse *)[self invoke:request rawRequest:getIdentityDkimAttributesRequest unmarshallerDelegate:[SESGetIdentityDkimAttributesResponseUnmarshaller class]];
}

-(SESVerifyEmailAddressResponse *)verifyEmailAddress:(SESVerifyEmailAddressRequest *)verifyEmailAddressRequest
{
    AmazonServiceRequest *request = [SESVerifyEmailAddressRequestMarshaller createRequest:verifyEmailAddressRequest];

    return (SESVerifyEmailAddressResponse *)[self invoke:request rawRequest:verifyEmailAddressRequest unmarshallerDelegate:[SESVerifyEmailAddressResponseUnmarshaller class]];
}

-(SESSendRawEmailResponse *)sendRawEmail:(SESSendRawEmailRequest *)sendRawEmailRequest
{
    AmazonServiceRequest *request = [SESSendRawEmailRequestMarshaller createRequest:sendRawEmailRequest];

    return (SESSendRawEmailResponse *)[self invoke:request rawRequest:sendRawEmailRequest unmarshallerDelegate:[SESSendRawEmailResponseUnmarshaller class]];
}

-(SESListIdentitiesResponse *)listIdentities:(SESListIdentitiesRequest *)listIdentitiesRequest
{
    AmazonServiceRequest *request = [SESListIdentitiesRequestMarshaller createRequest:listIdentitiesRequest];

    return (SESListIdentitiesResponse *)[self invoke:request rawRequest:listIdentitiesRequest unmarshallerDelegate:[SESListIdentitiesResponseUnmarshaller class]];
}

-(SESGetIdentityVerificationAttributesResponse *)getIdentityVerificationAttributes:(SESGetIdentityVerificationAttributesRequest *)getIdentityVerificationAttributesRequest
{
    AmazonServiceRequest *request = [SESGetIdentityVerificationAttributesRequestMarshaller createRequest:getIdentityVerificationAttributesRequest];

    return (SESGetIdentityVerificationAttributesResponse *)[self invoke:request rawRequest:getIdentityVerificationAttributesRequest unmarshallerDelegate:[SESGetIdentityVerificationAttributesResponseUnmarshaller class]];
}

-(SESSetIdentityDkimEnabledResponse *)setIdentityDkimEnabled:(SESSetIdentityDkimEnabledRequest *)setIdentityDkimEnabledRequest
{
    AmazonServiceRequest *request = [SESSetIdentityDkimEnabledRequestMarshaller createRequest:setIdentityDkimEnabledRequest];

    return (SESSetIdentityDkimEnabledResponse *)[self invoke:request rawRequest:setIdentityDkimEnabledRequest unmarshallerDelegate:[SESSetIdentityDkimEnabledResponseUnmarshaller class]];
}

-(SESGetSendQuotaResponse *)getSendQuota:(SESGetSendQuotaRequest *)getSendQuotaRequest
{
    AmazonServiceRequest *request = [SESGetSendQuotaRequestMarshaller createRequest:getSendQuotaRequest];

    return (SESGetSendQuotaResponse *)[self invoke:request rawRequest:getSendQuotaRequest unmarshallerDelegate:[SESGetSendQuotaResponseUnmarshaller class]];
}

-(SESSetIdentityFeedbackForwardingEnabledResponse *)setIdentityFeedbackForwardingEnabled:(SESSetIdentityFeedbackForwardingEnabledRequest *)setIdentityFeedbackForwardingEnabledRequest
{
    AmazonServiceRequest *request = [SESSetIdentityFeedbackForwardingEnabledRequestMarshaller createRequest:setIdentityFeedbackForwardingEnabledRequest];

    return (SESSetIdentityFeedbackForwardingEnabledResponse *)[self invoke:request rawRequest:setIdentityFeedbackForwardingEnabledRequest unmarshallerDelegate:[SESSetIdentityFeedbackForwardingEnabledResponseUnmarshaller class]];
}

-(SESVerifyDomainIdentityResponse *)verifyDomainIdentity:(SESVerifyDomainIdentityRequest *)verifyDomainIdentityRequest
{
    AmazonServiceRequest *request = [SESVerifyDomainIdentityRequestMarshaller createRequest:verifyDomainIdentityRequest];

    return (SESVerifyDomainIdentityResponse *)[self invoke:request rawRequest:verifyDomainIdentityRequest unmarshallerDelegate:[SESVerifyDomainIdentityResponseUnmarshaller class]];
}

-(SESSendEmailResponse *)sendEmail:(SESSendEmailRequest *)sendEmailRequest
{
    AmazonServiceRequest *request = [SESSendEmailRequestMarshaller createRequest:sendEmailRequest];

    return (SESSendEmailResponse *)[self invoke:request rawRequest:sendEmailRequest unmarshallerDelegate:[SESSendEmailResponseUnmarshaller class]];
}

-(SESDeleteVerifiedEmailAddressResponse *)deleteVerifiedEmailAddress:(SESDeleteVerifiedEmailAddressRequest *)deleteVerifiedEmailAddressRequest
{
    AmazonServiceRequest *request = [SESDeleteVerifiedEmailAddressRequestMarshaller createRequest:deleteVerifiedEmailAddressRequest];

    return (SESDeleteVerifiedEmailAddressResponse *)[self invoke:request rawRequest:deleteVerifiedEmailAddressRequest unmarshallerDelegate:[SESDeleteVerifiedEmailAddressResponseUnmarshaller class]];
}

-(SESSetIdentityNotificationTopicResponse *)setIdentityNotificationTopic:(SESSetIdentityNotificationTopicRequest *)setIdentityNotificationTopicRequest
{
    AmazonServiceRequest *request = [SESSetIdentityNotificationTopicRequestMarshaller createRequest:setIdentityNotificationTopicRequest];

    return (SESSetIdentityNotificationTopicResponse *)[self invoke:request rawRequest:setIdentityNotificationTopicRequest unmarshallerDelegate:[SESSetIdentityNotificationTopicResponseUnmarshaller class]];
}



@end

