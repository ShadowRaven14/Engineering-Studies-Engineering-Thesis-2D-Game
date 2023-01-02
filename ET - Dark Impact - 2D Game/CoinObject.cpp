#include "CoinObject.h"
using namespace std;

CoinObject::CoinObject(const char* texturesheet, int x, int y)
{
	ObjectInit(texturesheet, x, y); //Podstawowa funkcja z klasy interfejsu
}

CoinObject::CoinObject(const char* texturesheet)
{
	RandomizeCoordinates(texturesheet);  //Podstawowa funkcja z klasy interfejsu
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