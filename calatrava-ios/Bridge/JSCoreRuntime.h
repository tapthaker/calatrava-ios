//
//  JSCoreRuntime.h
//  Pods
//
//  Created by Tapan Thaker on 26/03/15.
//
//

#import <Foundation/Foundation.h>
#import "JsRuntime.h"
#import "BridgeJSProtocol.h"

@interface JSCoreRuntime : NSObject<JsRuntime, BridgeJSProtocol>

@property (nonatomic, strong) id<JsRtPageDelegate> pageDelegate;
@property (nonatomic, strong) id<JsRtTimerDelegate> timerDelegate;
@property (nonatomic, strong) id<JsRtRequestDelegate> requestDelegate;
@property (nonatomic, strong) id<JsRtUiDelegate> uiDelegate;
@property (nonatomic, strong) id<JsRtPluginDelegate> pluginDelegate;

@end
