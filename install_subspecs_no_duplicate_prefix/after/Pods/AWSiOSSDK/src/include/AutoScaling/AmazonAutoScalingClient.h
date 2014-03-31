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
#import "AutoScalingDescribeAutoScalingGroupsResponse.h"
#import "AutoScalingDescribeAutoScalingGroupsRequest.h"
#import "AutoScalingEnableMetricsCollectionResponse.h"
#import "AutoScalingEnableMetricsCollectionRequest.h"
#import "AutoScalingResumeProcessesResponse.h"
#import "AutoScalingResumeProcessesRequest.h"
#import "AutoScalingDeleteLaunchConfigurationResponse.h"
#import "AutoScalingDeleteLaunchConfigurationRequest.h"
#import "AutoScalingDescribePoliciesResponse.h"
#import "AutoScalingDescribePoliciesRequest.h"
#import "AutoScalingDescribeScalingProcessTypesResponse.h"
#import "AutoScalingDescribeScalingProcessTypesRequest.h"
#import "AutoScalingCreateAutoScalingGroupResponse.h"
#import "AutoScalingCreateAutoScalingGroupRequest.h"
#import "AutoScalingDescribeScalingActivitiesResponse.h"
#import "AutoScalingDescribeScalingActivitiesRequest.h"
#import "AutoScalingDescribeNotificationConfigurationsResponse.h"
#import "AutoScalingDescribeNotificationConfigurationsRequest.h"
#import "AutoScalingDescribeTerminationPolicyTypesResponse.h"
#import "AutoScalingDescribeTerminationPolicyTypesRequest.h"
#import "AutoScalingDescribeTagsResponse.h"
#import "AutoScalingDescribeTagsRequest.h"
#import "AutoScalingExecutePolicyResponse.h"
#import "AutoScalingExecutePolicyRequest.h"
#import "AutoScalingDeleteTagsResponse.h"
#import "AutoScalingDeleteTagsRequest.h"
#import "AutoScalingPutScalingPolicyResponse.h"
#import "AutoScalingPutScalingPolicyRequest.h"
#import "AutoScalingPutNotificationConfigurationResponse.h"
#import "AutoScalingPutNotificationConfigurationRequest.h"
#import "AutoScalingDeletePolicyResponse.h"
#import "AutoScalingDeletePolicyRequest.h"
#import "AutoScalingDeleteNotificationConfigurationResponse.h"
#import "AutoScalingDeleteNotificationConfigurationRequest.h"
#import "AutoScalingDeleteScheduledActionResponse.h"
#import "AutoScalingDeleteScheduledActionRequest.h"
#import "AutoScalingSetInstanceHealthResponse.h"
#import "AutoScalingSetInstanceHealthRequest.h"
#import "AutoScalingDescribeAutoScalingNotificationTypesResponse.h"
#import "AutoScalingDescribeAutoScalingNotificationTypesRequest.h"
#import "AutoScalingCreateOrUpdateTagsResponse.h"
#import "AutoScalingCreateOrUpdateTagsRequest.h"
#import "AutoScalingSuspendProcessesResponse.h"
#import "AutoScalingSuspendProcessesRequest.h"
#import "AutoScalingDescribeAutoScalingInstancesResponse.h"
#import "AutoScalingDescribeAutoScalingInstancesRequest.h"
#import "AutoScalingCreateLaunchConfigurationResponse.h"
#import "AutoScalingCreateLaunchConfigurationRequest.h"
#import "AutoScalingDeleteAutoScalingGroupResponse.h"
#import "AutoScalingDeleteAutoScalingGroupRequest.h"
#import "AutoScalingDisableMetricsCollectionResponse.h"
#import "AutoScalingDisableMetricsCollectionRequest.h"
#import "AutoScalingUpdateAutoScalingGroupResponse.h"
#import "AutoScalingUpdateAutoScalingGroupRequest.h"
#import "AutoScalingDescribeLaunchConfigurationsResponse.h"
#import "AutoScalingDescribeLaunchConfigurationsRequest.h"
#import "AutoScalingDescribeAdjustmentTypesResponse.h"
#import "AutoScalingDescribeAdjustmentTypesRequest.h"
#import "AutoScalingDescribeScheduledActionsResponse.h"
#import "AutoScalingDescribeScheduledActionsRequest.h"
#import "AutoScalingPutScheduledUpdateGroupActionResponse.h"
#import "AutoScalingPutScheduledUpdateGroupActionRequest.h"
#import "AutoScalingDescribeMetricCollectionTypesResponse.h"
#import "AutoScalingDescribeMetricCollectionTypesRequest.h"
#import "AutoScalingSetDesiredCapacityResponse.h"
#import "AutoScalingSetDesiredCapacityRequest.h"
#import "AutoScalingTerminateInstanceInAutoScalingGroupResponse.h"
#import "AutoScalingTerminateInstanceInAutoScalingGroupRequest.h"

#ifdef AWS_MULTI_FRAMEWORK
#import <AWSRuntime/AmazonWebServiceClient.h>
#else
#import "../AmazonWebServiceClient.h"
#endif

