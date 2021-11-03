//
//  APWebImageInterface.h
//  APWebImage
//
//  Created by yangwei on 2019/6/28.
//  Copyright © 2019 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface APWebImageInterface : NSObject

+ (id)sharedInstance;

// 同时下载图片的最大个数，默认为8
@property (nonatomic, assign) NSInteger maxDownloadImagesCount;

@end

NS_ASSUME_NONNULL_END
