//
//  SINAdConfig.h
//  SINSSPADFramework
//
//  Created by 肖潇 on 2019/10/22.
//  Copyright © 2019 Sohu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SINSize.h"


// 后删除
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, SINAdAdType) {
    SINAdAdTypeUnknown       = 0,
    SINAdAdTypeBanner        = 1,       // banner广告
    SINAdAdTypeInterstitial  = 2,       // 中插广告
    SINAdAdTypeSplash        = 3,       // 开屏广告
    SINAdAdTypeFeed          = 4,       // feeds流 ads
    SINAdAdTypePaster        = 5,       // 粘贴广告 ads
    SINAdAdTypeRewardVideo   = 6,       // 激励视频 ads
    SINAdAdTypeFullscreenVideo = 6,     // 全屏视频广告 ads
    SINAdAdTypeDrawVideo     = 8,       // 沉浸式视频 ads
};

typedef NS_ENUM(NSInteger, SINAdPosition) {
    SINAdPositionTop = 1,         // 顶部
    SINAdPositionBottom = 2,      // 底部
    SINAdPositionFeed = 3,        // feed
    SINAdPositionMiddle = 4,      // 仅（空隙，中插）
    SINAdPositionFullscreen = 5,  // 全屏
};


@interface SINAdConfig : NSObject

/// required必填. 广告iD
@property (nonatomic, copy) NSString *adId;

/// required必填. Ad type.
@property (nonatomic, assign) SINAdAdType adType;

/// required必填. Ad 展现位置
@property (nonatomic, assign) SINAdPosition position;

/// required必填. 图片的尺寸.(暂未加入)
@property (nonatomic, strong) SINSize *imgSize;

/// 接受一组图像大小(暂未加入)
@property (nonatomic, strong) NSMutableArray<SINSize *> *imgSizeArray;

/// Icon 的尺寸.(暂未加入)
@property (nonatomic, strong) SINSize *iconSize;


// todo: 不需要暴露出去
// 之后“扩展”出去的属性。目前先放到这个位置  网络开屏广告超时时间 （目前只有splash在使用）
@property (nonatomic, assign) CGFloat tolerateTimeout;




@end


