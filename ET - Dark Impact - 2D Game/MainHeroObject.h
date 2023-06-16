/*Klasa reprezentuj�c� obiekt gry typu bohater.*/

#pragma once
#include "__VirtualObject.h"
#include "HeroBasicClass.h"
#include "HeroKeyboardHandler.h"

class MainHeroObject
	: public virtual __VirtualObject, public HeroBasicClass, public HeroKeyboardHandler
{
public:
	//Podstawowe
	MainHeroObject(unsigned short type); //Konstruktor bohatera
	MainHeroObject(const char* texturesheet, int x, int y); //Konstruktor bohatera
	MainHeroObject(const char* texturesheet, Point* point); //Konstruktor bohatera
	MainHeroObject(const __VirtualObject& tempObject); //Konstruktor kopiuj�cy bohatera
	MainHeroObject(const MainHeroObject& tempHero); //Konstruktor kopiuj�cy bohatera
	~MainHeroObject(); //Destruktor bohatera
	MainHeroObject& operator= (const MainHeroObject& tempHero); //Przeci��enie operatora
	MainHeroObject& operator= (MainHeroObject* tempHero); //Przeci��enie operatora
	void Update(); //Aktualizacja bohatera
	void Render(); //Renderowanie bohatera

	//Zaawansowane
	bool isMovingRight;
	void TeleportHeroToPoint(Point* point); //Poruszanie si� bohaterem
	void ChangeHeroTexture_DamageOrHeal(bool damage); //Zmiana tekstur bohatera je�li otrzymuje obra�enia lub si� leczy

	//static int speed;
};