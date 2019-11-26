//
//  SINSSPADManager.h
//  SINSSPADFramework
//
//  Created by JiaLei on 2019/10/17.
//  Copyright © 2019 Sohu. All rights reserved.
//  2019年11月22日16:46:51

#import <Foundation/Foundation.h>
#import "SINAdManager.h"


NS_ASSUME_NONNULL_BEGIN

@interface SINAdManager : NSObject

+ (void)registerWithAppid:(NSString *)appid;

+ (NSString *)SDKVersion;

@end

NS_ASSUME_NONNULL_END
