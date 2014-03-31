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
#import "SESDeleteIdentityResponse.h"
#import "SESDeleteIdentityRequest.h"
#import "SESListVerifiedEmailAddressesResponse.h"
#import "SESListVerifiedEmailAddressesRequest.h"
#import "SESGetSendStatisticsResponse.h"
#import "SESGetSendStatisticsRequest.h"
#import "SESVerifyEmailIdentityResponse.h"
#import "SESVerifyEmailIdentityRequest.h"
#import "SESGetIdentityNotificationAttributesResponse.h"
#import "SESGetIdentityNotificationAttributesRequest.h"
#import "SESVerifyDomainDkimResponse.h"
#import "SESVerifyDomainDkimRequest.h"
#import "SESGetIdentityDkimAttributesResponse.h"
#import "SESGetIdentityDkimAttributesRequest.h"
#import "SESVerifyEmailAddressResponse.h"
#import "SESVerifyEmailAddressRequest.h"
#import "SESSendRawEmailResponse.h"
#import "SESSendRawEmailRequest.h"
#import "SESListIdentitiesResponse.h"
#import "SESListIdentitiesRequest.h"
#import "SESGetIdentityVerificationAttributesResponse.h"
#import "SESGetIdentityVerificationAttributesRequest.h"
#import "SESSetIdentityDkimEnabledResponse.h"
#import "SESSetIdentityDkimEnabledRequest.h"
#import "SESGetSendQuotaResponse.h"
#import "SESGetSendQuotaRequest.h"
#import "SESSetIdentityFeedbackForwardingEnabledResponse.h"
#import "SESSetIdentityFeedbackForwardingEnabledRequest.h"
#import "SESVerifyDomainIdentityResponse.h"
#import "SESVerifyDomainIdentityRequest.h"
#import "SESSendEmailResponse.h"
#import "SESSendEmailRequest.h"
#import "SESDeleteVerifiedEmailAddressResponse.h"
#import "SESDeleteVerifiedEmailAddressRequest.h"
#import "SESSetIdentityNotificationTopicResponse.h"
#import "SESSetIdentityNotificationTopicRequest.h"

#ifdef AWS_MULTI_FRAMEWORK
#import <AWSRuntime/AmazonWebServiceClient.h>
#else
#import "../AmazonWebServiceClient.h"
#endif

/** \defgroup SES Amazon SES */

/** <summary>
 * Interface for accessing AmazonSES.
 *
 *  Amazon SES
 * </summary>
 *
 * See our blog to learn more about Managing Credentials in Mobile Applications.
 * @see http://mobile.awsblog.com/post/Tx31X75XISXHRH8/Managing-Credentials-in-Mobile-Applications
 */
@interface AmazonSESClient:AmazonWebServiceClient
{
}


/**
 * <p>
 * Deletes the specified identity (email address or domain) from the list of verified identities.
 * </p>
 * <p>
 * This action is throttled at one request per second.
 * </p>
 *
 * @param deleteIdentityRequest Container for the necessary parameters to execute the DeleteIdentity service method on
 *           AmazonSES.
 *
 * @return The response from the DeleteIdentity service method, as returned by AmazonSES.
 *
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonSES indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see SESDeleteIdentityRequest
 * @see SESDeleteIdentityResponse
 */
-(SESDeleteIdentityResponse *)deleteIdentity:(SESDeleteIdentityRequest *)deleteIdentityRequest;


/**
 * <p>
 * Returns a list containing all of the email addresses that have been verified.
 * </p>
 * <p>
 * <b>IMPORTANT:</b>The ListVerifiedEmailAddresses action is deprecated as of the May 15, 2012 release of Domain
 * Verification. The ListIdentities action is now preferred.
 * </p>
 * <p>
 * This action is throttled at one request per second.
 * </p>
 *
 * @param listVerifiedEmailAddressesRequest Container for the necessary parameters to execute the
 *           ListVerifiedEmailAddresses service method on AmazonSES.
 *
 * @return The response from the ListVerifiedEmailAddresses service method, as returned by AmazonSES.
 *
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonSES indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see SESListVerifiedEmailAddressesRequest
 * @see SESListVerifiedEmailAddressesResponse
 */
-(SESListVerifiedEmailAddressesResponse *)listVerifiedEmailAddresses:(SESListVerifiedEmailAddressesRequest *)listVerifiedEmailAddressesRequest;


