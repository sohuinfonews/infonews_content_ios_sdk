//
//  SINNativeAd.h
//  SINSSPADFramework
//
//  Created by 肖潇 on 2019/10/21.
//  Copyright © 2019 Sohu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "SINAdMaterialModel.h"
#import "SINAdConfig.h"


NS_ASSUME_NONNULL_BEGIN
@protocol SINNativeAdDelegate;


@interface SINNativeAd : NSObject

// -----   测试代码  ------
@property (nonatomic, assign) NSInteger adType;

/**
 Ad Config description.  AdConfig
 */
@property (nonatomic, strong, readwrite, nullable) SINAdConfig *adConfig;

/**
 Ad Config 的原始数据.
 */
@property (nonatomic, strong, nullable) SINAdMaterialModel *data;

/**
 用于接收状态改变消息的代理。委派不限于视图控制器。<SINNativeAdDelegate>.
 */
@property (nonatomic, weak, readwrite, nullable) id<SINNativeAdDelegate> delegate;

/**
 required.
 用于处理广告操作的根视图控制器。动作方法包括“pushViewController”和“presentViewController”。
 */
@property (nonatomic, weak, readwrite) UIViewController *rootViewController;

/**
 使用ad配置初始化本机广告。
 @param adConfig : ad的生成配置文件.
               包括配置ID，adype，图片尺寸等等
 @return SINNativeAd
 */
- (instancetype)initWithAdConfig:(SINAdConfig *)adConfig;

/**
 注册可点击的视图
 */
- (void)registerContainer:(__kindof UIView *)containerView;

/**
 从本机广告中取消注册广告视图。
 */
- (void)unregisterView;

/**
 主动请求NativeAD数据。
 */
- (void)loadAdData;

/**
 广告呈现时调用该方法，(支持重复上报，初期有，后期找替代方式)
 */
- (void)adPresented;

/**
 广告点击时调用该方法 (初期有，后期找替代方式)
 */
- (void)adClicked;


@end


@protocol SINNativeAdDelegate <NSObject>

@optional

/**
 当成功加载本地广告材料时，将调用此方法。
 */
- (void)nativeAdDidLoad:(SINNativeAd *)nativeAd;

/**
 此方法在本地AD材料无法加载时调用。
 @param error : the reason of error
 */
- (void)nativeAd:(SINNativeAd *)nativeAd didFailWithError:(NSError *_Nullable)error;

/**
 变得可见的时候调用。 (暂未加入)
 */
- (void)nativeAdDidBecomeVisible:(SINNativeAd *)nativeAd;

/**
 当另一个控制器关闭时，将调用此方法。 (暂未加入)
 
 */
- (void)nativeAdDidCloseOtherController:(SINNativeAd *)nativeAd;

/**
 单击本机广告时将调用此方法。(暂未加入)
 */
- (void)nativeAdDidClick:(SINNativeAd *)nativeAd withView:(UIView *_Nullable)view;

@end

NS_ASSUME_NONNULL_END
