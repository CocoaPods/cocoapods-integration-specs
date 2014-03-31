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
#import "ElasticLoadBalancingDescribeLoadBalancerPolicyTypesResponse.h"
#import "ElasticLoadBalancingDescribeLoadBalancerPolicyTypesRequest.h"
#import "ElasticLoadBalancingConfigureHealthCheckResponse.h"
#import "ElasticLoadBalancingConfigureHealthCheckRequest.h"
#import "ElasticLoadBalancingDetachLoadBalancerFromSubnetsResponse.h"
#import "ElasticLoadBalancingDetachLoadBalancerFromSubnetsRequest.h"
#import "ElasticLoadBalancingModifyLoadBalancerAttributesResponse.h"
#import "ElasticLoadBalancingModifyLoadBalancerAttributesRequest.h"
#import "ElasticLoadBalancingCreateLoadBalancerListenersResponse.h"
#import "ElasticLoadBalancingCreateLoadBalancerListenersRequest.h"
#import "ElasticLoadBalancingDeleteLoadBalancerListenersResponse.h"
#import "ElasticLoadBalancingDeleteLoadBalancerListenersRequest.h"
#import "ElasticLoadBalancingCreateAppCookieStickinessPolicyResponse.h"
#import "ElasticLoadBalancingCreateAppCookieStickinessPolicyRequest.h"
#import "ElasticLoadBalancingApplySecurityGroupsToLoadBalancerResponse.h"
#import "ElasticLoadBalancingApplySecurityGroupsToLoadBalancerRequest.h"
#import "ElasticLoadBalancingDescribeLoadBalancerPoliciesResponse.h"
#import "ElasticLoadBalancingDescribeLoadBalancerPoliciesRequest.h"
#import "ElasticLoadBalancingSetLoadBalancerPoliciesOfListenerResponse.h"
#import "ElasticLoadBalancingSetLoadBalancerPoliciesOfListenerRequest.h"
#import "ElasticLoadBalancingDisableAvailabilityZonesForLoadBalancerResponse.h"
#import "ElasticLoadBalancingDisableAvailabilityZonesForLoadBalancerRequest.h"
#import "ElasticLoadBalancingDescribeInstanceHealthResponse.h"
#import "ElasticLoadBalancingDescribeInstanceHealthRequest.h"
#import "ElasticLoadBalancingDeleteLoadBalancerPolicyResponse.h"
#import "ElasticLoadBalancingDeleteLoadBalancerPolicyRequest.h"
#import "ElasticLoadBalancingCreateLoadBalancerPolicyResponse.h"
#import "ElasticLoadBalancingCreateLoadBalancerPolicyRequest.h"
#import "ElasticLoadBalancingEnableAvailabilityZonesForLoadBalancerResponse.h"
#import "ElasticLoadBalancingEnableAvailabilityZonesForLoadBalancerRequest.h"
#import "ElasticLoadBalancingDeleteLoadBalancerResponse.h"
#import "ElasticLoadBalancingDeleteLoadBalancerRequest.h"
#import "ElasticLoadBalancingCreateLoadBalancerResponse.h"
#import "ElasticLoadBalancingCreateLoadBalancerRequest.h"
#import "ElasticLoadBalancingSetLoadBalancerPoliciesForBackendServerResponse.h"
#import "ElasticLoadBalancingSetLoadBalancerPoliciesForBackendServerRequest.h"
#import "ElasticLoadBalancingDeregisterInstancesFromLoadBalancerResponse.h"
#import "ElasticLoadBalancingDeregisterInstancesFromLoadBalancerRequest.h"
#import "ElasticLoadBalancingSetLoadBalancerListenerSSLCertificateResponse.h"
#import "ElasticLoadBalancingSetLoadBalancerListenerSSLCertificateRequest.h"
#import "ElasticLoadBalancingDescribeLoadBalancerAttributesResponse.h"
#import "ElasticLoadBalancingDescribeLoadBalancerAttributesRequest.h"
#import "ElasticLoadBalancingCreateLBCookieStickinessPolicyResponse.h"
#import "ElasticLoadBalancingCreateLBCookieStickinessPolicyRequest.h"
#import "ElasticLoadBalancingAttachLoadBalancerToSubnetsResponse.h"
#import "ElasticLoadBalancingAttachLoadBalancerToSubnetsRequest.h"
#import "ElasticLoadBalancingRegisterInstancesWithLoadBalancerResponse.h"
#import "ElasticLoadBalancingRegisterInstancesWithLoadBalancerRequest.h"
#import "ElasticLoadBalancingDescribeLoadBalancersResponse.h"
#import "ElasticLoadBalancingDescribeLoadBalancersRequest.h"

#ifdef AWS_MULTI_FRAMEWORK
#import <AWSRuntime/AmazonWebServiceClient.h>
#else
#import "../AmazonWebServiceClient.h"
#endif

/** \defgroup ElasticLoadBalancing Elastic Load Balancing */

/** <summary>
 * Interface for accessing AmazonElasticLoadBalancing.
 *
 *  Elastic Load Balancing <p>
 * Elastic Load Balancing is a cost-effective and easy to use web service to help you improve the availability and scalability of your application running on Amazon Elastic Cloud Compute (Amazon EC2).
 * It makes it easy for you to distribute application loads between two or more EC2 instances. Elastic Load Balancing supports the growth in traffic of your application by enabling availability through
 * redundancy.
 * </p>
 * <p>
 * This guide provides detailed information about Elastic Load Balancing actions, data types, and parameters that can be used for sending a query request. Query requests are HTTP or HTTPS requests that
 * use the HTTP verb GET or POST and a query parameter named Action or Operation. Action is used throughout this documentation, although Operation is supported for backward compatibility with other AWS
 * Query APIs.
 * </p>
 * <p>
 * For detailed information on constructing a query request using the actions, data types, and parameters mentioned in this guide, go to <a
 * href="http://docs.aws.amazon.com/ElasticLoadBalancing/latest/DeveloperGuide/using-query-api.html"> Using the Query API </a> in the <i>Elastic Load Balancing Developer Guide</i> .
 * </p>
 * <p>
 * For detailed information about Elastic Load Balancing features and their associated actions, go to <a href="http://docs.aws.amazon.com/ElasticLoadBalancing/latest/DeveloperGuide/UserScenarios.html">
 * Using Elastic Load Balancing </a> in the <i>Elastic Load Balancing Developer Guide</i> .
 * </p>
 * <p>
 * This reference guide is based on the current WSDL, which is available at: <a href="http://elasticloadbalancing.amazonaws.com/doc/2012-06-01/ElasticLoadBalancing.wsdl"> </a>
 * </p>
 * <p>
 * <b>Endpoints</b>
 * </p>
 * <p>
 * The examples in this guide assume that your load balancers are created in the US East (Northern Virginia) region and use us-east-1 as the endpoint.
 * </p>
 * <p>
 * You can create your load balancers in other AWS regions. For information about regions and endpoints supported by Elastic Load Balancing, see <a
 * href="http://docs.aws.amazon.com/general/latest/gr/index.html?rande.html"> Regions and Endpoints </a> in the Amazon Web Services General Reference.
 * </p>
 * </summary>
 *
 * See our blog to learn more about Managing Credentials in Mobile Applications.
 * @see http://mobile.awsblog.com/post/Tx31X75XISXHRH8/Managing-Credentials-in-Mobile-Applications
 */
