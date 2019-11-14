#ifndef SPCTGAME_ARENDERINTERFACE_H
#define SPCTGAME_ARENDERINTERFACE_H

//==============================================================================

namespace spcTGame
{
	
//==============================================================================
	
class ARenderInterface
{
public:
	virtual void render() = 0;
	virtual ARenderInterface *copy() = 0;
};

//==============================================================================

}   //  namespace spcTGame

//==============================================================================

#endif  //  SPCTGAME_ARENDERINTERFACE_H
