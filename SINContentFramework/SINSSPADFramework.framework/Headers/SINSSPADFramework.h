//
//  SINSSPADFramework.h
//  SINSSPADFramework
//
//  Created by JiaLei on 2019/10/17.
//  Copyright © 2019 Sohu. All rights reserved.
//

#import <Foundation/Foundation.h>

// 初始化
#import "SINAdManager.h"
// 自渲染
#import "SINNativeAd.h"
// 开屏广告
#import "SINAdSplashView.h"
// 横幅广告（feeds流）
#import "SINAdRelatedView.h"
#import "SINAdRelatedViewManager.h"


//! Project version number for SINSSPADFramework.
FOUNDATION_EXPORT double SINSSPADFrameworkVersionNumber;

//! Project version string for SINSSPADFramework.
FOUNDATION_EXPORT const unsigned char SINSSPADFrameworkVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <SINSSPADFramework/PublicHeader.h>


// 这些都是对内的 之后再换地方
#define APPSTORE_HOST_ITUNES      @"itunes.apple.com"
#define APPSTORE_HOST_APPS      @"apps.apple.com"

// 广告跳转页面
typedef NS_ENUM(NSInteger, SADAdClickActionType) {
    SADAdClickActionType_Unknown ,
    SADAdClickActionTypeWebview ,    // webview
    SADAdClickActionTypeDownload ,   // 下载
    SADAdClickActionTypeDeepLink     // deeplink
};

// 优先跳转的方式  1.默认逻辑（根据nativeAd来做判断） 2.video 视频  3. webview
typedef NS_ENUM(NSInteger, SADAdJumpType) {
    SADAdJumpType_default ,  // 根据nativeAd来做判断: deeplink -> App Store -> webview
    SADAdJumpType_video ,    // video的逻辑 ： deeplink -> video -> webview
    SADAdJumpType_splash     // 开屏广告（必须是present 出现，有额外判断，逻辑和default基本一致)
};