/** \defgroup AutoScaling Auto Scaling */

/** <summary>
 * Interface for accessing AmazonAutoScaling.
 *
 *  Auto Scaling <p>
 * Auto Scaling is a web service designed to automatically launch or terminate Amazon Elastic Compute Cloud (Amazon EC2) instances based on user-defined policies, schedules, and health checks. This
 * service is used in conjunction with Amazon CloudWatch and Elastic Load Balancing services.
 * </p>
 * <p>
 * Auto Scaling provides APIs that you can call by submitting a Query Request. Query requests are HTTP or HTTPS requests that use the HTTP verbs GET or POST and a Query parameter named <i>Action</i> or
 * <i>Operation</i> that specifies the API you are calling. Action is used throughout this documentation, although Operation is also supported for backward compatibility with other Amazon Web Services
 * (AWS) Query APIs.
 * </p>
 * <p>
 * Calling the API using a Query request is the most direct way to access the web service, but requires that your application handle low-level details such as generating the hash to sign the request and
 * error handling. The benefit of calling the service using a Query request is that you are assured of having access to the complete functionality of the API. For information about signing a a query
 * request, see <a href="http://docs.aws.amazon.com/AutoScaling/latest/DeveloperGuide/api_requests.html"> Use Query Requests to Call Auto Scaling APIs </a>
 * </p>
 * <p>
 * This guide provides detailed information about Auto Scaling actions, data types, parameters, and errors. For detailed information about Auto Scaling features and their associated API actions, go to
 * the <a href="http://docs.aws.amazon.com/AutoScaling/latest/DeveloperGuide/"> Auto Scaling Developer Guide </a> .
 * </p>
 * <p>
 * This reference is based on the current WSDL, which is available at:
 * </p>
 * <p>
 * <a href="http://autoscaling.amazonaws.com/doc/2011-01-01/AutoScaling.wsdl"> http://autoscaling.amazonaws.com/doc/2011-01-01/AutoScaling.wsdl </a>
 * </p>
 * <p>
 * <b>Endpoints</b>
 * </p>
 * <p>
 * For information about this product's regions and endpoints, go to <a href="http://docs.aws.amazon.com/general/latest/gr/index.html?rande.html"> Regions and Endpoints </a> in the Amazon Web Services
 * General Reference.
 * </p>
 * </summary>
 *
 * See our blog to learn more about Managing Credentials in Mobile Applications.
 * @see http://mobile.awsblog.com/post/Tx31X75XISXHRH8/Managing-Credentials-in-Mobile-Applications
 */
@interface AmazonAutoScalingClient:AmazonWebServiceClient
{
}


/**
 * <p>
 * Returns a full description of each Auto Scaling group in the given list. This includes all Amazon EC2 instances that
 * are members of the group. If a list of names is not provided, the service returns the full details of all Auto Scaling
 * groups.
 * </p>
 * <p>
 * This action supports pagination by returning a token if there are more pages to retrieve. To get the next page, call
 * this action again with the returned token as the NextToken parameter.
 * </p>
 *
 * @param describeAutoScalingGroupsRequest Container for the necessary parameters to execute the DescribeAutoScalingGroups
 *           service method on AmazonAutoScaling.
 *
 * @return The response from the DescribeAutoScalingGroups service method, as returned by AmazonAutoScaling.
 *
 * @exception AutoScalingInvalidNextTokenException For more information see <AutoScalingInvalidNextTokenException>
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonAutoScaling indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see AutoScalingDescribeAutoScalingGroupsRequest
 * @see AutoScalingDescribeAutoScalingGroupsResponse
 */
-(AutoScalingDescribeAutoScalingGroupsResponse *)describeAutoScalingGroups:(AutoScalingDescribeAutoScalingGroupsRequest *)describeAutoScalingGroupsRequest;


/**
 * <p>
 * Enables monitoring of group metrics for the Auto Scaling group specified in AutoScalingGroupName .
 * You can specify the list of enabled metrics with the Metrics parameter.
 * </p>
 * <p>
 * Auto Scaling metrics collection can be turned on only if the InstanceMonitoring flag, in the Auto Scaling group's
 * launch configuration, is set to True .
 *
 * </p>
 *
 * @param enableMetricsCollectionRequest Container for the necessary parameters to execute the EnableMetricsCollection
 *           service method on AmazonAutoScaling.
 *
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonAutoScaling indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see AutoScalingEnableMetricsCollectionRequest
 * @see AutoScalingEnableMetricsCollectionResponse
 */
-(AutoScalingEnableMetricsCollectionResponse *)enableMetricsCollection:(AutoScalingEnableMetricsCollectionRequest *)enableMetricsCollectionRequest;


/**
 * <p>
 * Resumes all suspended Auto Scaling processes for an Auto Scaling group. For information on suspending and resuming Auto
 * Scaling process, see <a href="http://docs.aws.amazon.com/AutoScaling/latest/DeveloperGuide/US_SuspendResume.html">
 * Suspend and Resume Auto Scaling Process </a> .
 * </p>
 *
 * @param resumeProcessesRequest Container for the necessary parameters to execute the ResumeProcesses service method on
 *           AmazonAutoScaling.
 *
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonAutoScaling indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see AutoScalingResumeProcessesRequest
 * @see AutoScalingResumeProcessesResponse
 */
