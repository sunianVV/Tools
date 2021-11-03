//
//  MPMpaaSServiceInterface.h
//  MPMpaaSService
//
//  Created by yangwei on 2019/2/24.
//  Copyright © 2019年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MPMpaaSServiceInterface : NSObject

@property(nonatomic, strong) NSDictionary *nebulaUuids;

+ (instancetype)sharedInstance;

/**
 *  获取当前nebula包的appId
 *
 */
- (NSDictionary *)getNebulaUuids;

@end

NS_ASSUME_NONNULL_END