/**
 * <p>
 * Returns the user's sending statistics. The result is a list of data points, representing the last two weeks of sending
 * activity.
 * </p>
 * <p>
 * Each data point in the list contains statistics for a 15-minute interval.
 * </p>
 * <p>
 * This action is throttled at one request per second.
 * </p>
 *
 * @param getSendStatisticsRequest Container for the necessary parameters to execute the GetSendStatistics service method
 *           on AmazonSES.
 *
 * @return The response from the GetSendStatistics service method, as returned by AmazonSES.
 *
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonSES indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see SESGetSendStatisticsRequest
 * @see SESGetSendStatisticsResponse
 */
-(SESGetSendStatisticsResponse *)getSendStatistics:(SESGetSendStatisticsRequest *)getSendStatisticsRequest;


/**
 * <p>
 * Verifies an email address. This action causes a confirmation email message to be sent to the specified address.
 * </p>
 * <p>
 * This action is throttled at one request per second.
 * </p>
 *
 * @param verifyEmailIdentityRequest Container for the necessary parameters to execute the VerifyEmailIdentity service
 *           method on AmazonSES.
 *
 * @return The response from the VerifyEmailIdentity service method, as returned by AmazonSES.
 *
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonSES indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see SESVerifyEmailIdentityRequest
 * @see SESVerifyEmailIdentityResponse
 */
-(SESVerifyEmailIdentityResponse *)verifyEmailIdentity:(SESVerifyEmailIdentityRequest *)verifyEmailIdentityRequest;


/**
 * <p>
 * Given a list of verified identities (email addresses and/or domains), returns a structure describing identity
 * notification attributes.
 * </p>
 * <p>
 * This action is throttled at one request per second.
 * </p>
 * <p>
 * For more information about feedback notification, see the <a
 * href="http://docs.aws.amazon.com/ses/latest/DeveloperGuide/bounce-complaint-notifications.html"> Amazon SES Developer
 * Guide </a> .
 * </p>
 *
 * @param getIdentityNotificationAttributesRequest Container for the necessary parameters to execute the
 *           GetIdentityNotificationAttributes service method on AmazonSES.
 *
 * @return The response from the GetIdentityNotificationAttributes service method, as returned by AmazonSES.
 *
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonSES indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see SESGetIdentityNotificationAttributesRequest
 * @see SESGetIdentityNotificationAttributesResponse
 */
-(SESGetIdentityNotificationAttributesResponse *)getIdentityNotificationAttributes:(SESGetIdentityNotificationAttributesRequest *)getIdentityNotificationAttributesRequest;


/**
 * <p>
 * Returns a set of DKIM tokens for a domain. DKIM <i>tokens</i> are character strings that represent your domain's
 * identity. Using these tokens, you will need to create DNS CNAME records that point to DKIM public keys hosted by Amazon
 * SES. Amazon Web Services will eventually detect that you have updated your DNS records; this detection process may take
 * up to 72 hours. Upon successful detection, Amazon SES will be able to DKIM-sign email originating from that domain.
 * </p>
 * <p>
 * This action is throttled at one request per second.
 * </p>
 * <p>
 * To enable or disable Easy DKIM signing for a domain, use the SetIdentityDkimEnabled action.
 * </p>
 * <p>
 * For more information about creating DNS records using DKIM tokens, go to the <a
 * href="http://docs.aws.amazon.com/ses/latest/DeveloperGuide/easy-dkim-dns-records.html"> Amazon SES Developer Guide </a>
 * .
 * </p>
 *
 * @param verifyDomainDkimRequest Container for the necessary parameters to execute the VerifyDomainDkim service method on
 *           AmazonSES.
 *
 * @return The response from the VerifyDomainDkim service method, as returned by AmazonSES.
 *
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonSES indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see SESVerifyDomainDkimRequest
 * @see SESVerifyDomainDkimResponse
 */
-(SESVerifyDomainDkimResponse *)verifyDomainDkim:(SESVerifyDomainDkimRequest *)verifyDomainDkimRequest;


