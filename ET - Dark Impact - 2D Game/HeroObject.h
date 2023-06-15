/*Klasa reprezentuj¹c¹ obiekt gry typu bohater.*/

#pragma once
#include "__VirtualObject.h"
#include "HeroObjectives.h"
#include "HeroKeyboardHandler.h"

class HeroObject
	: public virtual __VirtualObject, public HeroObjectives, public HeroKeyboardHandler
{
public:
	//Podstawowe
	HeroObject(unsigned short type);
	HeroObject(const char* texturesheet, int x, int y); //Konstruktor bohatera
	HeroObject(const char* texturesheet, Point* point); //Konstruktor bohatera
	HeroObject(const __VirtualObject& tempObject);
	HeroObject(const HeroObject& tempHero);
	~HeroObject(); //Destruktor bohatera
	HeroObject& operator= (const HeroObject& tempHero); //Przeci¹¿enie operatora
	HeroObject& operator= (HeroObject* tempHero); //Przeci¹¿enie operatora
	void Update(); //Aktualizacja bohatera
	void Render(); //Renderowanie bohatera

	//Zaawansowane
	void TeleportHeroToPoint(Point* point); //Poruszanie siê bohaterem
	void ChangeHeroTexture_DamageOrHeal(bool damage);

	//static int speed;
};