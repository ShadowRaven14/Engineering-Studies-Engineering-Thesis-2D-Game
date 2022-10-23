#pragma once
#include "Object.h"

class HeroObject
	: public Object
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