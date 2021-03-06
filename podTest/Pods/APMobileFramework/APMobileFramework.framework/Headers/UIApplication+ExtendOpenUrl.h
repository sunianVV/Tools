//
//  UIApplication+ExtendOpenUrl.h
//  HuoYanSDK
//
//  Created by Moncter8 on 14-3-14.
//  Copyright (c) 2014年 Moncter8. All rights reserved.
//

#import <UIKit/UIKit.h>

#pragma mark - OpenURLOptions
extern NSString * const DFOpenURLOptionsSourceIdKey;

#pragma mark - ExtendOpenUrl
@interface UIApplication (ExtendOpenUrl)

/**
 *  在RC版本时，将URL的scheme变成schemerc格式，否则不变。
 *
 *  @param url 跳转的地址
 *
 *  @return 转换后的地址
 */
- (NSURL *)convertUrlInRcVersion:(NSURL *)url;

/**
 Attempts to open the resource at the specified URL with options synchronously.

 @param url A URL (Universal Resource Locator). 
 @param options A dictionary of options to use when opening the URL. For a list of possible keys to include in this dictionary, see OpenURLOptions.
 @return YES if the resource located by the URL was successfully handled; otherwise NO.
 */
- (BOOL)openURL:(NSURL *)url options:(NSDictionary *)options;

@end

#pragma mark - DTApplicationFilter
/*
 外部可通过 Category 的方式覆盖，仅可覆盖一次
 */
@interface DTApplicationFilter : NSObject

/**
 在发送给系统之前过滤URL
 此方法在系统处理内部scheme之后，在发送给系统之前。
 也就是 [[UIApplication sharedApplication] openURL:] 交控制权给系统之前

 @param name url
 @return YES 已处理，openURL流程将直接返回；NO 未处理，openURL流程将继续。
 */
+ (BOOL)filterOpenURL:(NSURL*)name;

@end


