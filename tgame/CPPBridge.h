//
//  CPPBridge.h
//  tgame
//
//  Created by Michael on 28/10/2019.
//  Copyright © 2019 Michael. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CPPBridge : NSObject

- (void)updateScreenSizeWithWidth:(CGFloat)width height:(CGFloat)height;
- (void)processGameCycle;
- (void)processKeyboardEvent:(UInt)keyCode;
- (void)startGame;

@end

NS_ASSUME_NONNULL_END
