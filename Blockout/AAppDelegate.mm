#import "AAppDelegate.h"
#import "ARenderView.h"

//==============================================================================

@implementation AAppDelegate

//==============================================================================

- (void)dealloc
{
    [super dealloc];
}

//==============================================================================

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification
{
    // Insert code here to initialize your application
    
	NSOpenGLPixelFormatAttribute attrs [] = {
		NSOpenGLPFANoRecovery,
		NSOpenGLPFAWindow,
		NSOpenGLPFAColorSize, 32,
		NSOpenGLPFADepthSize, 32,
		NSOpenGLPFAMaximumPolicy,
		NSOpenGLPFADoubleBuffer,
		NSOpenGLPFAAccelerated,
		0
	};
	NSOpenGLPixelFormat* pixelFormat = [[[NSOpenGLPixelFormat alloc] initWithAttributes: attrs] autorelease];

    ARenderView* view = [[[ARenderView alloc] initWithFrame: _window.frame
                                                pixelFormat: pixelFormat] autorelease];
    [_window setContentView:view];
    [_window makeFirstResponder: view];
    [view initRender];
}

//==============================================================================

@end
