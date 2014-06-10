- draw triangles
- render list of tringles
- draw solid cube
- draw textured cube
- draw partically filled well
- wrap tgame code in namespace

General purposes
- draw filled well
- keyboard input processing(MAC only without wrappers and helpers but in isolated place)
    so we can in future attach config functionality
- block formation movement(left/right/up/down/drop)
- block formation restrictions in terms of well borders
- timer(c++ time) to emulate block drops
- block falling to the bottom on timer
- block rotations and it's data model modification
- block movement restrictions according to the well configuration(collision detection)
- appending block formation into the well configuration
- speed switching to increase the difficulty

ui draw
- design UI
- points scoring
- start and end game statements
- text render(texture map for numbers only)
- table of records for current well width/height/depth/block type
- menu champions/new/quit(every menu item is a texture)
