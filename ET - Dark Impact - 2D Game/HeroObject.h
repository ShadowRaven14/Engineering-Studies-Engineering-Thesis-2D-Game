#pragma once
#include "_VirtualObject.h"

class HeroObject
	: public _VirtualObject
{
public:
	HeroObject(const char* texturesheet, int x, int y);
	~HeroObject();
	void Update();
	void Render();

	void MoveWithHero();
	void HandleKeyboard();

	char input, previnput; //poruszanie
};