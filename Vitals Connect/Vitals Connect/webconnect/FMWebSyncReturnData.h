//
// Title: WebSync Client ReturnData Extension for Cocoa
// Version: 4.7.4
// Copyright Frozen Mountain Software 2011+
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

#if TARGET_OS_IPHONE
  #import <UIKit/UIKit.h>
#else
  #import <AppKit/AppKit.h>
#endif

@class FMWebSyncReturnDataBase;
@class FMWebSyncServiceArgsExtensions;
@class FMWebSyncNotifyArgsExtensions;
@class FMWebSyncNotificationExtensions;
@class FMWebSyncPublicationExtensions;
@class FMWebSyncPublishArgsExtensions;

@class FMNullableBool;
@class FMWebSyncExtensible;

/// <summary>
/// Base methods supporting the ReturnData extension.
/// </summary>
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#pragma clang diagnostic ignored "-Wint-to-pointer-cast"

@interface FMWebSyncReturnDataBase : NSObject 

/// <summary>
/// Gets whether data should be returned with the response.
/// </summary>
/// <param name="extensible">The <see cref="FMWebSyncExtensible" /> object.</param>
/// <returns>True if the data should be returned, false if not, and null if not specified.</returns>
+ (FMNullableBool*) getReturnDataWithExtensible:(FMWebSyncExtensible*)extensible;
/// <summary>
/// Sets whether data should be returned with the response.
/// </summary>
/// <param name="extensible">The <see cref="FMWebSyncExtensible" /> object.</param>
/// <param name="returnData">If set to <c>true</c> return data with the response.</param>
+ (void) setReturnDataWithExtensible:(FMWebSyncExtensible*)extensible returnData:(bool)returnData;

@end


@class FMNullableBool;
@class FMWebSyncServiceArgs;

/// <summary>
/// <see cref="FMWebSyncServiceArgs" /> extension methods for the ReturnData extension.
/// </summary>
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#pragma clang diagnostic ignored "-Wint-to-pointer-cast"

@interface FMWebSyncServiceArgs (FMWebSyncReturnDataExtensions)

/// <summary>
/// Gets whether or not serviced data should be returned in the response.
/// </summary>
/// <param name="serviceArgs">The <see cref="FMWebSyncServiceArgs" /> to extend.</param>
/// <returns><c>true</c> if the serviced data should be returned in the response;
/// <c>false</c> if the serviced data should not be returned in the response;
/// <c>null</c> it not specified.</returns>
- (FMNullableBool*) getReturnData;
/// <summary>
/// Gets whether or not serviced data should be returned in the response.
/// </summary>
/// <param name="serviceArgs">The <see cref="FMWebSyncServiceArgs" /> to extend.</param>
/// <returns><c>true</c> if the serviced data should be returned in the response;
/// <c>false</c> if the serviced data should not be returned in the response;
/// <c>null</c> it not specified.</returns>
+ (FMNullableBool*) getReturnDataWithServiceArgs:(FMWebSyncServiceArgs*)serviceArgs;
/// <summary>
/// Sets whether or not to return the serviced data in the response.
/// </summary>
/// <param name="serviceArgs">The <see cref="FMWebSyncServiceArgs" /> to extend.</param>
/// <param name="returnData">Whether or not to return the serviced data in the response.</param>
/// <returns>The <see cref="FMWebSyncServiceArgs" />.</returns>
- (FMWebSyncServiceArgs*) setReturnDataWithReturnData:(bool)returnData;
/// <summary>
/// Sets whether or not to return the serviced data in the response.
/// </summary>
/// <param name="serviceArgs">The <see cref="FMWebSyncServiceArgs" /> to extend.</param>
/// <param name="returnData">Whether or not to return the serviced data in the response.</param>
/// <returns>The <see cref="FMWebSyncServiceArgs" />.</returns>
- (FMWebSyncServiceArgs*) setReturnData:(bool)returnData;
/// <summary>
/// Sets whether or not to return the serviced data in the response.
/// </summary>
/// <param name="serviceArgs">The <see cref="FMWebSyncServiceArgs" /> to extend.</param>
/// <param name="returnData">Whether or not to return the serviced data in the response.</param>
/// <returns>The <see cref="FMWebSyncServiceArgs" />.</returns>
+ (FMWebSyncServiceArgs*) setReturnDataWithServiceArgs:(FMWebSyncServiceArgs*)serviceArgs returnData:(bool)returnData;

@end


@class FMNullableBool;
@class FMWebSyncNotifyArgs;

/// <summary>
/// <see cref="FMWebSyncNotifyArgs" /> extension methods for the ReturnData extension.
/// </summary>
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#pragma clang diagnostic ignored "-Wint-to-pointer-cast"

@interface FMWebSyncNotifyArgs (FMWebSyncReturnDataExtensions)

