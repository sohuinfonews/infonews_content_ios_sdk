//
//  SINAdSDKError.h
//  SINSSPADFramework
//
//  Created by 肖潇 on 2019/10/22.
//  Copyright © 2019 Sohu. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


typedef NS_ENUM(NSInteger, SINErrorCode) {
    
    // AdConfig -> nativeAd
    SINErrorCodeAppEmpty           = 100001,    // 请求参数中的app为空
    SINErrorCodeAdConfigEmpty      = 100002,    // 参数AdConfig缺失
    SINErrorCodeAdConfigIDError    = 100003,    // 参数AdConfig中的ADID错误
    SINErrorCodeAdConfigSizeEmpty  = 100004,    // 参数AdConfig中的图片大小错误
    SINErrorCodeAdCountError       = 100005,    // 索取错误数量的广告
    SINUnionAdImageSizeError       = 100006,    // 图像尺寸错误
    
    // 通过AdConfig 网络请求的错误
    SINErrorCodeParamError       = 200001,    // 参数错误
    SINErrorCodeTimeout          = 200002,    // 超时
    SINErrorCodeNOAD             = 200003,    // 没有广告
    SINErrorCodeNetError         = 200004,    // 网络请求失败
    SINErrorCodeParseError       = 200005,    // 解析失败
    SINErrorCodeTempError        = 200006,    // native 模板失效
    SINUnionAppSiteRelError      = 200007,    // config中的ADId和app_id之间的关系无效
    
    // nativeAd渲染的错误
    SINErrorCodeNERenderResultError= 101,    // native Express ad, 渲染结果失败
    SINErrorCodeNETempError        = 102,    // native Express ad, 模板无效
    SINErrorCodeNEDataError        = 104,    // native Express ad, 数据是失效的
    SINErrorCodeNEParseError       = 105,    // native Express ad, 解析失败
    SINErrorCodeNERenderError      = 106,    // native Express ad, 渲染失败
    SINErrorCodeNERenderTimoutError= 107,    // native Express ad, 渲染超时
    
    
    // 落地页 和 App Store 相关
    SINErrorCodeOpenAPPStoreFail = 310001,   // 打开App Store失败
    
    // SDK相关的错误码、Debug错误、其他错误
    SINErrorNativeError          = 400000,     // 原生错误
    SINErrorCodeSDKStop          = 400001,     // SDK 被强制结束
    SINErrorCodeAdPackageIncomplete  = 400002, // SDK包不完整。建议验证SDK包的完整性或联系技术支持。
    SINUnionRequestLimitError    = 400003,    // 开发人员注册的广告空间超过每日请求限制。
    SINUnionLowVersion           = 400004,    // SDK版本太低，无法返回广告
    SINErrorADNotShowError       = 400005,    // 广告有数据但是不展示
    SINErrorCodeSuccess          = 200        // 请求成功
};


@interface SINAdSDKError : NSError

@property (nonatomic, assign, readonly) SINErrorCode errorCode;
/// 错误描述
@property (nonatomic, copy, readonly) NSString *errorDescription;


/// 错误描述
/// @param code 错误码(SINErrorCode)
+ (NSString *)descriptionWithError:(SINErrorCode)code;


/// 创建SINAdSDKError
/// @param code 错误码(SINErrorCode)
+ (SINAdSDKError *)errorCode:(SINErrorCode)code;




@end

NS_ASSUME_NONNULL_END
