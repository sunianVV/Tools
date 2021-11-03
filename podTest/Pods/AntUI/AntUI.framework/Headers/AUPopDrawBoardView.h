#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_PopTip//程序自动生成
//
//  AUPopDrawBoardView.h
//  AntUI
//
//  Created by 沫竹 on 2018/3/15.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <AntUI/AntUI.h>

typedef NS_ENUM(NSInteger, AUPopViewIndicatorDirection) {
    AUPopViewIndicatorDirectionUp,
    AUPopViewIndicatorDirectionDown,
};

@interface AUPopDrawBoardView : AUView

@property (nonatomic,strong) UIColor * triangleBorderColor;

@property (nonatomic, strong) UIView *customView;

//dismiss的时候回去执行代码
@property (nonatomic, copy) void (^actionOnDismiss)();

- (void)dismiss:(BOOL)animated;

@property (nonatomic, assign) AUPopViewIndicatorDirection indicatorDirection;


- (instancetype)initWithCustomView:(UIView *)customView;

- (void)showFromView:(UIView *)fromView
           fromPoint:(CGPoint)fromPoint
              toView:(UIView *)toView;

- (void)showFromView:(UIView *)fromView
           fromPoint:(CGPoint)fromPoint
              toView:(UIView *)toView
            animated:(BOOL) animated;

/**
 是否启用遮罩视图A
 1、启用遮罩视图会在toView上增加一层遮罩视图，当用户触摸这个遮罩视图时，会将本视图消失
 2、创建本视图时，默认是带有遮罩视图的，可以调用此方法将遮罩视图去掉
 
 @param enable YES，是；NO，不是
 */
- (void)enableMaskView:(BOOL)enable;


- (void)updateFrameFromCustomView;

@end

#endif//程序自动生成