/// <summary>
/// Gets whether or not notified data should be returned in the response.
/// </summary>
/// <param name="notifyArgs">The <see cref="FMWebSyncNotifyArgs" /> to extend.</param>
/// <returns><c>true</c> if the notified data should be returned in the response;
/// <c>false</c> if the notified data should not be returned in the response;
/// <c>null</c> it not specified.</returns>
- (FMNullableBool*) getReturnData;
/// <summary>
/// Gets whether or not notified data should be returned in the response.
/// </summary>
/// <param name="notifyArgs">The <see cref="FMWebSyncNotifyArgs" /> to extend.</param>
/// <returns><c>true</c> if the notified data should be returned in the response;
/// <c>false</c> if the notified data should not be returned in the response;
/// <c>null</c> it not specified.</returns>
+ (FMNullableBool*) getReturnDataWithNotifyArgs:(FMWebSyncNotifyArgs*)notifyArgs;
/// <summary>
/// Sets whether or not to return the notified data in the response.
/// </summary>
/// <param name="notifyArgs">The <see cref="FMWebSyncNotifyArgs" /> to extend.</param>
/// <param name="returnData">Whether or not to return the notified data in the response.</param>
/// <returns>The <see cref="FMWebSyncNotifyArgs" />.</returns>
+ (FMWebSyncNotifyArgs*) setReturnDataWithNotifyArgs:(FMWebSyncNotifyArgs*)notifyArgs returnData:(bool)returnData;
/// <summary>
/// Sets whether or not to return the notified data in the response.
/// </summary>
/// <param name="notifyArgs">The <see cref="FMWebSyncNotifyArgs" /> to extend.</param>
/// <param name="returnData">Whether or not to return the notified data in the response.</param>
/// <returns>The <see cref="FMWebSyncNotifyArgs" />.</returns>
- (FMWebSyncNotifyArgs*) setReturnDataWithReturnData:(bool)returnData;
/// <summary>
/// Sets whether or not to return the notified data in the response.
/// </summary>
/// <param name="notifyArgs">The <see cref="FMWebSyncNotifyArgs" /> to extend.</param>
/// <param name="returnData">Whether or not to return the notified data in the response.</param>
/// <returns>The <see cref="FMWebSyncNotifyArgs" />.</returns>
- (FMWebSyncNotifyArgs*) setReturnData:(bool)returnData;

@end


@class FMNullableBool;
@class FMWebSyncNotification;

/// <summary>
/// <see cref="FMWebSyncNotification" /> extension methods for the ReturnData extension.
/// </summary>
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#pragma clang diagnostic ignored "-Wint-to-pointer-cast"

@interface FMWebSyncNotification (FMWebSyncReturnDataExtensions)

/// <summary>
/// Gets whether or not notified data should be returned in the response.
/// </summary>
/// <param name="notification">The <see cref="FMWebSyncNotification" /> to extend.</param>
/// <returns><c>true</c> if the notified data should be returned in the response;
/// <c>false</c> if the notified data should not be returned in the response;
/// <c>null</c> it not specified.</returns>
- (FMNullableBool*) getReturnData;
/// <summary>
/// Gets whether or not notified data should be returned in the response.
/// </summary>
/// <param name="notification">The <see cref="FMWebSyncNotification" /> to extend.</param>
/// <returns><c>true</c> if the notified data should be returned in the response;
/// <c>false</c> if the notified data should not be returned in the response;
/// <c>null</c> it not specified.</returns>
+ (FMNullableBool*) getReturnDataWithNotification:(FMWebSyncNotification*)notification;
/// <summary>
/// Sets whether or not to return the notified data in the response.
/// </summary>
/// <param name="notification">The <see cref="FMWebSyncNotification" /> to extend.</param>
/// <param name="returnData">Whether or not to return the notified data in the response.</param>
/// <returns>The <see cref="FMWebSyncNotification" />.</returns>
+ (FMWebSyncNotification*) setReturnDataWithNotification:(FMWebSyncNotification*)notification returnData:(bool)returnData;
/// <summary>
/// Sets whether or not to return the notified data in the response.
/// </summary>
/// <param name="notification">The <see cref="FMWebSyncNotification" /> to extend.</param>
/// <param name="returnData">Whether or not to return the notified data in the response.</param>
/// <returns>The <see cref="FMWebSyncNotification" />.</returns>
- (FMWebSyncNotification*) setReturnDataWithReturnData:(bool)returnData;
/// <summary>
/// Sets whether or not to return the notified data in the response.
/// </summary>
/// <param name="notification">The <see cref="FMWebSyncNotification" /> to extend.</param>
/// <param name="returnData">Whether or not to return the notified data in the response.</param>
/// <returns>The <see cref="FMWebSyncNotification" />.</returns>
- (FMWebSyncNotification*) setReturnData:(bool)returnData;

@end


@class FMNullableBool;
@class FMWebSyncPublication;

/// <summary>
/// <see cref="FMWebSyncPublication" /> extension methods for the ReturnData extension.
/// </summary>
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#pragma clang diagnostic ignored "-Wint-to-pointer-cast"

