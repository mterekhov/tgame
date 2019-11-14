//
//  CPPBridge.m
//  tgame
//
//  Created by Michael on 28/10/2019.
//  Copyright © 2019 Michael. All rights reserved.
//

#import "CPPBridge.h"
#import "ablockout.h"

@interface CPPBridge ()

@property (nonatomic, assign) spcTGame::ABlockout *tengine;

@end

@implementation CPPBridge

- (instancetype)init {
    self = [super init];
    
    _tengine = new spcTGame::ABlockout();
    
    return self;
}

- (void)dealloc {
    delete self.tengine;
}

- (void)updateScreenSizeWithWidth:(CGFloat)width height:(CGFloat)height {
    self.tengine->updateScreenSize(width, height);
}

- (void)processGameCycle {
    self.tengine->processGameCycle();
}

- (void)processKeyboardEvent:(UInt)keyCode {
    self.tengine->processKeyboardEvent(keyCode);
}

- (void)startGame {
    self.tengine->startGame();
}

@end
