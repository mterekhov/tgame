#import "ARenderView.h"
#import "DrawTypes.h"

//==============================================================================

@implementation ARenderView

//==============================================================================

#pragma mark - View lifecycle -

//==============================================================================

- (id)initWithFrame:(NSRect)frame pixelFormat:(NSOpenGLPixelFormat*)format
{
    self = [super initWithFrame:frame pixelFormat:format];
    if (self == nil)
        return nil;

    return self;
}

//==============================================================================

- (void) dealloc
{
	[self stopAnimation];
    [super dealloc];
}

//==============================================================================

- (void) viewDidEndLiveResize
{
	[self stopAnimation];
    [self updateScreenSize:self.frame.size.width screenHeight:self.frame.size.height];
    [self startAnimation];
}

//==============================================================================

#pragma mark - OpenGL setup -

//==============================================================================

- (void) initRender
{
    _openGLInited = NO;

    [self initContext:self.pixelFormat];
    [self initGL];
    _animationInterval = 1.0f / 60.0f;
    [self startAnimation];
    
    _openGLInited = YES;
}

//==============================================================================

- (void) initContext:(NSOpenGLPixelFormat*)format
{
    if (_openGLInited == YES)
        return;
    
	NSOpenGLContext* viewContext = [[NSOpenGLContext alloc] initWithFormat: format
                                                              shareContext: nil];
    [self setOpenGLContext: viewContext];
    [viewContext makeCurrentContext];
    [viewContext setView: self];
}

//==============================================================================

- (void) initGL
{
    if (_openGLInited == YES)
        return;
    
    [self updateScreenSize:self.bounds.size.width screenHeight:self.bounds.size.height];
    
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    
    glEnable(GL_DEPTH_TEST);
	glClearDepth(1.0f);
	glDepthFunc(GL_LESS);
    
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_CULL_FACE);
	glShadeModel(GL_SMOOTH); // Type of shading for the polygons
    glEnableClientState(GL_VERTEX_ARRAY);
}

//==============================================================================

- (void) updateScreenSize:(GLfloat) screenWidth screenHeight: (GLfloat) screenHeight
{
    glViewport(0.0f, 0.0f, screenWidth, screenHeight);
    
    GLfloat aspect = screenWidth / screenHeight;
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
}

//==============================================================================

- (void) renderFrame
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    _blockout.render();

	[[NSOpenGLContext currentContext] flushBuffer];
}

//==============================================================================

#pragma mark - Animation timer -

//==============================================================================

- (void)startAnimation
{
	_animationTimer = [NSTimer scheduledTimerWithTimeInterval:_animationInterval target:self selector:@selector(renderFrame) userInfo:nil repeats:YES];
	_animationStarted = [NSDate timeIntervalSinceReferenceDate];
}

//==============================================================================

- (void)stopAnimation
{
	[_animationTimer invalidate];
	_animationTimer = nil;
}

//==============================================================================

- (void)setAnimationInterval:(NSTimeInterval)interval
{
	_animationInterval = interval;
	
	if (_animationTimer)
    {
		[self stopAnimation];
		[self startAnimation];
	}
}

//==============================================================================

@end