-(AutoScalingResumeProcessesResponse *)resumeProcesses:(AutoScalingResumeProcessesRequest *)resumeProcessesRequest;


/**
 * <p>
 * Deletes the specified LaunchConfiguration.
 * </p>
 * <p>
 * The specified launch configuration must not be attached to an Auto Scaling group. When this call completes, the launch
 * configuration is no longer available for use.
 * </p>
 *
 * @param deleteLaunchConfigurationRequest Container for the necessary parameters to execute the DeleteLaunchConfiguration
 *           service method on AmazonAutoScaling.
 *
 * @exception AutoScalingResourceInUseException For more information see <AutoScalingResourceInUseException>
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonAutoScaling indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see AutoScalingDeleteLaunchConfigurationRequest
 * @see AutoScalingDeleteLaunchConfigurationResponse
 */
-(AutoScalingDeleteLaunchConfigurationResponse *)deleteLaunchConfiguration:(AutoScalingDeleteLaunchConfigurationRequest *)deleteLaunchConfigurationRequest;


/**
 * <p>
 * Returns descriptions of what each policy does. This action supports pagination. If the response includes a token, there
 * are more records available. To get the additional records, repeat the request with the response token as the NextToken
 * parameter.
 * </p>
 *
 * @param describePoliciesRequest Container for the necessary parameters to execute the DescribePolicies service method on
 *           AmazonAutoScaling.
 *
 * @return The response from the DescribePolicies service method, as returned by AmazonAutoScaling.
 *
 * @exception AutoScalingInvalidNextTokenException For more information see <AutoScalingInvalidNextTokenException>
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonAutoScaling indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see AutoScalingDescribePoliciesRequest
 * @see AutoScalingDescribePoliciesResponse
 */
-(AutoScalingDescribePoliciesResponse *)describePolicies:(AutoScalingDescribePoliciesRequest *)describePoliciesRequest;


/**
 * <p>
 * Returns scaling process types for use in the ResumeProcesses and SuspendProcesses actions.
 * </p>
 *
 * @param describeScalingProcessTypesRequest Container for the necessary parameters to execute the
 *           DescribeScalingProcessTypes service method on AmazonAutoScaling.
 *
 * @return The response from the DescribeScalingProcessTypes service method, as returned by AmazonAutoScaling.
 *
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonAutoScaling indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see AutoScalingDescribeScalingProcessTypesRequest
 * @see AutoScalingDescribeScalingProcessTypesResponse
 */
-(AutoScalingDescribeScalingProcessTypesResponse *)describeScalingProcessTypes:(AutoScalingDescribeScalingProcessTypesRequest *)describeScalingProcessTypesRequest;


/**
 * <p>
 * Creates a new Auto Scaling group with the specified name and other attributes. When the creation request is completed,
 * the Auto Scaling group is ready to be used in other calls.
 * </p>
 * <p>
 * <b>NOTE:</b> The Auto Scaling group name must be unique within the scope of your AWS account.
 * </p>
 *
 * @param createAutoScalingGroupRequest Container for the necessary parameters to execute the CreateAutoScalingGroup
 *           service method on AmazonAutoScaling.
 *
 * @exception AutoScalingLimitExceededException For more information see <AutoScalingLimitExceededException>
 * @exception AutoScalingAlreadyExistsException For more information see <AutoScalingAlreadyExistsException>
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonAutoScaling indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see AutoScalingCreateAutoScalingGroupRequest
 * @see AutoScalingCreateAutoScalingGroupResponse
 */
-(AutoScalingCreateAutoScalingGroupResponse *)createAutoScalingGroup:(AutoScalingCreateAutoScalingGroupRequest *)createAutoScalingGroupRequest;


/**
 * <p>
 * Returns the scaling activities for the specified Auto Scaling group.
 * </p>
 * <p>
 * If the specified ActivityIds list is empty, all the activities from the past six weeks are returned. Activities are
 * sorted by completion time. Activities still in progress appear first on the list.
 * </p>
 * <p>
 * This action supports pagination. If the response includes a token, there are more records available. To get the
 * additional records, repeat the request with the response token as the NextToken parameter.
 * </p>
 *
 * @param describeScalingActivitiesRequest Container for the necessary parameters to execute the DescribeScalingActivities
 *           service method on AmazonAutoScaling.
 *
 * @return The response from the DescribeScalingActivities service method, as returned by AmazonAutoScaling.
 *
 * @exception AutoScalingInvalidNextTokenException For more information see <AutoScalingInvalidNextTokenException>
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonAutoScaling indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see AutoScalingDescribeScalingActivitiesRequest
 * @see AutoScalingDescribeScalingActivitiesResponse
 */
-(AutoScalingDescribeScalingActivitiesResponse *)describeScalingActivities:(AutoScalingDescribeScalingActivitiesRequest *)describeScalingActivitiesRequest;


