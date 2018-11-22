#ifndef SPCTGAME_ARENDEROBJECT_H
#define SPCTGAME_ARENDEROBJECT_H

//==============================================================================

#include "aformation.h"
#include "acolor.h"
#include "atexture.h"
#include "arenderinterface.h"

//==============================================================================

namespace spcTGame
{
    
//==============================================================================

class ARenderObject
{
private:
    ARenderInterface *_object;
    
public:
	static ARenderInterface *createTexturedBlock(const AFormation& formation, const TFloat size, const ATexture &texture);
	static ARenderInterface *createColoredBlock(const AFormation& formation, const TFloat size, const AColor& color, const ERenderStyle renderStyle);
	static ARenderInterface *createWell(const AFormation& formation, const TFloat size, const AColor& color);

	ARenderObject();
    ARenderObject(ARenderInterface *object);
	ARenderObject(const ARenderObject& renderObject);
    ~ARenderObject();
    
    void render();
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================
    
#endif  //  SPCTGAME_ARENDEROBJECT_H
