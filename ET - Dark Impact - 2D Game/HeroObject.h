#pragma once
#include "_VirtualObject.h"
#include "HeroLayerMap.h"

class HeroObject
	: public virtual _VirtualObject, public HeroLayerMap
{
public:
	//Podstawowe
	HeroObject(const char* texturesheet, int x, int y); //Konstruktor bohatera
	~HeroObject(); //Destruktor bohatera
	void Update(); //Aktualizacja bohatera
	void Render(); //Renderowanie bohatera

	//Zaawansowane
	void InitializeHeroMap();
	void MoveWithHero(); //Poruszanie siê bohaterem
};