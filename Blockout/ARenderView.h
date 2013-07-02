#import <Cocoa/Cocoa.h>

#import "ABlockout.h"

//==============================================================================

@interface ARenderView : NSOpenGLView
{
@private
    ABlockout* _blockout;
    
	NSTimer* _animationTimer;
	NSTimeInterval _animationInterval;
	NSTimeInterval _animationStarted;
    
    BOOL _openGLInited;
}

- (void) initRender;

@end
