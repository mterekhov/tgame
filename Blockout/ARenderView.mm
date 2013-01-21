#import "ARenderView.h"
#import "DrawTypes.h"

//==============================================================================

@implementation ARenderView

//==============================================================================

- (id)initWithFrame:(NSRect)frame pixelFormat:(NSOpenGLPixelFormat*)format
{
    self = [super initWithFrame:frame pixelFormat:format];
    if (self == nil)
        return nil;
    
    _blockout = 0;

    return self;
}

//==============================================================================

- (void) dealloc
{
    if (_blockout)
        delete _blockout;
    
    [super dealloc];
}

//==============================================================================

- (void) initRender
{
    if (_blockout)
    {
        NSLog(@"second attempt to init render");
        return;
    }
    
    [self initContext:self.pixelFormat];
    [self initGL];
    
    _blockout = new ABlockout();
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
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glViewport(0.0f, 0.0f, self.bounds.size.width, self.bounds.size.height);

    GLfloat aspect = self.bounds.size.width / self.bounds.size.height;
    GLfloat near = 0.1f;
    GLfloat far = 10000.0f;
    GLfloat fieldOfView = 45.0f;
    GLfloat size = near * tanf(DEG_TO_RAD(fieldOfView) / 2.0f);
    GLfloat width = size;
    GLfloat height = size / aspect;
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-width, width, -height, height, near, far);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glEnable(GL_DEPTH_TEST);
	glClearDepth(1.0f);
	glDepthFunc(GL_LESS);

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_CULL_FACE);
	glShadeModel(GL_SMOOTH); // Type of shading for the polygons
}

//==============================================================================

- (void)drawRect:(NSRect)dirtyRect
{
    if (_blockout == 0)
    {
        NSLog(@"render was not inited");
        return;
    }
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    _blockout->render();

	[[NSOpenGLContext currentContext] flushBuffer];
}

//==============================================================================

@end
