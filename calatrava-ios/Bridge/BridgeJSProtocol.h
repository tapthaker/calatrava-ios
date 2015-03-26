
#import <JavaScriptCore/JavaScriptCore.h>

@protocol BridgeJSProtocol <JSExport>

- (id)changeToPage:(NSString *)target;
- (id)registerProxy:(NSString *)proxy forPage:(NSString *)name;
- (id)attachHandlerTo:(NSString *)proxy forEvent:(NSString *)name;
- (id)valueFrom:(NSString *)proxy forField:(NSString *)field returnedTo:(NSString *)getId;
- (id)render:(NSString *)proxy with:(NSDictionary *)dataMsg;
- (id)requestFrom:(NSString *)reqId
              url:(NSString *)url
               as:(NSString *)method
             with:(NSString *)body
          headers:(NSDictionary *)headers;
- (id)openUrl:(NSString *)url;
- (id)startTimer:(NSString *)timerId timeout:(int)timeout;
- (id)callPlugin:(NSString *)plugin
          method:(NSString *)method
        withArgs:(NSDictionary *)args;

@end
