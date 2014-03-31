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

#import "AmazonAbstractWebServiceClient.h"
#import "AmazonStaticCredentialsProvider.h"
#import "AmazonEndpoints.h"


@implementation AmazonAbstractWebServiceClient

@synthesize userAgent = _userAgent;

- (id)init
{
    if (self = [super init]) {
        _maxRetries = 5;
        _timeout = 240;
        _connectionTimeout = 0;
        _delay = 0.2;
        _userAgent = [[AmazonSDKUtil userAgentString] retain];
    }

    return self;
}

-(id)initWithCredentials:(AmazonCredentials *)credentials
{
    AmazonStaticCredentialsProvider *provider = [[AmazonStaticCredentialsProvider alloc] initWithCredentials:credentials];
    if (self = [self initWithCredentialsProvider:provider]) {
    }

    [provider release];

    return self;
}

-(id)initWithCredentialsProvider:(id<AmazonCredentialsProvider>)provider
{
    if (self = [self init]) {
        _provider = [provider retain];
    }

    return self;
}

+(id)constructResponseFromRequest:(AmazonServiceRequest *)request
{
    NSString *requestClassName  = NSStringFromClass([request class]);
    NSString *responseClassName = [[requestClassName substringToIndex:[requestClassName length] - 7] stringByAppendingFormat:@"Response"];

    id response = [[NSClassFromString(responseClassName) new] autorelease];

    if (nil == response) {
        response = [request constructResponse];
    }

    return response;
}

-(AmazonServiceResponse *)invoke:(AmazonServiceRequest *)generatedRequest rawRequest:(AmazonServiceRequestConfig *)originalRequest unmarshallerDelegate:(Class)unmarshallerDelegate
{
    return [self invoke:generatedRequest rawRequest:originalRequest unmarshallerDelegate:unmarshallerDelegate andSign:YES];
}

-(AmazonServiceResponse *)invoke:(AmazonServiceRequest *)generatedRequest rawRequest:(AmazonServiceRequestConfig *)originalRequest unmarshallerDelegate:(Class)unmarshallerDelegate andSign:(BOOL)signRequest
{
    if (nil == generatedRequest) {
        return [self nilRequestResponse];
    }

    [generatedRequest setUserAgent:self.userAgent];

    if (nil == generatedRequest.endpoint) {
        generatedRequest.endpoint = [self endpoint];
    }
    if (nil == generatedRequest.credentials) {
        [generatedRequest setCredentials:[_provider credentials]];
    }

    NSMutableURLRequest *urlRequest = [generatedRequest configureURLRequest];
    if (signRequest) {
        [generatedRequest sign];
    }
    [urlRequest setHTTPBody:[[generatedRequest queryString] dataUsingEncoding:NSUTF8StringEncoding]];
    [self logTheRequest:urlRequest];

    AmazonServiceResponse *response = nil;
    int retries = 0;
    while (retries < self.maxRetries) {
        AMZLogDebug(@"Begin Request: %@:%d", NSStringFromClass([generatedRequest class]), retries);

        response = [self createResponse:generatedRequest withUnmarshallerDelegate:unmarshallerDelegate];
        [self setupRequestTimeout:urlRequest];

        // Setting this here and not the AmazonServiceRequest because S3 extends that class and sets its own Content-Type Header.
        [urlRequest addValue:@"application/x-www-form-urlencoded; charset=utf-8" forHTTPHeaderField:@"Content-Type"];

        if ([generatedRequest delegate] != nil) {
            response.isAsyncCall = YES;
            [self startAsyncRequest:urlRequest response:response originalRequest:originalRequest];
            return nil;
        }

        response.isAsyncCall = NO;
        [self startSyncRequest:generatedRequest forRequest:urlRequest response:response originalRequest:originalRequest];
        AMZLogDebug(@"Response Status Code : %d", response.httpStatusCode);

        if ( [self shouldRetry:response exception:((AmazonRequestDelegate *)generatedRequest.delegate).exception] ) {
            AMZLog(@"Retring Request: %d", retries);

            // Only Clock Skew exception needs to resign
            if(response.hasClockSkewError) {
                urlRequest = [generatedRequest configureURLRequest];
                [[generatedRequest parameters] removeObjectForKey:@"Signature"];
                [generatedRequest sign];
                [urlRequest setHTTPBody:[[generatedRequest queryString] dataUsingEncoding:NSUTF8StringEncoding]];
                [self logTheRequest:urlRequest];
            }

            [self pauseExponentially:retries];
            retries++;

            if (retries < self.maxRetries)
            {
                generatedRequest.delegate = nil;
            }
        }
        else {
            break;
        }
    }

    return [self returnErrorOrResponse:response forRequest:generatedRequest];
}

- (BOOL)shouldRetry:(AmazonServiceResponse *)response
{
    return [self shouldRetry:response exception:response.exception];
}

