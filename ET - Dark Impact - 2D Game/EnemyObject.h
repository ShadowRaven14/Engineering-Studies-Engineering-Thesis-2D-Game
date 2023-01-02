/*Klasa reprezentuj¹c¹ obiekt gry typu przeciwnik.*/

#pragma once
#include "_VirtualObject.h"

class EnemyObject
	: public virtual _VirtualObject
{
public:
	//Podstawowe
	EnemyObject(const char* texturesheet, int x, int y); //Konstruktor wroga
	EnemyObject(const char* texturesheet); //Konstruktor wroga
	~EnemyObject(); //Destruktor wroga
	void Update(); //Aktualizacja wroga
	void Render(); //Renderowanie wroga

	//Zaawansowane
	bool sx, sy; //Pomoc przy kierowaniu wrogiem
	void MoveWithEnemyV1(); //Poruszanie siê wroga
};