#import <Foundation/Foundation.h>

#import "AMacTimer.h"

//==============================================================================

@interface AMacTimerWrapper : NSObject
{
@public
    AMacTimer* timer;
}

+ (AMacTimerWrapper*) macTimer:(AMacTimer*) timer;

- (id) initWithTimer:(AMacTimer*) timer;

@end
