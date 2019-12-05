//
//  SINSSPADManager.h
//  SINSSPADFramework
//
//  Created by JiaLei on 2019/10/17.
//  Copyright © 2019 Sohu. All rights reserved.
//  2019年12月05日17:33:19

#import <Foundation/Foundation.h>
#import "SINAdManager.h"


NS_ASSUME_NONNULL_BEGIN

@interface SINAdManager : NSObject

+ (void)registerWithAppid:(NSString *)appid;

+ (NSString *)SDKVersion;

+ (void)debugMode;

@end

NS_ASSUME_NONNULL_END