- (BOOL)shouldRetry:(AmazonServiceResponse *)response exception:(NSException *)exception
{
    // Handling request timeout and HTTP errors.
    if (response.didTimeout || response.httpStatusCode == 500 || response.httpStatusCode == 503) {

        return YES;
    }

    NSException *exceptionHolder = response.exception;
    if(exceptionHolder == nil)
    {
        exceptionHolder = exception;
    }

    if([exceptionHolder isKindOfClass:[AmazonClientException class]])
    {
        AmazonClientException *clientException = (AmazonClientException *)exceptionHolder;

        // Handling NSURL errors.
        if(clientException.error != nil)
        {
            if([clientException.error.domain isEqualToString:NSURLErrorDomain]
               && clientException.error.code == NSURLErrorNetworkConnectionLost)
            {
                // The network connection was lost.
                return YES;
            }

            if([clientException.error.domain isEqualToString:NSURLErrorDomain]
               && clientException.error.code == NSURLErrorTimedOut)
            {
                // The request timed out.
                return YES;
            }

            if([clientException.error.domain isEqualToString:NSURLErrorDomain]
               && clientException.error.code == NSURLErrorCannotFindHost)
            {
                // S3 sometimes returns this error even when the bucket exists.
                return YES;
            }
        }
        // Handling AWS client exceptions.
        else
        {
            if ([clientException.message isEqualToString:@"CRC32 doesn't match."]) {
                return YES;
            }
        }
    }

    // Handling AWS service exceptions.
    if([exceptionHolder isKindOfClass:[AmazonServiceException class]])
    {
        AmazonServiceException *serviceException = (AmazonServiceException *)exceptionHolder;

        if ( [serviceException.errorCode isEqualToString:@"BadDigest"]) {
            // The Content-MD5 you specified did not match what S3 received.
            return YES;
        }

        if ( [serviceException.errorCode isEqualToString:@"NoSuchUpload"]) {
            // S3 Multipart Upload Complete request sometimes fails.
            return YES;
        }

        if( [serviceException.errorCode isEqualToString:@"ExpiredToken"]
           || [serviceException.errorCode isEqualToString:@"InvalidToken"]
           || [serviceException.errorCode isEqualToString:@"TokenRefreshRequired"] ) {

            // If the service returned error indicating session expired,
            // force refresh on provider and retry
            [_provider refresh];
            return YES;
        }

        if ( [serviceException.errorCode isEqualToString:@"ProvisionedThroughputExceededException"]) {
            return YES;
        }

        if (serviceException.reason != nil && [serviceException.reason rangeOfString:@"Throttling"].location != NSNotFound) {
            return YES;
        }

        if ( [response isClockSkewError:serviceException] ) {
            response.hasClockSkewError = YES;
            [AmazonSDKUtil setRuntimeClockSkew:[response getSkewTimeUsingResponse]];
            return YES;
        }
    }

    return NO;
}

-(void)pauseExponentially:(int32_t)tryCount
{
    NSTimeInterval pause = self.delay * (pow(2, tryCount));

    [NSThread sleepForTimeInterval:pause];
}

-(void)setUserAgent:(NSString *)newUserAgent
{
    [_userAgent autorelease];
    _userAgent = [[NSString stringWithFormat:@"%@, %@", newUserAgent, [AmazonSDKUtil userAgentString]] retain];
}

-(NSString *)userAgent
{
    if([AmazonErrorHandler throwsExceptions] == YES)
    {
        return _userAgent;
    }
    else
    {
        // When NSError error handling is enabled, add NE at the end of userAgent.
        return [NSString stringWithFormat:@"%@ NE", _userAgent];
    }
}

- (id)copyWithZone:(NSZone *)zone
{
    AmazonAbstractWebServiceClient *o = [[[self class] allocWithZone:zone] init];
    o.provider = self.provider;
    o.endpoint = [[self.endpoint copy] autorelease];
    o.maxRetries = self.maxRetries;
    o.timeout = self.timeout;
    o.connectionTimeout = self.connectionTimeout;
    o.delay = self.delay;
    o.userAgent = [[self.userAgent copy] autorelease];

    return o;
}

-(AmazonServiceResponse *)nilRequestResponse
{
    AmazonServiceResponse *response = [[[AmazonServiceResponse alloc] init] autorelease];
    response.error = [AmazonErrorHandler errorFromExceptionWithThrowsExceptionOption:[AmazonClientException
                                                                                      exceptionWithMessage:@"Request cannot be nil."]];

    return response;
}

-(void)logTheRequest:(NSMutableURLRequest *)urlRequest
{
    if ([AmazonLogger isVerboseLoggingEnabled]) {
        AMZLogDebug(@"%@ %@", [urlRequest HTTPMethod], [urlRequest URL]);
        AMZLogDebug(@"Request body: ");
        NSString *rBody = [[NSString alloc] initWithData:[urlRequest HTTPBody] encoding:NSUTF8StringEncoding];
        AMZLogDebug(@"%@", rBody);
        [rBody release];
    }
}