/**
 * <p>
 * Returns a list of notification actions associated with Auto Scaling groups for specified events.
 * </p>
 *
 * @param describeNotificationConfigurationsRequest Container for the necessary parameters to execute the
 *           DescribeNotificationConfigurations service method on AmazonAutoScaling.
 *
 * @return The response from the DescribeNotificationConfigurations service method, as returned by AmazonAutoScaling.
 *
 * @exception AutoScalingInvalidNextTokenException For more information see <AutoScalingInvalidNextTokenException>
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonAutoScaling indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see AutoScalingDescribeNotificationConfigurationsRequest
 * @see AutoScalingDescribeNotificationConfigurationsResponse
 */
-(AutoScalingDescribeNotificationConfigurationsResponse *)describeNotificationConfigurations:(AutoScalingDescribeNotificationConfigurationsRequest *)describeNotificationConfigurationsRequest;


/**
 * <p>
 * Returns a list of all termination policies supported by Auto Scaling.
 * </p>
 *
 * @param describeTerminationPolicyTypesRequest Container for the necessary parameters to execute the
 *           DescribeTerminationPolicyTypes service method on AmazonAutoScaling.
 *
 * @return The response from the DescribeTerminationPolicyTypes service method, as returned by AmazonAutoScaling.
 *
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonAutoScaling indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see AutoScalingDescribeTerminationPolicyTypesRequest
 * @see AutoScalingDescribeTerminationPolicyTypesResponse
 */
-(AutoScalingDescribeTerminationPolicyTypesResponse *)describeTerminationPolicyTypes:(AutoScalingDescribeTerminationPolicyTypesRequest *)describeTerminationPolicyTypesRequest;


/**
 * <p>
 * Lists the Auto Scaling group tags.
 * </p>
 * <p>
 * You can use filters to limit results when describing tags. For example, you can query for tags of a particular Auto
 * Scaling group. You can specify multiple values for a filter. A tag must match at least one of the specified values for
 * it to be included in the results.
 * </p>
 * <p>
 * You can also specify multiple filters. The result includes information for a particular tag only if it matches all your
 * filters. If there's no match, no special message is returned.
 * </p>
 *
 * @param describeTagsRequest Container for the necessary parameters to execute the DescribeTags service method on
 *           AmazonAutoScaling.
 *
 * @return The response from the DescribeTags service method, as returned by AmazonAutoScaling.
 *
 * @exception AutoScalingInvalidNextTokenException For more information see <AutoScalingInvalidNextTokenException>
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonAutoScaling indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see AutoScalingDescribeTagsRequest
 * @see AutoScalingDescribeTagsResponse
 */
-(AutoScalingDescribeTagsResponse *)describeTags:(AutoScalingDescribeTagsRequest *)describeTagsRequest;


/**
 * <p>
 * Executes the specified policy.
 * </p>
 *
 * @param executePolicyRequest Container for the necessary parameters to execute the ExecutePolicy service method on
 *           AmazonAutoScaling.
 *
 * @exception AutoScalingScalingActivityInProgressException For more information see <AutoScalingScalingActivityInProgressException>
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonAutoScaling indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see AutoScalingExecutePolicyRequest
 * @see AutoScalingExecutePolicyResponse
 */
-(AutoScalingExecutePolicyResponse *)executePolicy:(AutoScalingExecutePolicyRequest *)executePolicyRequest;


/**
 * <p>
 * Removes the specified tags or a set of tags from a set of resources.
 * </p>
 *
 * @param deleteTagsRequest Container for the necessary parameters to execute the DeleteTags service method on
 *           AmazonAutoScaling.
 *
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonAutoScaling indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see AutoScalingDeleteTagsRequest
 * @see AutoScalingDeleteTagsResponse
 */
-(AutoScalingDeleteTagsResponse *)deleteTags:(AutoScalingDeleteTagsRequest *)deleteTagsRequest;


/**
 * <p>
 * Creates or updates a policy for an Auto Scaling group. To update an existing policy, use the existing policy name and
 * set the parameter(s) you want to change. Any existing parameter not changed in an update to an existing policy is not
 * changed in this update request.
 * </p>
 *
 * @param putScalingPolicyRequest Container for the necessary parameters to execute the PutScalingPolicy service method on
 *           AmazonAutoScaling.
 *
 * @return The response from the PutScalingPolicy service method, as returned by AmazonAutoScaling.
 *
 * @exception AutoScalingLimitExceededException For more information see <AutoScalingLimitExceededException>
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonAutoScaling indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see AutoScalingPutScalingPolicyRequest
 * @see AutoScalingPutScalingPolicyResponse
 */
-(AutoScalingPutScalingPolicyResponse *)putScalingPolicy:(AutoScalingPutScalingPolicyRequest *)putScalingPolicyRequest;