@interface AmazonElasticLoadBalancingClient:AmazonWebServiceClient
{
}


/**
 * <p>
 * Returns meta-information on the specified load balancer policies defined by the Elastic Load Balancing service. The
 * policy types that are returned from this action can be used in a CreateLoadBalancerPolicy action to instantiate specific
 * policy configurations that will be applied to a load balancer.
 * </p>
 *
 * @param describeLoadBalancerPolicyTypesRequest Container for the necessary parameters to execute the
 *           DescribeLoadBalancerPolicyTypes service method on AmazonElasticLoadBalancing.
 *
 * @return The response from the DescribeLoadBalancerPolicyTypes service method, as returned by AmazonElasticLoadBalancing.
 *
 * @exception ElasticLoadBalancingPolicyTypeNotFoundException For more information see <ElasticLoadBalancingPolicyTypeNotFoundException>
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonElasticLoadBalancing indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see ElasticLoadBalancingDescribeLoadBalancerPolicyTypesRequest
 * @see ElasticLoadBalancingDescribeLoadBalancerPolicyTypesResponse
 */
-(ElasticLoadBalancingDescribeLoadBalancerPolicyTypesResponse *)describeLoadBalancerPolicyTypes:(ElasticLoadBalancingDescribeLoadBalancerPolicyTypesRequest *)describeLoadBalancerPolicyTypesRequest;


/**
 * <p>
 * Specifies the health check settings to use for evaluating the health state of your back-end instances.
 * </p>
 * <p>
 * For more information, see <a
 * href="http://docs.aws.amazon.com/ElasticLoadBalancing/latest/DeveloperGuide/TerminologyandKeyConcepts.html#healthcheck">
 * Health Check </a> in the <i>Elastic Load Balancing Developer Guide</i> .
 * </p>
 *
 * @param configureHealthCheckRequest Container for the necessary parameters to execute the ConfigureHealthCheck service
 *           method on AmazonElasticLoadBalancing.
 *
 * @return The response from the ConfigureHealthCheck service method, as returned by AmazonElasticLoadBalancing.
 *
 * @exception ElasticLoadBalancingLoadBalancerNotFoundException For more information see <ElasticLoadBalancingLoadBalancerNotFoundException>
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonElasticLoadBalancing indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see ElasticLoadBalancingConfigureHealthCheckRequest
 * @see ElasticLoadBalancingConfigureHealthCheckResponse
 */
-(ElasticLoadBalancingConfigureHealthCheckResponse *)configureHealthCheck:(ElasticLoadBalancingConfigureHealthCheckRequest *)configureHealthCheckRequest;


/**
 * <p>
 * Removes subnets from the set of configured subnets in the Amazon Virtual Private Cloud (Amazon VPC) for the load
 * balancer.
 * </p>
 * <p>
 * After a subnet is removed all of the EC2 instances registered with the load balancer that are in the removed subnet
 * will go into the <i>OutOfService</i> state. When a subnet is removed, the load balancer will balance the traffic among
 * the remaining routable subnets for the load balancer.
 * </p>
 *
 * @param detachLoadBalancerFromSubnetsRequest Container for the necessary parameters to execute the
 *           DetachLoadBalancerFromSubnets service method on AmazonElasticLoadBalancing.
 *
 * @return The response from the DetachLoadBalancerFromSubnets service method, as returned by AmazonElasticLoadBalancing.
 *
 * @exception ElasticLoadBalancingInvalidConfigurationRequestException For more information see <ElasticLoadBalancingInvalidConfigurationRequestException>
 * @exception ElasticLoadBalancingLoadBalancerNotFoundException For more information see <ElasticLoadBalancingLoadBalancerNotFoundException>
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonElasticLoadBalancing indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see ElasticLoadBalancingDetachLoadBalancerFromSubnetsRequest
 * @see ElasticLoadBalancingDetachLoadBalancerFromSubnetsResponse
 */
-(ElasticLoadBalancingDetachLoadBalancerFromSubnetsResponse *)detachLoadBalancerFromSubnets:(ElasticLoadBalancingDetachLoadBalancerFromSubnetsRequest *)detachLoadBalancerFromSubnetsRequest;


/**
 * <p>
 * Modifies the attributes of a specified load balancer.
 * </p>
 *
 * @param modifyLoadBalancerAttributesRequest Container for the necessary parameters to execute the
 *           ModifyLoadBalancerAttributes service method on AmazonElasticLoadBalancing.
 *
 * @return The response from the ModifyLoadBalancerAttributes service method, as returned by AmazonElasticLoadBalancing.
 *
 * @exception ElasticLoadBalancingInvalidConfigurationRequestException For more information see <ElasticLoadBalancingInvalidConfigurationRequestException>
 * @exception ElasticLoadBalancingLoadBalancerAttributeNotFoundException For more information see <ElasticLoadBalancingLoadBalancerAttributeNotFoundException>
 * @exception ElasticLoadBalancingLoadBalancerNotFoundException For more information see <ElasticLoadBalancingLoadBalancerNotFoundException>
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonElasticLoadBalancing indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see ElasticLoadBalancingModifyLoadBalancerAttributesRequest
 * @see ElasticLoadBalancingModifyLoadBalancerAttributesResponse
 */
-(ElasticLoadBalancingModifyLoadBalancerAttributesResponse *)modifyLoadBalancerAttributes:(ElasticLoadBalancingModifyLoadBalancerAttributesRequest *)modifyLoadBalancerAttributesRequest;