-(void)logTheRequestHeaders:(NSMutableURLRequest *)urlRequest
{
    AMZLogDebug(@"%@ %@", [urlRequest HTTPMethod], [urlRequest URL]);
    AMZLogDebug(@"Request headers: ");
    for (id hKey in [[urlRequest allHTTPHeaderFields] allKeys])
    {
        AMZLogDebug(@"  %@: %@", [hKey description], [[urlRequest allHTTPHeaderFields] valueForKey:hKey]);
    }
}

-(AmazonServiceResponse *)returnErrorOrResponse:(AmazonServiceResponse*)response forRequest:(AmazonServiceRequest *)generatedRequest
{
    if (response.exception != nil)
    {
        response.error = [AmazonErrorHandler errorFromExceptionWithThrowsExceptionOption:response.exception];
    }
    else if(response.error == nil)
    {
        if (((AmazonRequestDelegate *)generatedRequest.delegate).error != nil)
        {
            if (response == nil)
            {
                response = [generatedRequest constructResponse];
            }
            response.error = ((AmazonRequestDelegate *)generatedRequest.delegate).error;
        }
        else if (((AmazonRequestDelegate *)generatedRequest.delegate).exception != nil)
        {
            if (response == nil)
            {
                response = [generatedRequest constructResponse];
            }
            response.error = [AmazonErrorHandler errorFromExceptionWithThrowsExceptionOption:((AmazonRequestDelegate *)generatedRequest.delegate).exception];
        }
        else if (((AmazonRequestDelegate *)generatedRequest.delegate).response != nil)
        {
            return ((AmazonRequestDelegate *)generatedRequest.delegate).response;
        }
        else
        {
            if (response == nil)
            {
                response = [generatedRequest constructResponse];
            }
            response.error = [AmazonErrorHandler errorFromExceptionWithThrowsExceptionOption:
                              [AmazonClientException exceptionWithMessage:@"Unknown error occurred."]];
        }
    }

    return response;
}

-(void)startAsyncRequest:(NSMutableURLRequest *)urlRequest response:(AmazonServiceResponse *)response originalRequest:(AmazonServiceRequestConfig *)originalRequest
{
    NSURLConnection *urlConnection = [[[NSURLConnection alloc] initWithRequest:urlRequest
                                                                      delegate:response
                                                              startImmediately:NO] autorelease];
    originalRequest.urlConnection = urlConnection;

    NSTimer *timer = [NSTimer scheduledTimerWithTimeInterval:self.timeout
                                                      target:response
                                                    selector:@selector(timeout)
                                                    userInfo:nil
                                                     repeats:NO];
    response.request.responseTimer = timer;
    [urlConnection start];
}

-(void)startSyncRequest:(AmazonServiceRequest *)generatedRequest forRequest:(NSMutableURLRequest *)urlRequest response:(AmazonServiceResponse *)response originalRequest:(AmazonServiceRequestConfig *)originalRequest
{
    generatedRequest.delegate = [[[AmazonRequestDelegate alloc] init] autorelease];

    NSURLConnection *urlConnection = [[[NSURLConnection alloc] initWithRequest:urlRequest
                                                                      delegate:response
                                                              startImmediately:NO] autorelease];
    [urlConnection scheduleInRunLoop:[NSRunLoop currentRunLoop] forMode:AWSDefaultRunLoopMode];
    originalRequest.urlConnection = urlConnection;
    [urlConnection start];

    NSTimer *timeoutTimer = [NSTimer timerWithTimeInterval:self.timeout
                                                    target:response
                                                  selector:@selector(timeout)
                                                  userInfo:nil
                                                   repeats:NO];
    [[NSRunLoop currentRunLoop] addTimer:timeoutTimer forMode:AWSDefaultRunLoopMode];

    while (![(AmazonRequestDelegate *)(generatedRequest.delegate)isFinishedOrFailed]) {
        [[NSRunLoop currentRunLoop] runMode:AWSDefaultRunLoopMode beforeDate:[NSDate distantFuture]];
    }

    if (response.didTimeout) {
        [urlConnection cancel];
    }
    else {
        [timeoutTimer invalidate];     //  invalidate also releases the object.
    }
}

-(AmazonServiceResponse *)createResponse:(AmazonServiceRequest *)generatedRequest withUnmarshallerDelegate:(Class)unmarshallerDelegate
{
    AmazonServiceResponse *response = [AmazonAbstractWebServiceClient constructResponseFromRequest:generatedRequest];
    [response setRequest:generatedRequest];
    response.unmarshallerDelegate = unmarshallerDelegate;

    return response;
}

-(void)setupRequestTimeout:(NSMutableURLRequest *)urlRequest
{
    if (self.connectionTimeout != 0) {
        [urlRequest setTimeoutInterval:self.connectionTimeout];
    }
    else {
        [urlRequest setTimeoutInterval:self.timeout];
    }
    
}

-(void)dealloc
{
    [_provider release];
    [_endpoint release];
    [_userAgent release];
    
    [super dealloc];
}

@end
