/*Klasa reprezentuj¹c¹ obiekt gry typu przeciwnik.*/

#pragma once
#include "_VirtualObject.h"

class EnemyObject
	: public virtual _VirtualObject
{
public:
	//Podstawowe
	EnemyObject(unsigned short type);
	EnemyObject(const char* texturesheet, int x, int y); //Konstruktor wroga
	EnemyObject(const char* texturesheet); //Konstruktor wroga
	~EnemyObject(); //Destruktor wroga
	void Update(); //Aktualizacja wroga
	void Render(); //Renderowanie wroga

	//Zaawansowane
	void MoveWithEnemyV1(); //Poruszanie siê wroga
	void ChangeCurrentTexture(int n);
	unsigned short type;
	unsigned int power;
	bool isMovingRight, isMovingUp; //Pomoc przy kierowaniu wrogiem
	
};