/**
 * <p>
 * Configures an Auto Scaling group to send notifications when specified events take place. Subscribers to this topic can
 * have messages for events delivered to an endpoint such as a web server or email address.
 * </p>
 * <p>
 * For more information see <a
 * href="http://docs.aws.amazon.com/AutoScaling/latest/DeveloperGuide/ASGettingNotifications.html"> Get Email Notifications
 * When Your Auto Scaling Group Changes </a>
 * </p>
 * <p>
 * A new PutNotificationConfiguration overwrites an existing configuration.
 * </p>
 *
 * @param putNotificationConfigurationRequest Container for the necessary parameters to execute the
 *           PutNotificationConfiguration service method on AmazonAutoScaling.
 *
 * @exception AutoScalingLimitExceededException For more information see <AutoScalingLimitExceededException>
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonAutoScaling indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see AutoScalingPutNotificationConfigurationRequest
 * @see AutoScalingPutNotificationConfigurationResponse
 */
-(AutoScalingPutNotificationConfigurationResponse *)putNotificationConfiguration:(AutoScalingPutNotificationConfigurationRequest *)putNotificationConfigurationRequest;


/**
 * <p>
 * Deletes a policy created by PutScalingPolicy.
 * </p>
 *
 * @param deletePolicyRequest Container for the necessary parameters to execute the DeletePolicy service method on
 *           AmazonAutoScaling.
 *
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonAutoScaling indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see AutoScalingDeletePolicyRequest
 * @see AutoScalingDeletePolicyResponse
 */
-(AutoScalingDeletePolicyResponse *)deletePolicy:(AutoScalingDeletePolicyRequest *)deletePolicyRequest;


/**
 * <p>
 * Deletes notifications created by PutNotificationConfiguration.
 * </p>
 *
 * @param deleteNotificationConfigurationRequest Container for the necessary parameters to execute the
 *           DeleteNotificationConfiguration service method on AmazonAutoScaling.
 *
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonAutoScaling indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see AutoScalingDeleteNotificationConfigurationRequest
 * @see AutoScalingDeleteNotificationConfigurationResponse
 */
-(AutoScalingDeleteNotificationConfigurationResponse *)deleteNotificationConfiguration:(AutoScalingDeleteNotificationConfigurationRequest *)deleteNotificationConfigurationRequest;


/**
 * <p>
 * Deletes a scheduled action previously created using the PutScheduledUpdateGroupAction.
 * </p>
 *
 * @param deleteScheduledActionRequest Container for the necessary parameters to execute the DeleteScheduledAction service
 *           method on AmazonAutoScaling.
 *
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonAutoScaling indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see AutoScalingDeleteScheduledActionRequest
 * @see AutoScalingDeleteScheduledActionResponse
 */
-(AutoScalingDeleteScheduledActionResponse *)deleteScheduledAction:(AutoScalingDeleteScheduledActionRequest *)deleteScheduledActionRequest;


/**
 * <p>
 * Sets the health status of a specified instance that belongs to any of your Auto Scaling groups.
 * </p>
 * <p>
 * For more information, see <a
 * href="http://docs.aws.amazon.com/AutoScaling/latest/DeveloperGuide/as-configure-healthcheck.html"> Configure Health
 * Checks for Your Auto Scaling group </a> .
 * </p>
 *
 * @param setInstanceHealthRequest Container for the necessary parameters to execute the SetInstanceHealth service method
 *           on AmazonAutoScaling.
 *
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonAutoScaling indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see AutoScalingSetInstanceHealthRequest
 * @see AutoScalingSetInstanceHealthResponse
 */
-(AutoScalingSetInstanceHealthResponse *)setInstanceHealth:(AutoScalingSetInstanceHealthRequest *)setInstanceHealthRequest;


/**
 * <p>
 * Returns a list of all notification types that are supported by Auto Scaling.
 * </p>
 *
 * @param describeAutoScalingNotificationTypesRequest Container for the necessary parameters to execute the
 *           DescribeAutoScalingNotificationTypes service method on AmazonAutoScaling.
 *
 * @return The response from the DescribeAutoScalingNotificationTypes service method, as returned by AmazonAutoScaling.
 *
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonAutoScaling indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see AutoScalingDescribeAutoScalingNotificationTypesRequest
 * @see AutoScalingDescribeAutoScalingNotificationTypesResponse
 */
-(AutoScalingDescribeAutoScalingNotificationTypesResponse *)describeAutoScalingNotificationTypes:(AutoScalingDescribeAutoScalingNotificationTypesRequest *)describeAutoScalingNotificationTypesRequest;


/**
 * <p>
 * Creates new tags or updates existing tags for an Auto Scaling group.
 * </p>
 * <p>
 * <b>NOTE:</b> A tag's definition is composed of a resource ID, resource type, key and value, and the propagate flag.
 * Value and the propagate flag are optional parameters. See the Request Parameters for more information.
 * </p>
 * <p>
 * For information on creating tags for your Auto Scaling group, see <a
 * href="http://docs.aws.amazon.com/AutoScaling/latest/DeveloperGuide/ASTagging.html"> Tag Your Auto Scaling Groups and
 * Amazon EC2 Instances </a> .
 * </p>
 *
 * @param createOrUpdateTagsRequest Container for the necessary parameters to execute the CreateOrUpdateTags service method
 *           on AmazonAutoScaling.
 *
 * @exception AutoScalingLimitExceededException For more information see <AutoScalingLimitExceededException>
 * @exception AutoScalingAlreadyExistsException For more information see <AutoScalingAlreadyExistsException>
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonAutoScaling indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see AutoScalingCreateOrUpdateTagsRequest
 * @see AutoScalingCreateOrUpdateTagsResponse
 */
