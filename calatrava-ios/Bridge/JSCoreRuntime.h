//
//  JSCoreRuntime.h
//  Pods
//
//  Created by Tapan Thaker on 26/03/15.
//
//

#import <Foundation/Foundation.h>
#import "JsRuntime.h"

@interface JSCoreRuntime : NSObject<JsRuntime>{
    
    BOOL isLoadingHtml;
    int outstandingScriptLoads;
    NSMutableArray *filesToLoad;
    NSMutableArray *functionsToCall;
    
    id<JsRtPageDelegate> pageDelegate;
    id<JsRtTimerDelegate> timerDelegate;
    id<JsRtRequestDelegate> requestDelegate;
    id<JsRtPluginDelegate> pluginDelegate;
}

@property (nonatomic, strong) id<JsRtPageDelegate> pageDelegate;
@property (nonatomic, strong) id<JsRtTimerDelegate> timerDelegate;
@property (nonatomic, strong) id<JsRtRequestDelegate> requestDelegate;
@property (nonatomic, strong) id<JsRtUiDelegate> uiDelegate;
@property (nonatomic, strong) id<JsRtPluginDelegate> pluginDelegate;

- (id)init;

@end
