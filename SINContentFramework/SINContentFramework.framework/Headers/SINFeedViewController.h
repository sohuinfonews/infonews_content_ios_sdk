//
//  SINFeedBaseViewController.h
//  SINContentFramework
//
//  Created by wf on 2019/11/5.
//  Copyright © 2019 Sohu. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class SINCellItemModel;
@interface SINFeedViewController : UIViewController

- (void)showDislikeView:(UIView *)originView feedModel:(SINCellItemModel *)feedModel;

@end

NS_ASSUME_NONNULL_END