/**
 * <p>
 * Creates one or more listeners on a load balancer for the specified port. If a listener with the given port does not
 * already exist, it will be created; otherwise, the properties of the new listener must match the properties of the
 * existing listener.
 * </p>
 * <p>
 * For more information, see <a
 * href="http://docs.aws.amazon.com/ElasticLoadBalancing/latest/DeveloperGuide/us-add-listener.html"> Add a Listener to
 * Your Load Balancer </a> in the <i>Elastic Load Balancing Developer Guide</i> .
 * </p>
 *
 * @param createLoadBalancerListenersRequest Container for the necessary parameters to execute the
 *           CreateLoadBalancerListeners service method on AmazonElasticLoadBalancing.
 *
 * @exception ElasticLoadBalancingInvalidConfigurationRequestException For more information see <ElasticLoadBalancingInvalidConfigurationRequestException>
 * @exception ElasticLoadBalancingDuplicateListenerException For more information see <ElasticLoadBalancingDuplicateListenerException>
 * @exception ElasticLoadBalancingCertificateNotFoundException For more information see <ElasticLoadBalancingCertificateNotFoundException>
 * @exception ElasticLoadBalancingLoadBalancerNotFoundException For more information see <ElasticLoadBalancingLoadBalancerNotFoundException>
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonElasticLoadBalancing indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see ElasticLoadBalancingCreateLoadBalancerListenersRequest
 * @see ElasticLoadBalancingCreateLoadBalancerListenersResponse
 */
-(ElasticLoadBalancingCreateLoadBalancerListenersResponse *)createLoadBalancerListeners:(ElasticLoadBalancingCreateLoadBalancerListenersRequest *)createLoadBalancerListenersRequest;


/**
 * <p>
 * Deletes listeners from the load balancer for the specified port.
 * </p>
 *
 * @param deleteLoadBalancerListenersRequest Container for the necessary parameters to execute the
 *           DeleteLoadBalancerListeners service method on AmazonElasticLoadBalancing.
 *
 * @exception ElasticLoadBalancingLoadBalancerNotFoundException For more information see <ElasticLoadBalancingLoadBalancerNotFoundException>
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonElasticLoadBalancing indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see ElasticLoadBalancingDeleteLoadBalancerListenersRequest
 * @see ElasticLoadBalancingDeleteLoadBalancerListenersResponse
 */
-(ElasticLoadBalancingDeleteLoadBalancerListenersResponse *)deleteLoadBalancerListeners:(ElasticLoadBalancingDeleteLoadBalancerListenersRequest *)deleteLoadBalancerListenersRequest;


/**
 * <p>
 * Generates a stickiness policy with sticky session lifetimes that follow that of an application-generated cookie. This
 * policy can be associated only with HTTP/HTTPS listeners.
 * </p>
 * <p>
 * This policy is similar to the policy created by CreateLBCookieStickinessPolicy, except that the lifetime of the special
 * Elastic Load Balancing cookie follows the lifetime of the application-generated cookie specified in the policy
 * configuration. The load balancer only inserts a new stickiness cookie when the application response includes a new
 * application cookie.
 * </p>
 * <p>
 * If the application cookie is explicitly removed or expires, the session stops being sticky until a new application
 * cookie is issued.
 * </p>
 * <p>
 * <b>NOTE:</b> An application client must receive and send two cookies: the application-generated cookie and the special
 * Elastic Load Balancing cookie named AWSELB. This is the default behavior for many common web browsers.
 * </p>
 * <p>
 * For more information, see <a
 * ocs.aws.amazon.com/ElasticLoadBalancing/latest/DeveloperGuide/US_StickySessions.html#US_EnableStickySessionsAppCookies">
 * Enabling Application-Controlled Session Stickiness </a> in the <i>Elastic Load Balancing Developer Guide</i> .
 * </p>
 *
 * @param createAppCookieStickinessPolicyRequest Container for the necessary parameters to execute the
 *           CreateAppCookieStickinessPolicy service method on AmazonElasticLoadBalancing.
 *
 * @return The response from the CreateAppCookieStickinessPolicy service method, as returned by AmazonElasticLoadBalancing.
 *
 * @exception ElasticLoadBalancingInvalidConfigurationRequestException For more information see <ElasticLoadBalancingInvalidConfigurationRequestException>
 * @exception ElasticLoadBalancingDuplicatePolicyNameException For more information see <ElasticLoadBalancingDuplicatePolicyNameException>
 * @exception ElasticLoadBalancingTooManyPoliciesException For more information see <ElasticLoadBalancingTooManyPoliciesException>
 * @exception ElasticLoadBalancingLoadBalancerNotFoundException For more information see <ElasticLoadBalancingLoadBalancerNotFoundException>
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonElasticLoadBalancing indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see ElasticLoadBalancingCreateAppCookieStickinessPolicyRequest
 * @see ElasticLoadBalancingCreateAppCookieStickinessPolicyResponse
 */
-(ElasticLoadBalancingCreateAppCookieStickinessPolicyResponse *)createAppCookieStickinessPolicy:(ElasticLoadBalancingCreateAppCookieStickinessPolicyRequest *)createAppCookieStickinessPolicyRequest;


/**
 * <p>
 * Associates one or more security groups with your load balancer in Amazon Virtual Private Cloud (Amazon VPC). The
 * provided security group IDs will override any currently applied security groups.
 * </p>
 * <p>
 * For more information, see <a
 * href="http://docs.aws.amazon.com/ElasticLoadBalancing/latest/DeveloperGuide/USVPC_ApplySG.html"> Manage Security Groups
 * in Amazon VPC </a> in the <i>Elastic Load Balancing Developer Guide</i> .
 * </p>
 *
 * @param applySecurityGroupsToLoadBalancerRequest Container for the necessary parameters to execute the
 *           ApplySecurityGroupsToLoadBalancer service method on AmazonElasticLoadBalancing.
 *
 * @return The response from the ApplySecurityGroupsToLoadBalancer service method, as returned by
 *         AmazonElasticLoadBalancing.
 *
 * @exception ElasticLoadBalancingInvalidConfigurationRequestException For more information see <ElasticLoadBalancingInvalidConfigurationRequestException>
 * @exception ElasticLoadBalancingInvalidSecurityGroupException For more information see <ElasticLoadBalancingInvalidSecurityGroupException>
 * @exception ElasticLoadBalancingLoadBalancerNotFoundException For more information see <ElasticLoadBalancingLoadBalancerNotFoundException>
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonElasticLoadBalancing indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see ElasticLoadBalancingApplySecurityGroupsToLoadBalancerRequest
 * @see ElasticLoadBalancingApplySecurityGroupsToLoadBalancerResponse
 */