/**
 * <p>
 * Returns the current status of Easy DKIM signing for an entity. For domain name identities, this action also returns the
 * DKIM tokens that are required for Easy DKIM signing, and whether Amazon SES has successfully verified that these tokens
 * have been published.
 * </p>
 * <p>
 * This action takes a list of identities as input and returns the following information for each:
 * </p>
 *
 * <ul>
 * <li>Whether Easy DKIM signing is enabled or disabled.</li>
 * <li>A set of DKIM tokens that represent the identity. If the identity is an email address, the tokens represent the
 * domain of that address.</li>
 * <li>Whether Amazon SES has successfully verified the DKIM tokens published in the domain's DNS. This information is
 * only returned for domain name identities, not for email addresses.</li>
 *
 * </ul>
 * <p>
 * This action is throttled at one request per second.
 * </p>
 * <p>
 * For more information about creating DNS records using DKIM tokens, go to the <a
 * href="http://docs.aws.amazon.com/ses/latest/DeveloperGuide/easy-dkim-dns-records.html"> Amazon SES Developer Guide </a>
 * .
 * </p>
 *
 * @param getIdentityDkimAttributesRequest Container for the necessary parameters to execute the GetIdentityDkimAttributes
 *           service method on AmazonSES.
 *
 * @return The response from the GetIdentityDkimAttributes service method, as returned by AmazonSES.
 *
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonSES indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see SESGetIdentityDkimAttributesRequest
 * @see SESGetIdentityDkimAttributesResponse
 */
-(SESGetIdentityDkimAttributesResponse *)getIdentityDkimAttributes:(SESGetIdentityDkimAttributesRequest *)getIdentityDkimAttributesRequest;


/**
 * <p>
 * Verifies an email address. This action causes a confirmation email message to be sent to the specified address.
 * </p>
 * <p>
 * <b>IMPORTANT:</b>The VerifyEmailAddress action is deprecated as of the May 15, 2012 release of Domain Verification. The
 * VerifyEmailIdentity action is now preferred.
 * </p>
 * <p>
 * This action is throttled at one request per second.
 * </p>
 *
 * @param verifyEmailAddressRequest Container for the necessary parameters to execute the VerifyEmailAddress service method
 *           on AmazonSES.
 *
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonSES indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see SESVerifyEmailAddressRequest
 * @see SESVerifyEmailAddressResponse
 */
-(SESVerifyEmailAddressResponse *)verifyEmailAddress:(SESVerifyEmailAddressRequest *)verifyEmailAddressRequest;


/**
 * <p>
 * Sends an email message, with header and content specified by the client. The SendRawEmail action is useful for sending
 * multipart MIME emails. The raw text of the message must comply with Internet email standards; otherwise, the message
 * cannot be sent.
 * </p>
 * <p>
 * <b>IMPORTANT:</b> You can only send email from verified email addresses and domains. If you have not requested
 * production access to Amazon SES, you must also verify every recipient email address except for the recipients provided
 * by the Amazon SES mailbox simulator. For more information, go to the Amazon SES Developer Guide.
 * </p>
 * <p>
 * The total size of the message cannot exceed 10 MB. This includes any attachments that are part of the message.
 * </p>
 * <p>
 * Amazon SES has a limit on the total number of recipients per message: The combined number of To:, CC: and BCC: email
 * addresses cannot exceed 50. If you need to send an email message to a larger audience, you can divide your recipient
 * list into groups of 50 or fewer, and then call Amazon SES repeatedly to send the message to each group.
 * </p>
 * <p>
 * For every message that you send, the total number of recipients (To:, CC: and BCC:) is counted against your <i>sending
 * quota</i> - the maximum number of emails you can send in a 24-hour period. For information about your sending quota, go
 * to the <a href="http://docs.aws.amazon.com/ses/latest/DeveloperGuide/manage-sending-limits.html"> Amazon SES Developer
 * Guide </a> .
 * </p>
 *
 * @param sendRawEmailRequest Container for the necessary parameters to execute the SendRawEmail service method on
 *           AmazonSES.
 *
 * @return The response from the SendRawEmail service method, as returned by AmazonSES.
 *
 * @exception SESMessageRejectedException For more information see <SESMessageRejectedException>
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonSES indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see SESSendRawEmailRequest
 * @see SESSendRawEmailResponse
 */
-(SESSendRawEmailResponse *)sendRawEmail:(SESSendRawEmailRequest *)sendRawEmailRequest;


/**
 * <p>
 * Returns a list containing all of the identities (email addresses and domains) for a specific AWS Account, regardless of
 * verification status.
 * </p>
 * <p>
 * This action is throttled at one request per second.
 * </p>
 *
 * @param listIdentitiesRequest Container for the necessary parameters to execute the ListIdentities service method on
 *           AmazonSES.
 *
 * @return The response from the ListIdentities service method, as returned by AmazonSES.
 *
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonSES indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see SESListIdentitiesRequest
 * @see SESListIdentitiesResponse
 */
