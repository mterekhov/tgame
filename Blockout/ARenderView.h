#import <Cocoa/Cocoa.h>
#import <OpenGL/OpenGL.h>

#import "ABlockout.h"

//==============================================================================

@interface ARenderView : NSOpenGLView
{
@private
    ABlockout* _blockout;
}

- (void) initRender;
@end