-(AutoScalingCreateOrUpdateTagsResponse *)createOrUpdateTags:(AutoScalingCreateOrUpdateTagsRequest *)createOrUpdateTagsRequest;


/**
 * <p>
 * Suspends Auto Scaling processes for an Auto Scaling group. To suspend specific process types, specify them by name with
 * the ScalingProcesses.member.N parameter. To suspend all process types, omit the ScalingProcesses.member.N parameter.
 * </p>
 * <p>
 * <b>IMPORTANT:</b> Suspending either of the two primary process types, Launch or Terminate, can prevent other process
 * types from functioning properly.
 * </p>
 * <p>
 * To resume processes that have been suspended, use ResumeProcesses For more information on suspending and resuming Auto
 * Scaling process, see <a href="http://docs.aws.amazon.com/AutoScaling/latest/DeveloperGuide/US_SuspendResume.html">
 * Suspend and Resume Auto Scaling Process </a> .
 * </p>
 *
 * @param suspendProcessesRequest Container for the necessary parameters to execute the SuspendProcesses service method on
 *           AmazonAutoScaling.
 *
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonAutoScaling indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see AutoScalingSuspendProcessesRequest
 * @see AutoScalingSuspendProcessesResponse
 */
-(AutoScalingSuspendProcessesResponse *)suspendProcesses:(AutoScalingSuspendProcessesRequest *)suspendProcessesRequest;


/**
 * <p>
 * Returns a description of each Auto Scaling instance in the InstanceIds list. If a list is not provided, the service
 * returns the full details of all instances up to a maximum of 50. By default, the service returns a list of 20 items.
 * </p>
 * <p>
 * This action supports pagination by returning a token if there are more pages to retrieve. To get the next page, call
 * this action again with the returned token as the NextToken parameter.
 * </p>
 *
 * @param describeAutoScalingInstancesRequest Container for the necessary parameters to execute the
 *           DescribeAutoScalingInstances service method on AmazonAutoScaling.
 *
 * @return The response from the DescribeAutoScalingInstances service method, as returned by AmazonAutoScaling.
 *
 * @exception AutoScalingInvalidNextTokenException For more information see <AutoScalingInvalidNextTokenException>
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonAutoScaling indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see AutoScalingDescribeAutoScalingInstancesRequest
 * @see AutoScalingDescribeAutoScalingInstancesResponse
 */
-(AutoScalingDescribeAutoScalingInstancesResponse *)describeAutoScalingInstances:(AutoScalingDescribeAutoScalingInstancesRequest *)describeAutoScalingInstancesRequest;


/**
 * <p>
 * Creates a new launch configuration. The launch configuration name must be unique within the scope of the client's AWS
 * account. The maximum limit of launch configurations, which by default is 100, must not yet have been met; otherwise, the
 * call will fail. When created, the new launch configuration is available for immediate use.
 * </p>
 * <p>
 * You can create a launch configuration with Amazon EC2 security groups or with Amazon VPC security groups. However, you
 * can't use Amazon EC2 security groups together with Amazon VPC security groups, or vice versa.
 * </p>
 * <p>
 * <b>NOTE:</b> At this time, Auto Scaling launch configurations don't support compressed (e.g. zipped) user data files.
 * </p>
 *
 * @param createLaunchConfigurationRequest Container for the necessary parameters to execute the CreateLaunchConfiguration
 *           service method on AmazonAutoScaling.
 *
 * @exception AutoScalingLimitExceededException For more information see <AutoScalingLimitExceededException>
 * @exception AutoScalingAlreadyExistsException For more information see <AutoScalingAlreadyExistsException>
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonAutoScaling indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see AutoScalingCreateLaunchConfigurationRequest
 * @see AutoScalingCreateLaunchConfigurationResponse
 */
-(AutoScalingCreateLaunchConfigurationResponse *)createLaunchConfiguration:(AutoScalingCreateLaunchConfigurationRequest *)createLaunchConfigurationRequest;


/**
 * <p>
 * Deletes the specified Auto Scaling group if the group has no instances and no scaling activities in progress.
 * </p>
 * <p>
 * <b>NOTE:</b> To remove all instances before calling DeleteAutoScalingGroup, you can call UpdateAutoScalingGroup to set
 * the minimum and maximum size of the AutoScalingGroup to zero.
 * </p>
 *
 * @param deleteAutoScalingGroupRequest Container for the necessary parameters to execute the DeleteAutoScalingGroup
 *           service method on AmazonAutoScaling.
 *
 * @exception AutoScalingResourceInUseException For more information see <AutoScalingResourceInUseException>
 * @exception AutoScalingScalingActivityInProgressException For more information see <AutoScalingScalingActivityInProgressException>
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonAutoScaling indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see AutoScalingDeleteAutoScalingGroupRequest
 * @see AutoScalingDeleteAutoScalingGroupResponse
 */