-(ElasticLoadBalancingApplySecurityGroupsToLoadBalancerResponse *)applySecurityGroupsToLoadBalancer:(ElasticLoadBalancingApplySecurityGroupsToLoadBalancerRequest *)applySecurityGroupsToLoadBalancerRequest;


/**
 * <p>
 * Returns detailed descriptions of the policies. If you specify a load balancer name, the action returns the descriptions
 * of all the policies created for the load balancer. If you specify a policy name associated with your load balancer, the
 * action returns the description of that policy. If you don't specify a load balancer name, the action returns
 * descriptions of the specified sample policies, or descriptions of all the sample policies. The names of the sample
 * policies have the ELBSample- prefix.
 * </p>
 *
 * @param describeLoadBalancerPoliciesRequest Container for the necessary parameters to execute the
 *           DescribeLoadBalancerPolicies service method on AmazonElasticLoadBalancing.
 *
 * @return The response from the DescribeLoadBalancerPolicies service method, as returned by AmazonElasticLoadBalancing.
 *
 * @exception ElasticLoadBalancingPolicyNotFoundException For more information see <ElasticLoadBalancingPolicyNotFoundException>
 * @exception ElasticLoadBalancingLoadBalancerNotFoundException For more information see <ElasticLoadBalancingLoadBalancerNotFoundException>
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonElasticLoadBalancing indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see ElasticLoadBalancingDescribeLoadBalancerPoliciesRequest
 * @see ElasticLoadBalancingDescribeLoadBalancerPoliciesResponse
 */
-(ElasticLoadBalancingDescribeLoadBalancerPoliciesResponse *)describeLoadBalancerPolicies:(ElasticLoadBalancingDescribeLoadBalancerPoliciesRequest *)describeLoadBalancerPoliciesRequest;


/**
 * <p>
 * Associates, updates, or disables a policy with a listener on the load balancer. You can associate multiple policies
 * with a listener.
 * </p>
 *
 * @param setLoadBalancerPoliciesOfListenerRequest Container for the necessary parameters to execute the
 *           SetLoadBalancerPoliciesOfListener service method on AmazonElasticLoadBalancing.
 *
 * @return The response from the SetLoadBalancerPoliciesOfListener service method, as returned by
 *         AmazonElasticLoadBalancing.
 *
 * @exception ElasticLoadBalancingPolicyNotFoundException For more information see <ElasticLoadBalancingPolicyNotFoundException>
 * @exception ElasticLoadBalancingInvalidConfigurationRequestException For more information see <ElasticLoadBalancingInvalidConfigurationRequestException>
 * @exception ElasticLoadBalancingLoadBalancerNotFoundException For more information see <ElasticLoadBalancingLoadBalancerNotFoundException>
 * @exception ElasticLoadBalancingListenerNotFoundException For more information see <ElasticLoadBalancingListenerNotFoundException>
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonElasticLoadBalancing indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see ElasticLoadBalancingSetLoadBalancerPoliciesOfListenerRequest
 * @see ElasticLoadBalancingSetLoadBalancerPoliciesOfListenerResponse
 */
-(ElasticLoadBalancingSetLoadBalancerPoliciesOfListenerResponse *)setLoadBalancerPoliciesOfListener:(ElasticLoadBalancingSetLoadBalancerPoliciesOfListenerRequest *)setLoadBalancerPoliciesOfListenerRequest;


/**
 * <p>
 * Removes the specified EC2 Availability Zones from the set of configured Availability Zones for the load balancer.
 * </p>
 * <p>
 * There must be at least one Availability Zone registered with a load balancer at all times. Once an Availability Zone is
 * removed, all the instances registered with the load balancer that are in the removed Availability Zone go into the
 * <i>OutOfService</i> state. Upon Availability Zone removal, the load balancer attempts to equally balance the traffic
 * among its remaining usable Availability Zones. Trying to remove an Availability Zone that was not associated with the
 * load balancer does nothing.
 * </p>
 * <p>
 * For more information, see <a
 * href="http://docs.aws.amazon.com/ElasticLoadBalancing/latest/DeveloperGuide/US_ShrinkLBApp04.html"> Disable an
 * Availability Zone from a Load-Balanced Application </a> in the <i>Elastic Load Balancing Developer Guide</i> .
 * </p>
 *
 * @param disableAvailabilityZonesForLoadBalancerRequest Container for the necessary parameters to execute the
 *           DisableAvailabilityZonesForLoadBalancer service method on AmazonElasticLoadBalancing.
 *
 * @return The response from the DisableAvailabilityZonesForLoadBalancer service method, as returned by
 *         AmazonElasticLoadBalancing.
 *
 * @exception ElasticLoadBalancingInvalidConfigurationRequestException For more information see <ElasticLoadBalancingInvalidConfigurationRequestException>
 * @exception ElasticLoadBalancingLoadBalancerNotFoundException For more information see <ElasticLoadBalancingLoadBalancerNotFoundException>
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonElasticLoadBalancing indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see ElasticLoadBalancingDisableAvailabilityZonesForLoadBalancerRequest
 * @see ElasticLoadBalancingDisableAvailabilityZonesForLoadBalancerResponse
 */
-(ElasticLoadBalancingDisableAvailabilityZonesForLoadBalancerResponse *)disableAvailabilityZonesForLoadBalancer:(ElasticLoadBalancingDisableAvailabilityZonesForLoadBalancerRequest *)disableAvailabilityZonesForLoadBalancerRequest;


/**
 * <p>
 * Returns the current state of the specified instances registered with the specified load balancer. If no instances are
 * specified, the state of all the instances registered with the load balancer is returned.
 * </p>
 * <p>
 * <b>NOTE:</b> You must provide the same account credentials as those that were used to create the load balancer.
 * </p>
 *
 * @param describeInstanceHealthRequest Container for the necessary parameters to execute the DescribeInstanceHealth
 *           service method on AmazonElasticLoadBalancing.
 *
 * @return The response from the DescribeInstanceHealth service method, as returned by AmazonElasticLoadBalancing.
 *
 * @exception ElasticLoadBalancingLoadBalancerNotFoundException For more information see <ElasticLoadBalancingLoadBalancerNotFoundException>
 * @exception ElasticLoadBalancingInvalidInstanceException For more information see <ElasticLoadBalancingInvalidInstanceException>
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonElasticLoadBalancing indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see ElasticLoadBalancingDescribeInstanceHealthRequest
 * @see ElasticLoadBalancingDescribeInstanceHealthResponse
 */
