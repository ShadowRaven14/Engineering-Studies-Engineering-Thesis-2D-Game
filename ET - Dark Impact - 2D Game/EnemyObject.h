#pragma once
#include "Object.h"

class EnemyObject
	: public Object
{
public:
	EnemyObject(const char* texturesheet, int x, int y);
	~EnemyObject();
	void Update();
	void Render();
};