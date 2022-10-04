#pragma once
#include "Object.h"

class AppleObject 
	: public Object
{

public:
	AppleObject(const char* texturesheet, int x, int y);
	~AppleObject();
	void Update();
	void Render();
};