-(AutoScalingDeleteAutoScalingGroupResponse *)deleteAutoScalingGroup:(AutoScalingDeleteAutoScalingGroupRequest *)deleteAutoScalingGroupRequest;


/**
 * <p>
 * Disables monitoring of group metrics for the Auto Scaling group specified in AutoScalingGroupName .
 * You can specify the list of affected metrics with the Metrics parameter.
 * </p>
 *
 * @param disableMetricsCollectionRequest Container for the necessary parameters to execute the DisableMetricsCollection
 *           service method on AmazonAutoScaling.
 *
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonAutoScaling indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see AutoScalingDisableMetricsCollectionRequest
 * @see AutoScalingDisableMetricsCollectionResponse
 */
-(AutoScalingDisableMetricsCollectionResponse *)disableMetricsCollection:(AutoScalingDisableMetricsCollectionRequest *)disableMetricsCollectionRequest;


/**
 * <p>
 * Updates the configuration for the specified AutoScalingGroup.
 * </p>
 * <p>
 * <b>NOTE:</b> To update an Auto Scaling group with a launch configuration that has the InstanceMonitoring flag set to
 * False, you must first ensure that collection of group metrics is disabled. Otherwise, calls to UpdateAutoScalingGroup
 * will fail. If you have previously enabled group metrics collection, you can disable collection of all group metrics by
 * calling DisableMetricsCollection.
 * </p>
 * <p>
 * The new settings are registered upon the completion of this call. Any launch configuration settings take effect on any
 * triggers after this call returns. Scaling activities that are currently in progress aren't affected.
 * </p>
 * <p>
 * <b>NOTE:</b> If a new value is specified for MinSize without specifying the value for DesiredCapacity, and if the new
 * MinSize is larger than the current size of the Auto Scaling Group, there will be an implicit call to SetDesiredCapacity
 * to set the group to the new MinSize. If a new value is specified for MaxSize without specifying the value for
 * DesiredCapacity, and the new MaxSize is smaller than the current size of the Auto Scaling Group, there will be an
 * implicit call to SetDesiredCapacity to set the group to the new MaxSize. All other optional parameters are left
 * unchanged if not passed in the request.
 * </p>
 *
 * @param updateAutoScalingGroupRequest Container for the necessary parameters to execute the UpdateAutoScalingGroup
 *           service method on AmazonAutoScaling.
 *
 * @exception AutoScalingScalingActivityInProgressException For more information see <AutoScalingScalingActivityInProgressException>
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonAutoScaling indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see AutoScalingUpdateAutoScalingGroupRequest
 * @see AutoScalingUpdateAutoScalingGroupResponse
 */
-(AutoScalingUpdateAutoScalingGroupResponse *)updateAutoScalingGroup:(AutoScalingUpdateAutoScalingGroupRequest *)updateAutoScalingGroupRequest;


/**
 * <p>
 * Returns a full description of the launch configurations, or the specified launch configurations, if they exist.
 * </p>
 * <p>
 * If no name is specified, then the full details of all launch configurations are returned.
 * </p>
 *
 * @param describeLaunchConfigurationsRequest Container for the necessary parameters to execute the
 *           DescribeLaunchConfigurations service method on AmazonAutoScaling.
 *
 * @return The response from the DescribeLaunchConfigurations service method, as returned by AmazonAutoScaling.
 *
 * @exception AutoScalingInvalidNextTokenException For more information see <AutoScalingInvalidNextTokenException>
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonAutoScaling indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see AutoScalingDescribeLaunchConfigurationsRequest
 * @see AutoScalingDescribeLaunchConfigurationsResponse
 */
-(AutoScalingDescribeLaunchConfigurationsResponse *)describeLaunchConfigurations:(AutoScalingDescribeLaunchConfigurationsRequest *)describeLaunchConfigurationsRequest;


/**
 * <p>
 * Returns policy adjustment types for use in the PutScalingPolicy action.
 * </p>
 *
 * @param describeAdjustmentTypesRequest Container for the necessary parameters to execute the DescribeAdjustmentTypes
 *           service method on AmazonAutoScaling.
 *
 * @return The response from the DescribeAdjustmentTypes service method, as returned by AmazonAutoScaling.
 *
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonAutoScaling indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see AutoScalingDescribeAdjustmentTypesRequest
 * @see AutoScalingDescribeAdjustmentTypesResponse
 */
-(AutoScalingDescribeAdjustmentTypesResponse *)describeAdjustmentTypes:(AutoScalingDescribeAdjustmentTypesRequest *)describeAdjustmentTypesRequest;


