//
//  DTFrameworkInterface+podTest.m
//  podTest
//
//  Created by lishuguang915163.com on 2021/11/02. All rights reserved.
//

#import "DTFrameworkInterface+podTest.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wobjc-protocol-method-implementation"

@implementation DTFrameworkInterface (podTest)

- (BOOL)shouldLogReportActive
{
    return YES;
}

- (NSTimeInterval)logReportActiveMinInterval
{
    return 0;
}

- (BOOL)shouldLogStartupConsumption
{
    return YES;
}

- (BOOL)shouldAutoactivateBandageKit
{
    return YES;
}

- (BOOL)shouldAutoactivateShareKit
{
    return YES;
}

- (DTNavigationBarBackTextStyle)navigationBarBackTextStyle
{
    return DTNavigationBarBackTextStyleAlipay;
}
- (void)application:(UIApplication *)application beforeDidFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
     
//    [WXApi registerApp:@"wx90fd655719a5641a"
//         universalLink :@"https://jq8qy.share2dlink.com/"];
    //  预置离线包 的 包信息路径。
    NSString *presetApplistPath = [[NSBundle mainBundle] pathForResource:[NSString stringWithFormat:@"FT.bundle/h5_json.json"] ofType:nil];
    // 离线包路径
    NSString *appPackagePath = [[NSBundle mainBundle] pathForResource:[NSString stringWithFormat:@"FT.bundle"] ofType:nil];
    // JSAPI 和 Plugin 文件的存储路径。
    NSString *pluginsJsapisPath = [[NSBundle mainBundle] pathForResource:[NSString stringWithFormat:@"DemoCustomPlugins.bundle/Poseidon-UserDefine-Extra-Config.plist"] ofType:nil];
    // 初始化容器
//    [MPNebulaAdapterInterface initNebulaWithCustomPresetApplistPath:presetApplistPath customPresetAppPackagePath:appPackagePath customPluginsJsapisPath:pluginsJsapisPath];
 
}

- (void)application:(UIApplication *)application afterDidFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    //    设置容器基类
//    [MPNebulaAdapterInterface shareInstance].nebulaVeiwControllerClass = [FTH5WebViewController class];
//    [MPNebulaAdapterInterface shareInstance].nebulaNeedVerify = NO;
//    [[MPNebulaAdapterInterface shareInstance] requestAllNebulaApps:^(NSDictionary *data, NSError *error) {
//        NSLog(@"%@", data);
//    }];
}
@end

#pragma clang diagnostic pop

