#import "AMacTimerWrapper.h"

//==============================================================================

@implementation AMacTimerWrapper

//==============================================================================

+ (AMacTimerWrapper*) macTimer:(AMacTimer*) timer
{
    return [[[AMacTimerWrapper alloc] initWithTimer:timer] autorelease];
}

//==============================================================================

- (id) initWithTimer:(AMacTimer*) cppTimer
{
    self = [super init];
    if (self == nil)
        return nil;
    
    timer = cppTimer;
    
    return self;
}

//==============================================================================

@end
