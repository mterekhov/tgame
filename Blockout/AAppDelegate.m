//
//  AAppDelegate.m
//  Blockout
//
//  Created by entertainment on 19.01.13.
//  Copyright (c) 2013 Landsknecht. All rights reserved.
//

#import "AAppDelegate.h"
#import "ARenderView.h"

@implementation AAppDelegate

- (void)dealloc
{
    [super dealloc];
}

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
	NSOpenGLPixelFormat* pixelFormat = [[NSOpenGLPixelFormat alloc] initWithAttributes: attrs];
    ARenderView* view = [[[ARenderView alloc] initWithFrame: _window.frame
                                                pixelFormat: pixelFormat] autorelease];
//                                                pixelFormat: [ARenderView defaultPixelFormat]] autorelease];
	[pixelFormat release];
	pixelFormat = nil;
    [_window setContentView:view];
}

@end