-(ElasticLoadBalancingDescribeInstanceHealthResponse *)describeInstanceHealth:(ElasticLoadBalancingDescribeInstanceHealthRequest *)describeInstanceHealthRequest;


/**
 * <p>
 * Deletes a policy from the load balancer. The specified policy must not be enabled for any listeners.
 * </p>
 *
 * @param deleteLoadBalancerPolicyRequest Container for the necessary parameters to execute the DeleteLoadBalancerPolicy
 *           service method on AmazonElasticLoadBalancing.
 *
 * @return The response from the DeleteLoadBalancerPolicy service method, as returned by AmazonElasticLoadBalancing.
 *
 * @exception ElasticLoadBalancingInvalidConfigurationRequestException For more information see <ElasticLoadBalancingInvalidConfigurationRequestException>
 * @exception ElasticLoadBalancingLoadBalancerNotFoundException For more information see <ElasticLoadBalancingLoadBalancerNotFoundException>
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonElasticLoadBalancing indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see ElasticLoadBalancingDeleteLoadBalancerPolicyRequest
 * @see ElasticLoadBalancingDeleteLoadBalancerPolicyResponse
 */
-(ElasticLoadBalancingDeleteLoadBalancerPolicyResponse *)deleteLoadBalancerPolicy:(ElasticLoadBalancingDeleteLoadBalancerPolicyRequest *)deleteLoadBalancerPolicyRequest;


/**
 * <p>
 * Creates a new policy that contains the necessary attributes depending on the policy type. Policies are settings that
 * are saved for your load balancer and that can be applied to the front-end listener, or the back-end application server,
 * depending on your policy type.
 * </p>
 *
 * @param createLoadBalancerPolicyRequest Container for the necessary parameters to execute the CreateLoadBalancerPolicy
 *           service method on AmazonElasticLoadBalancing.
 *
 * @return The response from the CreateLoadBalancerPolicy service method, as returned by AmazonElasticLoadBalancing.
 *
 * @exception ElasticLoadBalancingPolicyTypeNotFoundException For more information see <ElasticLoadBalancingPolicyTypeNotFoundException>
 * @exception ElasticLoadBalancingInvalidConfigurationRequestException For more information see <ElasticLoadBalancingInvalidConfigurationRequestException>
 * @exception ElasticLoadBalancingDuplicatePolicyNameException For more information see <ElasticLoadBalancingDuplicatePolicyNameException>
 * @exception ElasticLoadBalancingTooManyPoliciesException For more information see <ElasticLoadBalancingTooManyPoliciesException>
 * @exception ElasticLoadBalancingLoadBalancerNotFoundException For more information see <ElasticLoadBalancingLoadBalancerNotFoundException>
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonElasticLoadBalancing indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see ElasticLoadBalancingCreateLoadBalancerPolicyRequest
 * @see ElasticLoadBalancingCreateLoadBalancerPolicyResponse
 */
-(ElasticLoadBalancingCreateLoadBalancerPolicyResponse *)createLoadBalancerPolicy:(ElasticLoadBalancingCreateLoadBalancerPolicyRequest *)createLoadBalancerPolicyRequest;


/**
 * <p>
 * Adds one or more EC2 Availability Zones to the load balancer.
 * </p>
 * <p>
 * The load balancer evenly distributes requests across all its registered Availability Zones that contain instances.
 * </p>
 * <p>
 * <b>NOTE:</b> The new EC2 Availability Zones to be added must be in the same EC2 Region as the Availability Zones for
 * which the load balancer was created.
 * </p>
 * <p>
 * For more information, see <a
 * href="http://docs.aws.amazon.com/ElasticLoadBalancing/latest/DeveloperGuide/US_AddLBAvailabilityZone.html"> Expand a
 * Load Balanced Application to an Additional Availability Zone </a> in the <i>Elastic Load Balancing Developer Guide</i> .
 * </p>
 *
 * @param enableAvailabilityZonesForLoadBalancerRequest Container for the necessary parameters to execute the
 *           EnableAvailabilityZonesForLoadBalancer service method on AmazonElasticLoadBalancing.
 *
 * @return The response from the EnableAvailabilityZonesForLoadBalancer service method, as returned by
 *         AmazonElasticLoadBalancing.
 *
 * @exception ElasticLoadBalancingLoadBalancerNotFoundException For more information see <ElasticLoadBalancingLoadBalancerNotFoundException>
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonElasticLoadBalancing indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see ElasticLoadBalancingEnableAvailabilityZonesForLoadBalancerRequest
 * @see ElasticLoadBalancingEnableAvailabilityZonesForLoadBalancerResponse
 */
-(ElasticLoadBalancingEnableAvailabilityZonesForLoadBalancerResponse *)enableAvailabilityZonesForLoadBalancer:(ElasticLoadBalancingEnableAvailabilityZonesForLoadBalancerRequest *)enableAvailabilityZonesForLoadBalancerRequest;


/**
 * <p>
 * Deletes the specified load balancer.
 * </p>
 * <p>
 * If attempting to recreate the load balancer, you must reconfigure all the settings. The DNS name associated with a
 * deleted load balancer will no longer be usable. Once deleted, the name and associated DNS record of the load balancer no
 * longer exist and traffic sent to any of its IP addresses will no longer be delivered to back-end instances.
 * </p>
 * <p>
 * To successfully call this API, you must provide the same account credentials as were used to create the load balancer.
 * </p>
 * <p>
 * <b>NOTE:</b> By design, if the load balancer does not exist or has already been deleted, a call to DeleteLoadBalancer
 * action still succeeds.
 * </p>
 *
 * @param deleteLoadBalancerRequest Container for the necessary parameters to execute the DeleteLoadBalancer service method
 *           on AmazonElasticLoadBalancing.
 *
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonElasticLoadBalancing indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see ElasticLoadBalancingDeleteLoadBalancerRequest
 * @see ElasticLoadBalancingDeleteLoadBalancerResponse
 */
