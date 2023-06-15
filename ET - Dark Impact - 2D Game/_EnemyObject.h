/*Klasa reprezentuj¹c¹ obiekt gry typu przeciwnik.*/

#pragma once
#include "__VirtualObject.h"

class _EnemyObject
	: public virtual __VirtualObject
{
public:
	//Podstawowe
	void Update(); //Aktualizacja wroga
	void Render(); //Renderowanie wroga

	//Zaawansowane
	short typeOfMovement;
	void RandomizeTypeOfMovement();
	void MoveWithEnemyV1(); //Poruszanie siê wroga wersja 1
	void MoveWithEnemyV2(); //Poruszanie siê wroga wersja 2
	void MoveWithEnemyV3(); //Poruszanie siê wroga wersja 3
	void MoveWithEnemyV4(); //Poruszanie siê wroga wersja 4
	void ChangeCurrentTexture(int n);
	unsigned short type;
	unsigned int power;
	bool isMovingRight, isMovingUp; //Pomoc przy kierowaniu wrogiem
	
};