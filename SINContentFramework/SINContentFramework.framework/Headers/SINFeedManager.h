//
//  SINFeedManager.h
//  SINContentFramework
//
//  Created by wf on 2019/11/26.
//  Copyright © 2019 Sohu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "SINFeedSDKConfig.h"

///调用注册接口异常错误码
typedef NS_ENUM(NSUInteger, SINFeedSDKRegisterError) {
    SINFeedSDKRegisterErrorUnknown,
    SINFeedSDKRegisterErrorJson = 10000,               //注册json格式错误
    SINFeedSDKRegisterErrorServer = 10001,             //服务端数据错误
    SINFeedSDKRegisterErrorNoNetwork = -1004           //无网络
};

@protocol SINFeedManagerDelegate <NSObject>

- (void)feedRegisterFaildWithErrorCoded:(SINFeedSDKRegisterError)errCode;

@end

NS_ASSUME_NONNULL_BEGIN

@interface SINFeedManager : NSObject

@property (nonatomic, weak)   id<SINFeedManagerDelegate>delegate;

+ (instancetype)sharedInstance;

/// 初始化sdk
/// @param appid appid 需要申请
/// @param config 配置信息
+ (void)registerWithAppid:(NSString *)appid sdkConfig:(SINFeedSDKConfig * _Nullable)config;

/// 初始化feed流vc
+ (UIViewController *)feedVcInit;

/// SDK版本号
+ (NSString *)sdkVersion;

@end

NS_ASSUME_NONNULL_END