-(ElasticLoadBalancingDeleteLoadBalancerResponse *)deleteLoadBalancer:(ElasticLoadBalancingDeleteLoadBalancerRequest *)deleteLoadBalancerRequest;


/**
 * <p>
 * Creates a new load balancer.
 * </p>
 * <p>
 * After the call has completed successfully, a new load balancer is created with a unique Domain Name Service (DNS) name.
 * The DNS name includes the name of the AWS region in which the load balance was created. For example, if your load
 * balancer was created in the United States, the DNS name might end with either of the following:
 * </p>
 *
 * <ul>
 * <li> <i>us-east-1.elb.amazonaws.com</i> (for the Northern Virginia Region) </li>
 * <li> <i>us-west-1.elb.amazonaws.com</i> (for the Northern California Region) </li>
 *
 * </ul>
 * <p>
 * For information about the AWS regions supported by Elastic Load Balancing, see <a
 * href="http://docs.aws.amazon.com/general/latest/gr/rande.html#elb_region"> Regions and Endpoints </a> .
 * </p>
 * <p>
 * You can create up to 10 load balancers per region per account.
 * </p>
 * <p>
 * Elastic Load Balancing supports load balancing your Amazon EC2 instances launched within any one of the following
 * platforms:
 * </p>
 *
 * <ul>
 * <li> <i>EC2-Classic</i> <p>
 * For information on creating and managing your load balancers in EC2-Classic, see <a
 * href="http://docs.aws.amazon.com/ElasticLoadBalancing/latest/DeveloperGuide/UserScenariosForEC2.html"> Deploy Elastic
 * Load Balancing in Amazon EC2-Classic </a> .
 * </p>
 * </li>
 * <li> <i>EC2-VPC</i> <p>
 * For information on creating and managing your load balancers in EC2-VPC, see <a
 * href="http://docs.aws.amazon.com/ElasticLoadBalancing/latest/DeveloperGuide/UserScenariosForVPC.html"> Deploy Elastic
 * Load Balancing in Amazon VPC </a> .
 * </p>
 * </li>
 *
 * </ul>
 *
 * @param createLoadBalancerRequest Container for the necessary parameters to execute the CreateLoadBalancer service method
 *           on AmazonElasticLoadBalancing.
 *
 * @return The response from the CreateLoadBalancer service method, as returned by AmazonElasticLoadBalancing.
 *
 * @exception ElasticLoadBalancingInvalidSubnetException For more information see <ElasticLoadBalancingInvalidSubnetException>
 * @exception ElasticLoadBalancingInvalidConfigurationRequestException For more information see <ElasticLoadBalancingInvalidConfigurationRequestException>
 * @exception ElasticLoadBalancingInvalidSecurityGroupException For more information see <ElasticLoadBalancingInvalidSecurityGroupException>
 * @exception ElasticLoadBalancingCertificateNotFoundException For more information see <ElasticLoadBalancingCertificateNotFoundException>
 * @exception ElasticLoadBalancingInvalidSchemeException For more information see <ElasticLoadBalancingInvalidSchemeException>
 * @exception ElasticLoadBalancingDuplicateLoadBalancerNameException For more information see <ElasticLoadBalancingDuplicateLoadBalancerNameException>
 * @exception ElasticLoadBalancingTooManyLoadBalancersException For more information see <ElasticLoadBalancingTooManyLoadBalancersException>
 * @exception ElasticLoadBalancingSubnetNotFoundException For more information see <ElasticLoadBalancingSubnetNotFoundException>
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonElasticLoadBalancing indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see ElasticLoadBalancingCreateLoadBalancerRequest
 * @see ElasticLoadBalancingCreateLoadBalancerResponse
 */
-(ElasticLoadBalancingCreateLoadBalancerResponse *)createLoadBalancer:(ElasticLoadBalancingCreateLoadBalancerRequest *)createLoadBalancerRequest;


/**
 * <p>
 * Replaces the current set of policies associated with a port on which the back-end server is listening with a new set of
 * policies. After the policies have been created using CreateLoadBalancerPolicy, they can be applied here as a list. At
 * this time, only the back-end server authentication policy type can be applied to the back-end ports; this policy type is
 * composed of multiple public key policies.
 * </p>
 * <p>
 * <b>NOTE:</b> The SetLoadBalancerPoliciesForBackendServer replaces the current set of policies associated with the
 * specified instance port. Every time you use this action to enable the policies, use the PolicyNames parameter to list
 * all the policies you want to enable.
 * </p>
 * <p>
 * You can use DescribeLoadBalancers or DescribeLoadBalancerPolicies action to verify that the policy has been associated
 * with the back-end server.
 * </p>
 *
 * @param setLoadBalancerPoliciesForBackendServerRequest Container for the necessary parameters to execute the
 *           SetLoadBalancerPoliciesForBackendServer service method on AmazonElasticLoadBalancing.
 *
 * @return The response from the SetLoadBalancerPoliciesForBackendServer service method, as returned by
 *         AmazonElasticLoadBalancing.
 *
 * @exception ElasticLoadBalancingPolicyNotFoundException For more information see <ElasticLoadBalancingPolicyNotFoundException>
 * @exception ElasticLoadBalancingInvalidConfigurationRequestException For more information see <ElasticLoadBalancingInvalidConfigurationRequestException>
 * @exception ElasticLoadBalancingLoadBalancerNotFoundException For more information see <ElasticLoadBalancingLoadBalancerNotFoundException>
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonElasticLoadBalancing indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see ElasticLoadBalancingSetLoadBalancerPoliciesForBackendServerRequest
 * @see ElasticLoadBalancingSetLoadBalancerPoliciesForBackendServerResponse
 */
-(ElasticLoadBalancingSetLoadBalancerPoliciesForBackendServerResponse *)setLoadBalancerPoliciesForBackendServer:(ElasticLoadBalancingSetLoadBalancerPoliciesForBackendServerRequest *)setLoadBalancerPoliciesForBackendServerRequest;


