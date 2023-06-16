/*Klasa reprezentuj�c� obiekt gry typu przeciwnik.*/

#pragma once
#include "__VirtualObject.h"

class _EnemyObject
	: public virtual __VirtualObject
{
public:
	//Podstawowe
	void Update(); //Aktualizacja
	void Render(); //Renderowanie

	//Zaawansowane
	short typeOfMovement = 0;
	void RandomizeTypeOfMovement();
	void MoveWithEnemyV1(); //Poruszanie si� wroga wersja 1
	void MoveWithEnemyV2(); //Poruszanie si� wroga wersja 2
	void MoveWithEnemyV3(); //Poruszanie si� wroga wersja 3
	void MoveWithEnemyV4(); //Poruszanie si� wroga wersja 4
	void ChangeCurrentTexture(int n);

	unsigned short type = 0;
	unsigned short power = 0;
	bool isMovingRight = true, isMovingUp = true; //Pomoc przy kierowaniu wrogiem
	
};