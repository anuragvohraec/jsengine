#import "JsenginePlugin.h"
#import <jsengine/jsengine-Swift.h>

@implementation JsenginePlugin
+ (void)registerWithRegistrar:(NSObject<FlutterPluginRegistrar>*)registrar {
  [SwiftJsenginePlugin registerWithRegistrar:registrar];
}
@end