@interface FMWebSyncPublication (FMWebSyncReturnDataExtensions)

/// <summary>
/// Gets whether or not published data should be returned in the response.
/// </summary>
/// <param name="publication">The <see cref="FMWebSyncPublication" /> to extend.</param>
/// <returns><c>true</c> if the published data should be returned in the response;
/// <c>false</c> if the published data should not be returned in the response;
/// <c>null</c> it not specified.</returns>
- (FMNullableBool*) getReturnData;
/// <summary>
/// Gets whether or not published data should be returned in the response.
/// </summary>
/// <param name="publication">The <see cref="FMWebSyncPublication" /> to extend.</param>
/// <returns><c>true</c> if the published data should be returned in the response;
/// <c>false</c> if the published data should not be returned in the response;
/// <c>null</c> it not specified.</returns>
+ (FMNullableBool*) getReturnDataWithPublication:(FMWebSyncPublication*)publication;
/// <summary>
/// Sets whether or not to return the published data in the response.
/// </summary>
/// <param name="publication">The <see cref="FMWebSyncPublication" /> to extend.</param>
/// <param name="returnData">Whether or not to return the published data in the response.</param>
/// <returns>The <see cref="FMWebSyncPublication" />.</returns>
+ (FMWebSyncPublication*) setReturnDataWithPublication:(FMWebSyncPublication*)publication returnData:(bool)returnData;
/// <summary>
/// Sets whether or not to return the published data in the response.
/// </summary>
/// <param name="publication">The <see cref="FMWebSyncPublication" /> to extend.</param>
/// <param name="returnData">Whether or not to return the published data in the response.</param>
/// <returns>The <see cref="FMWebSyncPublication" />.</returns>
- (FMWebSyncPublication*) setReturnDataWithReturnData:(bool)returnData;
/// <summary>
/// Sets whether or not to return the published data in the response.
/// </summary>
/// <param name="publication">The <see cref="FMWebSyncPublication" /> to extend.</param>
/// <param name="returnData">Whether or not to return the published data in the response.</param>
/// <returns>The <see cref="FMWebSyncPublication" />.</returns>
- (FMWebSyncPublication*) setReturnData:(bool)returnData;

@end


@class FMNullableBool;
@class FMWebSyncPublishArgs;

/// <summary>
/// <see cref="FMWebSyncPublishArgs" /> extension methods for the ReturnData extension.
/// </summary>
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#pragma clang diagnostic ignored "-Wint-to-pointer-cast"

@interface FMWebSyncPublishArgs (FMWebSyncReturnDataExtensions)

/// <summary>
/// Gets whether or not published data should be returned in the response.
/// </summary>
/// <param name="publishArgs">The <see cref="FMWebSyncPublishArgs" /> to extend.</param>
/// <returns><c>true</c> if the published data should be returned in the response;
/// <c>false</c> if the published data should not be returned in the response;
/// <c>null</c> it not specified.</returns>
- (FMNullableBool*) getReturnData;
/// <summary>
/// Gets whether or not published data should be returned in the response.
/// </summary>
/// <param name="publishArgs">The <see cref="FMWebSyncPublishArgs" /> to extend.</param>
/// <returns><c>true</c> if the published data should be returned in the response;
/// <c>false</c> if the published data should not be returned in the response;
/// <c>null</c> it not specified.</returns>
+ (FMNullableBool*) getReturnDataWithPublishArgs:(FMWebSyncPublishArgs*)publishArgs;
/// <summary>
/// Sets whether or not to return the published data in the response.
/// </summary>
/// <param name="publishArgs">The <see cref="FMWebSyncPublishArgs" /> to extend.</param>
/// <param name="returnData">Whether or not to return the published data in the response.</param>
/// <returns>The <see cref="FMWebSyncPublishArgs" />.</returns>
+ (FMWebSyncPublishArgs*) setReturnDataWithPublishArgs:(FMWebSyncPublishArgs*)publishArgs returnData:(bool)returnData;
/// <summary>
/// Sets whether or not to return the published data in the response.
/// </summary>
/// <param name="publishArgs">The <see cref="FMWebSyncPublishArgs" /> to extend.</param>
/// <param name="returnData">Whether or not to return the published data in the response.</param>
/// <returns>The <see cref="FMWebSyncPublishArgs" />.</returns>
- (FMWebSyncPublishArgs*) setReturnDataWithReturnData:(bool)returnData;
/// <summary>
/// Sets whether or not to return the published data in the response.
/// </summary>
/// <param name="publishArgs">The <see cref="FMWebSyncPublishArgs" /> to extend.</param>
/// <param name="returnData">Whether or not to return the published data in the response.</param>
/// <returns>The <see cref="FMWebSyncPublishArgs" />.</returns>
- (FMWebSyncPublishArgs*) setReturnData:(bool)returnData;

@end

