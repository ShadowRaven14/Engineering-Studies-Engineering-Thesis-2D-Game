/*Klasa reprezentuj¹c¹ obiekt gry typu bohater.*/

#pragma once
#include "_VirtualObject.h"
#include "HeroStatistics.h"

class HeroObject
	: public virtual _VirtualObject, public HeroStatistics
{
public:
	//Podstawowe
	HeroObject(const char* texturesheet, int x, int y); //Konstruktor bohatera
	HeroObject(const char* texturesheet, Point* point); //Konstruktor bohatera
	HeroObject(const _VirtualObject& tempObject);
	HeroObject(const HeroObject& tempHero);
	~HeroObject(); //Destruktor bohatera
	HeroObject& operator= (const HeroObject& tempHero); //Przeci¹¿enie operatora
	HeroObject& operator= (HeroObject* tempHero); //Przeci¹¿enie operatora
	void Update(); //Aktualizacja bohatera
	void Render(); //Renderowanie bohatera

	//Zaawansowane
	void MoveWithHero(); //Poruszanie siê bohaterem
	void MoveHeroToPoint(Point* point); //Poruszanie siê bohaterem
	CoordinatesOfHero cordsOfHero; //Bohater na mapie
};