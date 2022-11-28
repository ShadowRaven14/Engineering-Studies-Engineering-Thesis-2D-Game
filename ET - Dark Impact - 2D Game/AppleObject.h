/*Do wyrzucenia.*/

#pragma once
#include "_VirtualObject.h"

class AppleObject 
	: public virtual _VirtualObject
{
public:
	AppleObject(const char* texturesheet, int x, int y);
	~AppleObject();
	void Update();
	void Render();

	bool qx;
	bool qy;
};