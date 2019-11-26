//
//  SINADMaterialModel.h
//  SINSSPADFramework
//
//  Created by JiaLei on 2019/10/21.
//  Copyright © 2019 Sohu. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class SINAdImageModel;

typedef NS_ENUM(NSInteger, SINAdActionType) {
    SINAdActionType_web        = 1,   // webview进入
    SINAdActionType_download   = 6,   // 下载
    SINAdActionType_deeplink   = 7,   // deeplink
};



@interface SINAdMaterialModel : NSObject

@property (nonatomic, copy, readonly) NSString *positionId; // 广告位id,值为集团商业部的id
@property (nonatomic, copy, readonly) NSString *sourceId; // 广告来源的平台id ,第三方广告平台id
@property (nonatomic, copy, readonly) NSString *adLoadId;
@property (nonatomic, copy, readonly) NSString *source; // app前端展示的   来自某某，暂时定为空
@property (nonatomic, copy, readonly) NSString *adid;  //id
@property (nonatomic, copy, readonly) NSArray <SINAdImageModel *>*pics;  //id 封面图列表 (含有宽高，描述，url)
@property (nonatomic, assign, readonly) NSInteger position; // 位置(第几位)，从1开始
@property (nonatomic, copy, readonly) NSString *title;  // 标题
@property (nonatomic, assign, readonly) NSInteger type;  // template: 1:大图，2，图文，3:视频
@property (nonatomic, assign, readonly) NSInteger action;
@property (nonatomic, copy, readonly) NSString *url;  // 广告点击后的url
@property (nonatomic, copy, readonly) NSString *deeplinkUrl;  // action为7时的url字段
@property (nonatomic, copy, readonly) NSArray <NSString *>*impTrackers;
@property (nonatomic, copy, readonly) NSArray <NSString *>*clickTrackers;
@property (nonatomic, copy, readonly) NSString *sspSourceId;
@property (nonatomic, copy, readonly) NSString *sspName;  // 广告点击后的url

@end

NS_ASSUME_NONNULL_END
