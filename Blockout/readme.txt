================================================================================
CURRENT TASKS
================================================================================
- correct //    #ifndef SPCTGAME_AOPENGLSTATE_H and its finis comment at the end of header file
- correct face culling

================================================================================
ROAD MAP
================================================================================

General purposes
- keyboard input processing(MAC only without wrappers and helpers but in isolated place) so we can in future attach config functionality
- block formation movement(left/right/up/down/drop)
- block formation restrictions in terms of well borders
- block falling to the bottom on timer
- block rotations and it's data model modification
- block movement restrictions according to the well configuration(collision detection)
- appending block formation into the well configuration
- draw filled well

- timer(c++ time) to emulate block drops
- speed switching to increase the difficulty

ui draw
- design UI
- points scoring
- start and end game statements
- text render(texture map for numbers only)
- table of records for current well width/height/depth/block type
- menu score/new/quit(every menu item is a texture)
