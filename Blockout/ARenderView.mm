#import "ARenderView.h"

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
    [self initGame];
    
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

	NSOpenGLContext* viewContext = [[[NSOpenGLContext alloc] initWithFormat: format
                                                              shareContext: nil] autorelease];
    [self setOpenGLContext: viewContext];
    [viewContext makeCurrentContext];
    [viewContext setView: self];
}

//==============================================================================

- (void) initGame
{
    if (_openGLInited == YES)
    {
        NSLog(@"ARenderView::initGL: OpenGL already inited");
        return;
    }
    
    [self updateScreenSize:self.bounds.size.width screenHeight:self.bounds.size.height];

    _blockout = new spcTGame::ABlockout();
    _blockout->startGame();
}

//==============================================================================

- (void) updateScreenSize:(spcTGame::TDouble) screenWidth screenHeight: (spcTGame::TDouble) screenHeight
{
    _blockout->updateScreenSize(screenWidth, screenHeight);
}

//==============================================================================

- (void) renderGame
{
    _blockout->processGameCycle();

	[[NSOpenGLContext currentContext] flushBuffer];
}

//==============================================================================

#pragma mark - Animation timer -

//==============================================================================

- (void)startAnimation
{
	_animationTimer = [NSTimer scheduledTimerWithTimeInterval: _animationInterval
                                                       target: self
                                                     selector: @selector(renderGame)
                                                     userInfo: nil
                                                      repeats: YES];
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

#pragma mark - Key events -

//==============================================================================

- (BOOL)acceptsFirstResponder
{
    return YES;
}

//==============================================================================

- (void) keyDown:(NSEvent *)theEvent
{
//    NSString* characters = [theEvent charactersIgnoringModifiers];
    _blockout->processKeyboardEvent(theEvent.keyCode);
}

//==============================================================================

@end