/**
 * <p>
 * Deregisters instances from the load balancer. Once the instance is deregistered, it will stop receiving traffic from
 * the load balancer.
 * </p>
 * <p>
 * In order to successfully call this API, the same account credentials as those used to create the load balancer must be
 * provided.
 * </p>
 * <p>
 * For more information, see <a
 * href="http://docs.aws.amazon.com/ElasticLoadBalancing/latest/DeveloperGuide/US_DeReg_Reg_Instances.html"> De-register
 * and Register Amazon EC2 Instances </a> in the <i>Elastic Load Balancing Developer Guide</i> .
 * </p>
 * <p>
 * You can use DescribeLoadBalancers to verify if the instance is deregistered from the load balancer.
 * </p>
 *
 * @param deregisterInstancesFromLoadBalancerRequest Container for the necessary parameters to execute the
 *           DeregisterInstancesFromLoadBalancer service method on AmazonElasticLoadBalancing.
 *
 * @return The response from the DeregisterInstancesFromLoadBalancer service method, as returned by
 *         AmazonElasticLoadBalancing.
 *
 * @exception ElasticLoadBalancingLoadBalancerNotFoundException For more information see <ElasticLoadBalancingLoadBalancerNotFoundException>
 * @exception ElasticLoadBalancingInvalidInstanceException For more information see <ElasticLoadBalancingInvalidInstanceException>
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonElasticLoadBalancing indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see ElasticLoadBalancingDeregisterInstancesFromLoadBalancerRequest
 * @see ElasticLoadBalancingDeregisterInstancesFromLoadBalancerResponse
 */
-(ElasticLoadBalancingDeregisterInstancesFromLoadBalancerResponse *)deregisterInstancesFromLoadBalancer:(ElasticLoadBalancingDeregisterInstancesFromLoadBalancerRequest *)deregisterInstancesFromLoadBalancerRequest;


/**
 * <p>
 * Sets the certificate that terminates the specified listener's SSL connections. The specified certificate replaces any
 * prior certificate that was used on the same load balancer and port.
 * </p>
 * <p>
 * For more information on updating your SSL certificate, see <a
 * href="http://docs.aws.amazon.com/ElasticLoadBalancing/latest/DeveloperGuide/US_UpdatingLoadBalancerSSL.html"> Updating
 * an SSL Certificate for a Load Balancer </a> in the <i>Elastic Load Balancing Developer Guide</i> .
 * </p>
 *
 * @param setLoadBalancerListenerSSLCertificateRequest Container for the necessary parameters to execute the
 *           SetLoadBalancerListenerSSLCertificate service method on AmazonElasticLoadBalancing.
 *
 * @exception ElasticLoadBalancingInvalidConfigurationRequestException For more information see <ElasticLoadBalancingInvalidConfigurationRequestException>
 * @exception ElasticLoadBalancingCertificateNotFoundException For more information see <ElasticLoadBalancingCertificateNotFoundException>
 * @exception ElasticLoadBalancingLoadBalancerNotFoundException For more information see <ElasticLoadBalancingLoadBalancerNotFoundException>
 * @exception ElasticLoadBalancingListenerNotFoundException For more information see <ElasticLoadBalancingListenerNotFoundException>
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonElasticLoadBalancing indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see ElasticLoadBalancingSetLoadBalancerListenerSSLCertificateRequest
 * @see ElasticLoadBalancingSetLoadBalancerListenerSSLCertificateResponse
 */
-(ElasticLoadBalancingSetLoadBalancerListenerSSLCertificateResponse *)setLoadBalancerListenerSSLCertificate:(ElasticLoadBalancingSetLoadBalancerListenerSSLCertificateRequest *)setLoadBalancerListenerSSLCertificateRequest;


/**
 * <p>
 * Returns detailed information about all of the attributes associated with the specified load balancer.
 * </p>
 *
 * @param describeLoadBalancerAttributesRequest Container for the necessary parameters to execute the
 *           DescribeLoadBalancerAttributes service method on AmazonElasticLoadBalancing.
 *
 * @return The response from the DescribeLoadBalancerAttributes service method, as returned by AmazonElasticLoadBalancing.
 *
 * @exception ElasticLoadBalancingLoadBalancerAttributeNotFoundException For more information see <ElasticLoadBalancingLoadBalancerAttributeNotFoundException>
 * @exception ElasticLoadBalancingLoadBalancerNotFoundException For more information see <ElasticLoadBalancingLoadBalancerNotFoundException>
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonElasticLoadBalancing indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see ElasticLoadBalancingDescribeLoadBalancerAttributesRequest
 * @see ElasticLoadBalancingDescribeLoadBalancerAttributesResponse
 */
-(ElasticLoadBalancingDescribeLoadBalancerAttributesResponse *)describeLoadBalancerAttributes:(ElasticLoadBalancingDescribeLoadBalancerAttributesRequest *)describeLoadBalancerAttributesRequest;


/**
 * <p>
 * Generates a stickiness policy with sticky session lifetimes controlled by the lifetime of the browser (user-agent) or a
 * specified expiration period. This policy can be associated only with HTTP/HTTPS listeners.
 * </p>
 * <p>
 * When a load balancer implements this policy, the load balancer uses a special cookie to track the backend server
 * instance for each request. When the load balancer receives a request, it first checks to see if this cookie is present
 * in the request. If so, the load balancer sends the request to the application server specified in the cookie. If not,
 * the load balancer sends the request to a server that is chosen based on the existing load balancing algorithm.
 * </p>
 * <p>
 * A cookie is inserted into the response for binding subsequent requests from the same user to that server. The validity
 * of the cookie is based on the cookie expiration time, which is specified in the policy configuration.
 * </p>
 * <p>
 * For more information, see <a
 * docs.aws.amazon.com/ElasticLoadBalancing/latest/DeveloperGuide/US_StickySessions.html#US_EnableStickySessionsLBCookies">
 * Enabling Duration-Based Session Stickiness </a> in the <i>Elastic Load Balancing Developer Guide</i> .
 * </p>
 *
 * @param createLBCookieStickinessPolicyRequest Container for the necessary parameters to execute the
 *           CreateLBCookieStickinessPolicy service method on AmazonElasticLoadBalancing.
 *
 * @return The response from the CreateLBCookieStickinessPolicy service method, as returned by AmazonElasticLoadBalancing.
 *
 * @exception ElasticLoadBalancingInvalidConfigurationRequestException For more information see <ElasticLoadBalancingInvalidConfigurationRequestException>
 * @exception ElasticLoadBalancingDuplicatePolicyNameException For more information see <ElasticLoadBalancingDuplicatePolicyNameException>
 * @exception ElasticLoadBalancingTooManyPoliciesException For more information see <ElasticLoadBalancingTooManyPoliciesException>
 * @exception ElasticLoadBalancingLoadBalancerNotFoundException For more information see <ElasticLoadBalancingLoadBalancerNotFoundException>
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonElasticLoadBalancing indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see ElasticLoadBalancingCreateLBCookieStickinessPolicyRequest
 * @see ElasticLoadBalancingCreateLBCookieStickinessPolicyResponse
 */
