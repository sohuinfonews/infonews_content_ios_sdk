//
//  SINAdRelatedViewManager.h
//  SINSSPADFramework
//
//  Created by 肖潇 on 2019/11/13.
//  Copyright © 2019 Sohu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SINNativeAd.h"
#import "SINAdRelatedView.h"
#import "SINAdConfig.h"


NS_ASSUME_NONNULL_BEGIN

@class SINAdRelatedViewManager;

@protocol SINAdRelatedManagerDelegate <NSObject>

@optional

/**
 * 加载广告时成功回调
 */
- (void)nativeExpressAdSuccessToLoad:(SINAdRelatedViewManager *)nativeExpressAd views:(NSArray<__kindof SINAdRelatedView *> *)views;

/**
 * 加载广告失败回调
 */
- (void)nativeExpressAdFailToLoad:(SINAdRelatedViewManager *)nativeExpressAd error:(NSError *_Nullable)error;

/**
 当relatedView视图广告成功加载时，将调用此方法。 (正常调用)
 @param relatedView : view for relatedView
 @param nativeAd : nativeAd for relatedView
 */
- (void)relatedViewDidLoad:(SINAdRelatedView *)relatedView WithAdmodel:(SINNativeAd *_Nullable)nativeAd;

/**
 当RelatedView广告加载失败时，将调用此方法。 （图片过大，尺寸传入不对。）
 @param error : the reason of error
 */
- (void)relatedViewRenderFail:(SINAdRelatedView *)relatedView Error:(NSError *_Nullable)error;

/**
 当RelatedView广告变得可视，将调用此方法。 （没有实现）
 */
- (void)relatedViewDidBecomVisible:(SINAdRelatedView *)relatedView WithAdmodel:(SINNativeAd *_Nullable)nativeAd;

/**
 单击RelatedView时将调用此方法。 （正常调用）
 */
- (void)relatedViewDidClick:(SINAdRelatedView *)relatedView WithAdmodel:(SINNativeAd *_Nullable)nativeAd;

@end


@interface SINAdRelatedViewManager : NSObject

@property (nonatomic, strong, nullable) SINAdConfig *adConfig;

@property (nonatomic, assign, readwrite) CGSize adSize;

/**
 The delegate for receiving state change messages from a SINAdRelatedManagerDelegate
 */
@property (nonatomic, weak, nullable) id<SINAdRelatedManagerDelegate> delegate;


/**
 @param size 预期广告视图大小，当大小为零时，高度将变成最适合的高度。（SINAdRelatedView可以取到）
 */
- (instancetype)initWithAdConfig:(SINAdConfig *)adConfig adSize:(CGSize)size;

/**
 The number of ads requested,The maximum is 3
 */
- (void)loadAd:(NSInteger)count;

@end

NS_ASSUME_NONNULL_END
