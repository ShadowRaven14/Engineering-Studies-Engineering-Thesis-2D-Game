#pragma once
#include "_VirtualObject.h"

class HeroObject
	: public virtual _VirtualObject
{
public:
	//Podstawowe
	HeroObject(const char* texturesheet, int x, int y); //Konstruktor bohatera
	~HeroObject(); //Destruktor bohatera
	void Update(); //Aktualizacja bohatera
	void Render(); //Renderowanie bohatera

	//Zaawansowane
	int map[29][45];
	void MoveWithHero(); //Poruszanie siê bohaterem
};