-(ElasticLoadBalancingCreateLBCookieStickinessPolicyResponse *)createLBCookieStickinessPolicy:(ElasticLoadBalancingCreateLBCookieStickinessPolicyRequest *)createLBCookieStickinessPolicyRequest;


/**
 * <p>
 * Adds one or more subnets to the set of configured subnets in the Amazon Virtual Private Cloud (Amazon VPC) for the load
 * balancer.
 * </p>
 * <p>
 * The load balancers evenly distribute requests across all of the registered subnets. For more information, see <a
 * href="http://docs.aws.amazon.com/ElasticLoadBalancing/latest/DeveloperGuide/UserScenariosForVPC.html"> Deploy Elastic
 * Load Balancing in Amazon VPC </a> in the <i>Elastic Load Balancing Developer Guide</i> .
 *
 * </p>
 *
 * @param attachLoadBalancerToSubnetsRequest Container for the necessary parameters to execute the
 *           AttachLoadBalancerToSubnets service method on AmazonElasticLoadBalancing.
 *
 * @return The response from the AttachLoadBalancerToSubnets service method, as returned by AmazonElasticLoadBalancing.
 *
 * @exception ElasticLoadBalancingInvalidSubnetException For more information see <ElasticLoadBalancingInvalidSubnetException>
 * @exception ElasticLoadBalancingInvalidConfigurationRequestException For more information see <ElasticLoadBalancingInvalidConfigurationRequestException>
 * @exception ElasticLoadBalancingLoadBalancerNotFoundException For more information see <ElasticLoadBalancingLoadBalancerNotFoundException>
 * @exception ElasticLoadBalancingSubnetNotFoundException For more information see <ElasticLoadBalancingSubnetNotFoundException>
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonElasticLoadBalancing indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see ElasticLoadBalancingAttachLoadBalancerToSubnetsRequest
 * @see ElasticLoadBalancingAttachLoadBalancerToSubnetsResponse
 */
-(ElasticLoadBalancingAttachLoadBalancerToSubnetsResponse *)attachLoadBalancerToSubnets:(ElasticLoadBalancingAttachLoadBalancerToSubnetsRequest *)attachLoadBalancerToSubnetsRequest;


/**
 * <p>
 * Adds new instances to the load balancer.
 * </p>
 * <p>
 * Once the instance is registered, it starts receiving traffic and requests from the load balancer. Any instance that is
 * not in any of the Availability Zones registered for the load balancer will be moved to the <i>OutOfService</i> state. It
 * will move to the <i>InService</i> state when the Availability Zone is added to the load balancer.
 * </p>
 * <p>
 * When an instance registered with a load balancer is stopped and then restarted, the IP addresses associated with the
 * instance changes. Elastic Load Balancing cannot recognize the new IP address, which prevents it from routing traffic to
 * the instances. We recommend that you de-register your Amazon EC2 instances from your load balancer after you stop your
 * instance, and then register the load balancer with your instance after you've restarted. To de-register your instances
 * from load balancer, use DeregisterInstancesFromLoadBalancer action.
 * </p>
 * <p>
 * For more information, see <a
 * href="http://docs.aws.amazon.com/ElasticLoadBalancing/latest/DeveloperGuide/US_DeReg_Reg_Instances.html"> De-register
 * and Register Amazon EC2 Instances </a> in the <i>Elastic Load Balancing Developer Guide</i> .
 * </p>
 * <p>
 * <b>NOTE:</b> In order for this call to be successful, you must provide the same account credentials as those that were
 * used to create the load balancer.
 * </p>
 * <p>
 * <b>NOTE:</b> Completion of this API does not guarantee that operation has completed. Rather, it means that the request
 * has been registered and the changes will happen shortly.
 * </p>
 * <p>
 * You can use DescribeLoadBalancers or DescribeInstanceHealth action to check the state of the newly registered instances.
 * </p>
 *
 * @param registerInstancesWithLoadBalancerRequest Container for the necessary parameters to execute the
 *           RegisterInstancesWithLoadBalancer service method on AmazonElasticLoadBalancing.
 *
 * @return The response from the RegisterInstancesWithLoadBalancer service method, as returned by
 *         AmazonElasticLoadBalancing.
 *
 * @exception ElasticLoadBalancingLoadBalancerNotFoundException For more information see <ElasticLoadBalancingLoadBalancerNotFoundException>
 * @exception ElasticLoadBalancingInvalidInstanceException For more information see <ElasticLoadBalancingInvalidInstanceException>
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonElasticLoadBalancing indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see ElasticLoadBalancingRegisterInstancesWithLoadBalancerRequest
 * @see ElasticLoadBalancingRegisterInstancesWithLoadBalancerResponse
 */
-(ElasticLoadBalancingRegisterInstancesWithLoadBalancerResponse *)registerInstancesWithLoadBalancer:(ElasticLoadBalancingRegisterInstancesWithLoadBalancerRequest *)registerInstancesWithLoadBalancerRequest;


/**
 * <p>
 * Returns detailed configuration information for all the load balancers created for the account. If you specify load
 * balancer names, the action returns configuration information of the specified load balancers.
 * </p>
 * <p>
 * <b>NOTE:</b> In order to retrieve this information, you must provide the same account credentials that was used to
 * create the load balancer.
 * </p>
 *
 * @param describeLoadBalancersRequest Container for the necessary parameters to execute the DescribeLoadBalancers service
 *           method on AmazonElasticLoadBalancing.
 *
 * @return The response from the DescribeLoadBalancers service method, as returned by AmazonElasticLoadBalancing.
 *
 * @exception ElasticLoadBalancingLoadBalancerNotFoundException For more information see <ElasticLoadBalancingLoadBalancerNotFoundException>
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonElasticLoadBalancing indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see ElasticLoadBalancingDescribeLoadBalancersRequest
 * @see ElasticLoadBalancingDescribeLoadBalancersResponse
 */
-(ElasticLoadBalancingDescribeLoadBalancersResponse *)describeLoadBalancers:(ElasticLoadBalancingDescribeLoadBalancersRequest *)describeLoadBalancersRequest;



@end

