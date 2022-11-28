/*Klasa reprezentuj¹c¹ obiekt gry typu bohater.*/

#pragma once
#include "_VirtualObject.h"
#include "HeroLayerMap.h"
#include "BasicClass.h"

class HeroObject
	: public virtual _VirtualObject, public HeroLayerMap, public BasicClass
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