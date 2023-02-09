/*Klasa reprezentuj¹c¹ obiekt gry typu bohater.*/

#pragma once
#include "_VirtualObject.h"
#include "HeroStatistics.h"
#include "HeroKeyboardHandler.h"

class HeroObject
	: public virtual _VirtualObject, public HeroStatistics, public HeroKeyboardHandler
{
public:
	//Podstawowe
	HeroObject(unsigned short type);
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
	void TeleportHeroToPoint(Point* point); //Poruszanie siê bohaterem

	//static int speed;
};