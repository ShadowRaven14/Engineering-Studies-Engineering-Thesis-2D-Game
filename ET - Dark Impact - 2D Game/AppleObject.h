#pragma once
#include "_VirtualObject.h"

class AppleObject 
	: public _VirtualObject
{

public:
	bool qx;
	bool qy;

	AppleObject(const char* texturesheet, int x, int y);
	~AppleObject();
	void Update();
	void Render();

};