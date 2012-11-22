#import <UIKit/UIKit.h>
#import "BaseUIViewController.h"

@interface WebViewController :  BaseUIViewController <UIWebViewDelegate>{
    
    UIWebView *_webView;
    NSMutableOrderedSet *queuedBinds;
    NSMutableOrderedSet *queuedRenders;
    BOOL webViewReady;
}

- (NSString *)pageName;

- (id)scrollToTop;

- (void)displayDialog:(NSString *)dialogName;

@end
