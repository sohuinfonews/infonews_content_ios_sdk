//
//  SINAdSplashView.h
//  SINSSPADFramework
//
//  Created by 肖潇 on 2019/10/21.
//  Copyright © 2019 Sohu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "SINAdSDKError.h"

NS_ASSUME_NONNULL_BEGIN

/**
 开屏样式类型

 - SINAdSplashUITypeDefault: 默认样式
 - SINAdSplashUITypeFullScreen: 全屏样式
 */
typedef NS_ENUM(NSUInteger, SINAdSplashUIType) {
    SINAdSplashUITypeDefault = 0,
    SINAdSplashUITypeFullScreen,
};

@class SINAdSplashView;

@protocol SINAdSplashDelegate <NSObject>
@optional

/**
 广告数据请求失败
 
 @param splash 实例
 @param error 错误
 */
- (void)nativeAd:(SINAdSplashView *)splash didFailWithError:(NSError *_Nullable)error;

/**
 广告已经展示在屏幕上
 */
- (void)splashDidPresentScreen:(SINAdSplashView *)splash;

/**
 广告即将在屏幕上消失（如果进入了广告落地页，这个回调会在关闭落地页之后调用）
 */
- (void)splashWillDismissScreen:(SINAdSplashView *)splash;

/**
 开屏广告已经在屏幕上消失（如果进入了广告落地页，这个回调会在关闭落地页之后调用）
 */
- (void)splashDidDismissScreen:(SINAdSplashView *)splash;

/**
 广告落地页，消失的时候调用
 */
- (void)splashLandingPageDidClose:(SINAdSplashView *)splash;

/**
 广告被点击
 */
- (void)splashDidClick:(SINAdSplashView *)splash;

/**
 自定义品牌区域视图
 可根据UI类型，返回不同样式的logo视图

 @param splash 实例
 @param type 开屏广告UI类型
 @return 自定义品牌区域视图
 */
- (UIView *)splash:(SINAdSplashView *)splash logoViewForUIType:(SINAdSplashUIType)type;
@end


@interface SINAdSplashView : NSObject

/**
  允许请求超时时间，默认3秒（单位:秒）
 */
@property (nonatomic, assign) NSTimeInterval tolerateTimeout;

/**
 是否隐藏“跳过”的按钮，默认是NO。如果隐藏隐藏了跳过按钮，您需要自定义倒计时 （暂时未加）
 */
@property (nonatomic, assign) BOOL hideSkipButton;

/**
 用于接收状态更改消息的委托
 */
@property (nonatomic, weak, nullable) id<SINAdSplashDelegate> delegate;

/*
 required.
 用于处理广告操作的根视图控制器 (必传项。如果不传无法展示)
 */
@property (nonatomic, weak) UIViewController *rootViewController;

/**
 是否加载了Splash广告数据（暂时未加）
 */
@property (nonatomic, getter=isAdValid, readonly) BOOL adValid;


/**
 初始化开屏广告的方法
 @param adID : 广告ID，必传
 @param frame : splashAd的frame. 建议按照手机屏幕大小传入（UIScreen.main.bounds）
 @return SINAdSplashView
 */
- (instancetype)initWithAdID:(NSString *)adID frame:(CGRect)frame;

/**
 加载开屏广告
 请求数据后，立即启动倒计时（tolerateTimeout）
 */
- (void)loadAdData;

@end

NS_ASSUME_NONNULL_END
