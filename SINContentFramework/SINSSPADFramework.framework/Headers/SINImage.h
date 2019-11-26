//
//  SINImage.h
//  SINSSPADFramework
//
//  Created by 肖潇 on 2019/10/22.
//  Copyright © 2019 Sohu. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SINImage : NSObject

// image address URL
@property (nonatomic, copy) NSString *imageURL;

// image widthf
@property (nonatomic, assign) float width;

// image height
@property (nonatomic, assign) float height;

- (instancetype)initWithDictionary:(NSDictionary *)dic;


@end

NS_ASSUME_NONNULL_END
