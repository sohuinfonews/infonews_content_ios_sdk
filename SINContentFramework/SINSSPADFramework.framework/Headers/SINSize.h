//
//  SINSize.h
//  SINSSPADFramework
//
//  Created by 肖潇 on 2019/10/22.
//  Copyright © 2019 Sohu. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 使用预定义的大小（以像素为单位）以获得最佳结果的视图。在查看显示时，建议使用相同的缩放比例。
*/
typedef NS_ENUM(NSInteger, SINProposalSize) {
    SINProposalSize_Banner600_90 = 0,
    SINProposalSize_Banner600_100,
    SINProposalSize_Banner600_150,
    SINProposalSize_Banner600_260,
    SINProposalSize_Banner600_286,
    SINProposalSize_Banner600_300,
    SINProposalSize_Banner600_388,
    SINProposalSize_Banner600_400,
    SINProposalSize_Banner600_500,
    SINProposalSize_Feed228_150,
    SINProposalSize_Feed690_388,
    SINProposalSize_DrawFullScreen
};

NS_ASSUME_NONNULL_BEGIN

@interface SINSize : NSObject

// width unit pixel.
@property (nonatomic, assign) NSInteger width;

// height unit pixel.
@property (nonatomic, assign) NSInteger height;


+ (instancetype)sizeBy:(SINProposalSize)proposalSize;


@end

NS_ASSUME_NONNULL_END
