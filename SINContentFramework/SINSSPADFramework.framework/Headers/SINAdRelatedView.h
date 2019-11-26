//
//  SINAdRelatedView.h
//  SINSSPADFramework
//
//  Created by 肖潇 on 2019/11/4.
//  Copyright © 2019 Sohu. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SINNativeAd.h"
#import "SINSize.h"

NS_ASSUME_NONNULL_BEGIN

// 目前有内存泄露的bug。
@interface SINAdRelatedView : UIView

/// 广告展示的label。可以在外部修改属性
@property (nonatomic, weak, readonly, nullable) UILabel *adLabel;
 
/// 广告展示的imageView。可以在外部修改属性
@property (nonatomic, weak, readonly, nullable) UIImageView *logoImageView;

// 必传（用于广告落地页跳转）
@property (nonatomic, weak) UIViewController *rootViewController;

/**
 Ad Config material. (后期藏起来)
 */
@property (nonatomic, strong, nullable) SINNativeAd *nativeAd;

/**
 required
 */
- (void)render;

@end


NS_ASSUME_NONNULL_END