-(SESListIdentitiesResponse *)listIdentities:(SESListIdentitiesRequest *)listIdentitiesRequest;


/**
 * <p>
 * Given a list of identities (email addresses and/or domains), returns the verification status and (for domain identities)
 * the verification token for each identity.
 * </p>
 * <p>
 * This action is throttled at one request per second.
 * </p>
 *
 * @param getIdentityVerificationAttributesRequest Container for the necessary parameters to execute the
 *           GetIdentityVerificationAttributes service method on AmazonSES.
 *
 * @return The response from the GetIdentityVerificationAttributes service method, as returned by AmazonSES.
 *
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonSES indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see SESGetIdentityVerificationAttributesRequest
 * @see SESGetIdentityVerificationAttributesResponse
 */
-(SESGetIdentityVerificationAttributesResponse *)getIdentityVerificationAttributes:(SESGetIdentityVerificationAttributesRequest *)getIdentityVerificationAttributesRequest;


/**
 * <p>
 * Enables or disables Easy DKIM signing of email sent from an identity:
 * </p>
 *
 * <ul>
 * <li>If Easy DKIM signing is enabled for a domain name identity (e.g., example.com ), then Amazon SES will DKIM-sign all
 * email sent by addresses under that domain name (e.g., user@example.com ).</li>
 * <li>If Easy DKIM signing is enabled for an email address, then Amazon SES will DKIM-sign all email sent by that email
 * address.</li>
 *
 * </ul>
 * <p>
 * For email addresses (e.g., user@example.com ), you can only enable Easy DKIM signing if the corresponding domain (e.g.,
 * example.com ) has been set up for Easy DKIM using the AWS Console or the VerifyDomainDkim action.
 * </p>
 * <p>
 * This action is throttled at one request per second.
 * </p>
 * <p>
 * For more information about Easy DKIM signing, go to the <a
 * href="http://docs.aws.amazon.com/ses/latest/DeveloperGuide/easy-dkim.html"> Amazon SES Developer Guide </a> .
 * </p>
 *
 * @param setIdentityDkimEnabledRequest Container for the necessary parameters to execute the SetIdentityDkimEnabled
 *           service method on AmazonSES.
 *
 * @return The response from the SetIdentityDkimEnabled service method, as returned by AmazonSES.
 *
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonSES indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see SESSetIdentityDkimEnabledRequest
 * @see SESSetIdentityDkimEnabledResponse
 */
-(SESSetIdentityDkimEnabledResponse *)setIdentityDkimEnabled:(SESSetIdentityDkimEnabledRequest *)setIdentityDkimEnabledRequest;


/**
 * <p>
 * Returns the user's current sending limits.
 * </p>
 * <p>
 * This action is throttled at one request per second.
 * </p>
 *
 * @param getSendQuotaRequest Container for the necessary parameters to execute the GetSendQuota service method on
 *           AmazonSES.
 *
 * @return The response from the GetSendQuota service method, as returned by AmazonSES.
 *
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonSES indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see SESGetSendQuotaRequest
 * @see SESGetSendQuotaResponse
 */
-(SESGetSendQuotaResponse *)getSendQuota:(SESGetSendQuotaRequest *)getSendQuotaRequest;


/**
 * <p>
 * Given an identity (email address or domain), enables or disables whether Amazon SES forwards feedback notifications as
 * email. Feedback forwarding may only be disabled when both complaint and bounce topics are set.
 * </p>
 * <p>
 * This action is throttled at one request per second.
 * </p>
 * <p>
 * For more information about feedback notification, see the <a
 * href="http://docs.aws.amazon.com/ses/latest/DeveloperGuide/bounce-complaint-notifications.html"> Amazon SES Developer
 * Guide </a> .
 * </p>
 *
 * @param setIdentityFeedbackForwardingEnabledRequest Container for the necessary parameters to execute the
 *           SetIdentityFeedbackForwardingEnabled service method on AmazonSES.
 *
 * @return The response from the SetIdentityFeedbackForwardingEnabled service method, as returned by AmazonSES.
 *
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonSES indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see SESSetIdentityFeedbackForwardingEnabledRequest
 * @see SESSetIdentityFeedbackForwardingEnabledResponse
 */
-(SESSetIdentityFeedbackForwardingEnabledResponse *)setIdentityFeedbackForwardingEnabled:(SESSetIdentityFeedbackForwardingEnabledRequest *)setIdentityFeedbackForwardingEnabledRequest;


