#import "ARenderView.h"

//==============================================================================

@implementation ARenderView

//==============================================================================

- (id)initWithFrame:(NSRect)frame pixelFormat:(NSOpenGLPixelFormat*)format
{
    self = [super initWithFrame:frame pixelFormat:format];
    if (self == nil)
        return nil;

    return self;
}

//==============================================================================

- (void) initRender
{
    [self initContext:self.pixelFormat];
    [self initGL];
}

//==============================================================================

- (void) initContext:(NSOpenGLPixelFormat*)format
{
	NSOpenGLContext* viewContext = [[NSOpenGLContext alloc] initWithFormat: format
                                                              shareContext: nil];
    [self setOpenGLContext: viewContext];
    [viewContext makeCurrentContext];
    [viewContext setView: self];
}

//==============================================================================

- (void) initGL
{
	glClearColor(0.0, 0.0, 0.0, 0.0); // Clear background color to black
    glViewport(0, 0, self.bounds.size.width, self.bounds.size.height);
	
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-self.bounds.size.width, self.bounds.size.width, -self.bounds.size.height, self.bounds.size.height, 0.1f, 10000.0f);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glEnable(GL_DEPTH_TEST);
	glClearDepth(1.0);
	glDepthFunc(GL_LESS);

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_CULL_FACE);
	glShadeModel(GL_SMOOTH); // Type of shading for the polygons
}

//==============================================================================

- (void)drawRect:(NSRect)dirtyRect
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	[[NSOpenGLContext currentContext] flushBuffer];
}

//==============================================================================

@end
