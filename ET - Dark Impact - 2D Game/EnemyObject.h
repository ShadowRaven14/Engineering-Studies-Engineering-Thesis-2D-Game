#pragma once
#include "_VirtualObject.h"

class EnemyObject
	: public _VirtualObject
{
public:
	EnemyObject(const char* texturesheet, int x, int y);
	~EnemyObject();
	void Update();
	void Render();
};