/**
 * <p>
 * Verifies a domain.
 * </p>
 * <p>
 * This action is throttled at one request per second.
 * </p>
 *
 * @param verifyDomainIdentityRequest Container for the necessary parameters to execute the VerifyDomainIdentity service
 *           method on AmazonSES.
 *
 * @return The response from the VerifyDomainIdentity service method, as returned by AmazonSES.
 *
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonSES indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see SESVerifyDomainIdentityRequest
 * @see SESVerifyDomainIdentityResponse
 */
-(SESVerifyDomainIdentityResponse *)verifyDomainIdentity:(SESVerifyDomainIdentityRequest *)verifyDomainIdentityRequest;


/**
 * <p>
 * Composes an email message based on input data, and then immediately queues the message for sending.
 * </p>
 * <p>
 * <b>IMPORTANT:</b> You can only send email from verified email addresses and domains. If you have not requested
 * production access to Amazon SES, you must also verify every recipient email address except for the recipients provided
 * by the Amazon SES mailbox simulator. For more information, go to the Amazon SES Developer Guide.
 * </p>
 * <p>
 * The total size of the message cannot exceed 10 MB.
 * </p>
 * <p>
 * Amazon SES has a limit on the total number of recipients per message: The combined number of To:, CC: and BCC: email
 * addresses cannot exceed 50. If you need to send an email message to a larger audience, you can divide your recipient
 * list into groups of 50 or fewer, and then call Amazon SES repeatedly to send the message to each group.
 * </p>
 * <p>
 * For every message that you send, the total number of recipients (To:, CC: and BCC:) is counted against your <i>sending
 * quota</i> - the maximum number of emails you can send in a 24-hour period. For information about your sending quota, go
 * to the <a href="http://docs.aws.amazon.com/ses/latest/DeveloperGuide/manage-sending-limits.html"> Amazon SES Developer
 * Guide </a> .
 * </p>
 *
 * @param sendEmailRequest Container for the necessary parameters to execute the SendEmail service method on AmazonSES.
 *
 * @return The response from the SendEmail service method, as returned by AmazonSES.
 *
 * @exception SESMessageRejectedException For more information see <SESMessageRejectedException>
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonSES indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see SESSendEmailRequest
 * @see SESSendEmailResponse
 */
-(SESSendEmailResponse *)sendEmail:(SESSendEmailRequest *)sendEmailRequest;


/**
 * <p>
 * Deletes the specified email address from the list of verified addresses.
 * </p>
 * <p>
 * <b>IMPORTANT:</b>The DeleteVerifiedEmailAddress action is deprecated as of the May 15, 2012 release of Domain
 * Verification. The DeleteIdentity action is now preferred.
 * </p>
 * <p>
 * This action is throttled at one request per second.
 * </p>
 *
 * @param deleteVerifiedEmailAddressRequest Container for the necessary parameters to execute the
 *           DeleteVerifiedEmailAddress service method on AmazonSES.
 *
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonSES indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see SESDeleteVerifiedEmailAddressRequest
 * @see SESDeleteVerifiedEmailAddressResponse
 */
-(SESDeleteVerifiedEmailAddressResponse *)deleteVerifiedEmailAddress:(SESDeleteVerifiedEmailAddressRequest *)deleteVerifiedEmailAddressRequest;


/**
 * <p>
 * Given an identity (email address or domain), sets the Amazon SNS topic to which Amazon SES will publish bounce and
 * complaint notifications for emails sent with that identity as the Source .
 * Publishing to topics may only be disabled when feedback forwarding is enabled.
 * </p>
 * <p>
 * This action is throttled at one request per second.
 * </p>
 * <p>
 * For more information about feedback notification, see the <a
 * href="http://docs.aws.amazon.com/ses/latest/DeveloperGuide/bounce-complaint-notifications.html"> Amazon SES Developer
 * Guide </a> .
 * </p>
 *
 * @param setIdentityNotificationTopicRequest Container for the necessary parameters to execute the
 *           SetIdentityNotificationTopic service method on AmazonSES.
 *
 * @return The response from the SetIdentityNotificationTopic service method, as returned by AmazonSES.
 *
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonSES indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see SESSetIdentityNotificationTopicRequest
 * @see SESSetIdentityNotificationTopicResponse
 */
-(SESSetIdentityNotificationTopicResponse *)setIdentityNotificationTopic:(SESSetIdentityNotificationTopicRequest *)setIdentityNotificationTopicRequest;



@end

