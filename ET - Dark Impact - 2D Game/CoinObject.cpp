#include "CoinObject.h"

CoinObject::CoinObject(const char* texturesheet, int x, int y)
{
	std::cout << "COIN CONSTRUKTOR" << std::endl;
	ObjectInit(texturesheet, x, y); //Podstawowa funkcja z klasy interfejsu
}

CoinObject::CoinObject(const char* texturesheet)
{
	std::cout << "COIN CONSTRUKTOR" << std::endl;
	srand((unsigned)time(NULL));
	int x = (rand() % (25 - 2) + 1) * 32;
	int y = (rand() % (20 - 2) + 1) * 32;
	ObjectInit(texturesheet, x, y); //Podstawowa funkcja z klasy interfejsu
}


//Aktualizacja bohatera
void CoinObject::Update()
{
	UpdateInit(); //Podstawowa funkcja z klasy interfejsu
	srcRect.h = srcRect.h * 2; //Wysokoœæ w pikselach
	srcRect.w = srcRect.w * 2; //Szerokoœæ w pikselach
}

//Renderowanie bohatera
void CoinObject::Render()
{
	RenderInit(); //Podstawowa funkcja z klasy interfejsu
}