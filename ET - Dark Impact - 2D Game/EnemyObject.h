#pragma once
#include "_VirtualObject.h"

class EnemyObject
	: public _VirtualObject
{
public:
	//Podstawowe
	EnemyObject(const char* texturesheet, int x, int y); //Konstruktor wroga
	~EnemyObject(); //Destruktor wroga
	void Update(); //Aktualizacja wroga
	void Render(); //Renderowanie wroga
};