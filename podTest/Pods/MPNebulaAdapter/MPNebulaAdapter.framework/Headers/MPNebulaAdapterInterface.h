//
//  MPNebulaAdapterInterface.h
//  MPNebulaAdapter
//
//  Created by yangwei on 2019/2/12.
//  Copyright © 2019年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MPNebulaAdapterInterface : NSObject

+(instancetype)shareInstance;

/**
 初始化Nebula容器。必须在容器加载前初始化，建议在didFinishLauncher方法中调用
 */
+ (void)initNebula;

/**
 基于Nebula容器创建的H5页面的VC基类，默认为 UIViewController。若需定制H5页面所在的VC，可自定义VC后设置此属性
 注意：若当前应用集成了小程序，自定义的基类必须继承 'H5WebViewController'
 */
@property (nonatomic, strong) Class nebulaVeiwControllerClass;

/**
 基于Nebula容器创建的H5页面嵌入的webview基类，默认为 UIWebView。若需定制H5页面的webview，可自定义webview后设置此c属性
 */
@property (nonatomic, strong) Class nebulaWebViewClass;

/**
 设置当前应用所有基于Nebula容器创建的H5页面的 UserAgent
 */
@property (nonatomic, strong) NSString *nebulaUserAgent;

/**
离线包是否验签，默认为YES，即Nebula容器默认对下载的离线包验签。调试期间如需要关闭验签，此属性设置为 NO
 */
@property (nonatomic, assign) BOOL nebulaNeedVerify;

/**
 离线包验签的公钥路径，默认为nil。若离线包验签开关为YES，此处必须设置对应的公钥，否则本地验签不通过导致离线包加载失败
 */
@property (nonatomic, strong) NSString *nebulaPublicKeyPath;

/**
 全局资源包列表
 */
@property (nonatomic, strong) NSArray *nebulaCommonResourceAppList;

/**
 当H5页面加载失败时展示的html错误页路径，默认读取 MPNebulaAdapter.bundle/error.html
 */
@property (nonatomic, strong) NSString *errorHtmlPath;

/**
 *  基于在线url，创建一个H5容器
 *
 *  @param params H5容器的启动参数，必填参数：url，其他可选参数参考文档 https://tech.antfin.com/docs/2/85001
 *
 */
- (void)startH5ViewControllerWithParams:(NSDictionary *)params;

/**
 *  基于传入的离线包信息，创建一个H5容器，并自动push打开
 *
 *  @param params H5容器的启动参数，必填参数：appId，其他可选参数参考文档 https://tech.antfin.com/docs/2/85001
 *
 */
- (void)startH5ViewControllerWithNebulaApp:(NSDictionary *)params;

/**
 *  基于传入的离线包信息，创建一个H5容器，并返回创建的H5容器实例。一般用在首页tab页面
 *
 *  @param params H5容器的启动参数，必填参数：appId，其他可选参数参考文档 https://tech.antfin.com/docs/2/85001
 *
 *  @return 创建的H5容器vc实例
 */
- (UIViewController *)createH5ViewControllerWithNebulaApp:(NSDictionary *)params;

/**
 *  全量更新本地离线包信息
 *
 *  @param finish 完成回调
 *
 */
- (void)requestAllNebulaApps:(NAMRequestFinish)finish;

/**
 *  单个应用请求
 *
 *  注:
 *      9.9.9前: 请求成功后Wifi下自动下载离线包,非Wifi只下载auto_install为YES的离线包
 *      9.9.9及之后: 可针对每个应用配置下载时机, 通过服务端配置, 默认WIFI下载
 *
 *  @param params   请求列表 格式:{appid:version},可传多个appid,不指定version时传空传,默认取最高版本
 *                支持版本号模糊匹配 e.g. '*' 匹配最高版本号 '1.*' 匹配1开头的版本号总最高版本号等,最长4位
 *  @param finish 完成回调
 */
- (void)requestNebulaAppsWithParams:(NSDictionary *)params finish:(NAMRequestFinish)finish;


/**
 *  全量下载包信息池中的离线包
 *
 *
 */
- (void)downLoadAllNebulaApps;

/**
 *  批量下载指定的离线包
 *
 *  @param params 字典{appId:version},指定要下载的appId和版本号,从包管理池中读取并下载
 */
- (void)downLoadNebulaAppsWithParams:(NSDictionary *)params;

/**
 *  安装离线包
 *
 *  @param app         离线包信息，可通过findApp：查找
 *  @param process   安装过程回调, 过程包含: 异步下载离线包->解压离线包
 *  @param finish       安装完成的回调
 */
- (void)installNebulaApp:(NAMApp *)app
                 process:(NAMAppInstallProcess)process
                  finish:(NAMAppInstallFinish)finish;
@end

NS_ASSUME_NONNULL_END
