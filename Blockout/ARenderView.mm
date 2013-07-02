#import "ARenderView.h"
#import "DrawTypes.h"
#import "AOpenGLState.h"

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
    
    delete _blockout;
    
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
    
    _blockout = new ABlockout();
    
    _animationInterval = 1.0f / 60.0f;
    [self startAnimation];
    
    _openGLInited = YES;
}

//==============================================================================

- (void) initContext:(NSOpenGLPixelFormat*)format
{
    if (_openGLInited == YES)
    {
        NSLog(@"ARenderView::initContext: OpenGL already inited");
        return;
    }

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
    {
        NSLog(@"ARenderView::initGL: OpenGL already inited");
        return;
    }
    
    [self updateScreenSize:self.bounds.size.width screenHeight:self.bounds.size.height];

    //  call shared to create instance and init some OpenGL pars;
    AOpenGLState::shared();
}

//==============================================================================

- (void) updateScreenSize:(GLfloat) screenWidth screenHeight: (GLfloat) screenHeight
{
    AOpenGLState* oglState = AOpenGLState::shared();
    oglState->frustumSetup(screenWidth, screenHeight);
}

//==============================================================================

- (void) renderGame
{
    AOpenGLState* oglState = AOpenGLState::shared();
    oglState->clear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    _blockout->processGameCycle();

	[[NSOpenGLContext currentContext] flushBuffer];
}

//==============================================================================

#pragma mark - Animation timer -

//==============================================================================

- (void)startAnimation
{
	_animationTimer = [NSTimer scheduledTimerWithTimeInterval:_animationInterval target:self selector:@selector(renderGame) userInfo:nil repeats:YES];
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
