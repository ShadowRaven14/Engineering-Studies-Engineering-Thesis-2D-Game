/*Klasa reprezentującą obiekt gry typu bohater.*/

#pragma once
#include "_VirtualObject.h"
#include "HeroObjectives.h"
#include "HeroKeyboardHandler.h"

class HeroObject
	: public virtual _VirtualObject, public HeroObjectives, public HeroKeyboardHandler
{
public:
	//Podstawowe
	HeroObject(unsigned short type);
	HeroObject(const char* texturesheet, int x, int y); //Konstruktor bohatera
	HeroObject(const char* texturesheet, Point* point); //Konstruktor bohatera
	HeroObject(const _VirtualObject& tempObject);
	HeroObject(const HeroObject& tempHero);
	~HeroObject(); //Destruktor bohatera
	HeroObject& operator= (const HeroObject& tempHero); //Przeciążenie operatora
	HeroObject& operator= (HeroObject* tempHero); //Przeciążenie operatora
	void Update(); //Aktualizacja bohatera
	void Render(); //Renderowanie bohatera

	//Zaawansowane
	void TeleportHeroToPoint(Point* point); //Poruszanie się bohaterem

	//static int speed;
};