/**
 * <p>
 * Lists all the actions scheduled for your Auto Scaling group that haven't been executed. To see a list of actions
 * already executed, see the activity record returned in DescribeScalingActivities.
 * </p>
 *
 * @param describeScheduledActionsRequest Container for the necessary parameters to execute the DescribeScheduledActions
 *           service method on AmazonAutoScaling.
 *
 * @return The response from the DescribeScheduledActions service method, as returned by AmazonAutoScaling.
 *
 * @exception AutoScalingInvalidNextTokenException For more information see <AutoScalingInvalidNextTokenException>
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonAutoScaling indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see AutoScalingDescribeScheduledActionsRequest
 * @see AutoScalingDescribeScheduledActionsResponse
 */
-(AutoScalingDescribeScheduledActionsResponse *)describeScheduledActions:(AutoScalingDescribeScheduledActionsRequest *)describeScheduledActionsRequest;


/**
 * <p>
 * Creates or updates a scheduled scaling action for an Auto Scaling group. When updating a scheduled scaling action, if
 * you leave a parameter unspecified, the corresponding value remains unchanged in the affected Auto Scaling group.
 * </p>
 * <p>
 * For information on creating or updating a scheduled action for your Auto Scaling group, see <a
 * href="http://docs.aws.amazon.com/AutoScaling/latest/DeveloperGuide/schedule_time.html"> Scale Based on a Schedule </a> .
 * </p>
 * <p>
 * <b>NOTE:</b> Auto Scaling supports the date and time expressed in "YYYY-MM-DDThh:mm:ssZ" format in UTC/GMT only.
 * </p>
 *
 * @param putScheduledUpdateGroupActionRequest Container for the necessary parameters to execute the
 *           PutScheduledUpdateGroupAction service method on AmazonAutoScaling.
 *
 * @exception AutoScalingLimitExceededException For more information see <AutoScalingLimitExceededException>
 * @exception AutoScalingAlreadyExistsException For more information see <AutoScalingAlreadyExistsException>
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonAutoScaling indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see AutoScalingPutScheduledUpdateGroupActionRequest
 * @see AutoScalingPutScheduledUpdateGroupActionResponse
 */
-(AutoScalingPutScheduledUpdateGroupActionResponse *)putScheduledUpdateGroupAction:(AutoScalingPutScheduledUpdateGroupActionRequest *)putScheduledUpdateGroupActionRequest;


/**
 * <p>
 * Returns a list of metrics and a corresponding list of granularities for each metric.
 * </p>
 *
 * @param describeMetricCollectionTypesRequest Container for the necessary parameters to execute the
 *           DescribeMetricCollectionTypes service method on AmazonAutoScaling.
 *
 * @return The response from the DescribeMetricCollectionTypes service method, as returned by AmazonAutoScaling.
 *
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonAutoScaling indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see AutoScalingDescribeMetricCollectionTypesRequest
 * @see AutoScalingDescribeMetricCollectionTypesResponse
 */
-(AutoScalingDescribeMetricCollectionTypesResponse *)describeMetricCollectionTypes:(AutoScalingDescribeMetricCollectionTypesRequest *)describeMetricCollectionTypesRequest;


/**
 * <p>
 * Sets the desired size of the specified AutoScalingGroup.
 * </p>
 *
 * @param setDesiredCapacityRequest Container for the necessary parameters to execute the SetDesiredCapacity service method
 *           on AmazonAutoScaling.
 *
 * @exception AutoScalingScalingActivityInProgressException For more information see <AutoScalingScalingActivityInProgressException>
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonAutoScaling indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see AutoScalingSetDesiredCapacityRequest
 * @see AutoScalingSetDesiredCapacityResponse
 */
-(AutoScalingSetDesiredCapacityResponse *)setDesiredCapacity:(AutoScalingSetDesiredCapacityRequest *)setDesiredCapacityRequest;


/**
 * <p>
 * Terminates the specified instance. Optionally, the desired group size can be adjusted.
 * </p>
 * <p>
 * <b>NOTE:</b> This call simply registers a termination request. The termination of the instance cannot happen
 * immediately.
 * </p>
 *
 * @param terminateInstanceInAutoScalingGroupRequest Container for the necessary parameters to execute the
 *           TerminateInstanceInAutoScalingGroup service method on AmazonAutoScaling.
 *
 * @return The response from the TerminateInstanceInAutoScalingGroup service method, as returned by AmazonAutoScaling.
 *
 * @exception AutoScalingScalingActivityInProgressException For more information see <AutoScalingScalingActivityInProgressException>
 *
 * @exception AmazonClientException If any internal errors are encountered inside the client while
 * attempting to make the request or handle the response.  For example
 * if a network connection is not available.  For more information see <AmazonClientException>.
 * @exception AmazonServiceException If an error response is returned by AmazonAutoScaling indicating
 * either a problem with the data in the request, or a server side issue.  For more information see <AmazonServiceException>.
 *
 * @see AutoScalingTerminateInstanceInAutoScalingGroupRequest
 * @see AutoScalingTerminateInstanceInAutoScalingGroupResponse
 */
-(AutoScalingTerminateInstanceInAutoScalingGroupResponse *)terminateInstanceInAutoScalingGroup:(AutoScalingTerminateInstanceInAutoScalingGroupRequest *)terminateInstanceInAutoScalingGroupRequest;



@end

