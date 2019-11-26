//
//  SINCellItemModel.h
//  SINContentFramework
//
//  Created by wf on 2019/11/5.
//  Copyright © 2019 Sohu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 *  filterWord 数组中为字典，以下为key值
 */
extern NSString *const kCFModelFilterWordsKey_Type;
extern NSString *const kCFModelFilterWordsKey_Name;

typedef NS_ENUM(NSUInteger, SINFeedTemplateType) {
    SINFeedTemplateTypeUnkonwn = 0,
    SINFeedTemplateTypeRightSide = 1,        //右图
    SINFeedTemplateTypeBigImage = 2,         //大图
    SINFeedTemplateTypeMultipleImage = 3,    //多图
    SINFeedTemplateTypeNoImage = 4,          //无图
};

typedef NS_ENUM(NSUInteger, SIFeedContentType) {
    SIFeedContentTypeUnkonwn = 0,
    SIFeedContentTypeNormal = 1,            //图文
    SIFeedContentTypePicGroup = 2,          //组图
    SIFeedContentTypeVideo = 3,             //视频
};

typedef NS_ENUM(NSUInteger, SINTemplatePosition) {
    SINTemplatePositionFeed,
    SINTemplatePositionRelate
};

@class SINItemTableViewCell;
@protocol SINCellItemDelegate <NSObject>

- (Class)cellClass;

- (CGFloat)height;

@end

@interface SINCellItemModel : NSObject<SINCellItemDelegate>

@property (nonatomic, copy) NSString * articleUrl;
@property (nonatomic, assign) NSInteger commentNum;
@property (nonatomic, assign) NSInteger contentType;
@property (nonatomic, assign) NSTimeInterval createTime;
@property (nonatomic, strong) NSArray * filterWords;
@property (nonatomic, assign) NSInteger isRec;
@property (nonatomic, assign) NSInteger isTop;
@property (nonatomic, copy) NSString * keyword;
@property (nonatomic, copy) NSString * mediaFlagIcon;
@property (nonatomic, copy) NSString * mediaId;
@property (nonatomic, copy) NSString * mediaName;
@property (nonatomic, copy) NSString * newsId;
@property (nonatomic, assign) NSInteger picNum;
@property (nonatomic, strong) NSArray * pics;
@property (nonatomic, assign) NSInteger playCount;
@property (nonatomic, assign) NSInteger recommendEvent;
@property (nonatomic, assign) NSInteger recpool;
@property (nonatomic, assign) NSInteger recreason;
@property (nonatomic, assign) CGFloat score;
@property (nonatomic, assign) NSInteger state;
@property (nonatomic, assign) NSInteger subtype;
@property (nonatomic, assign) NSInteger templateType;
@property (nonatomic, copy) NSString * title;


@property (nonatomic, assign) SINTemplatePosition position;

@property (nonatomic, assign) NSTimeInterval virtualTime;

@end

NS_ASSUME_NONNULL_END
