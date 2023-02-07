#include "CoinObject.h"
using namespace std;

CoinObject::CoinObject(unsigned short type)
{
	const char* tempTex;

	switch (type)
	{
	case 0:
		tempTex = "Images/Coin.png";
		usableTextures.push_back(tempTex);
		break;

	default:
		std::cout << "Error: Type Construktor." << std::endl;
		tempTex = "Images/AppleNormal.png";
		usableTextures.push_back(tempTex);
		break;
	}

	RandomizeCoordinates(usableTextures[0]); //Podstawowa funkcja z klasy interfejsu
}

CoinObject::CoinObject(const char* texturesheet, int x, int y)
{
	BasicInit(texturesheet, x, y); //Podstawowa funkcja z klasy interfejsu
}

CoinObject::CoinObject(const char* texturesheet)
{
	RandomizeCoordinates(texturesheet);  //Podstawowa funkcja z klasy interfejsu
}

//Aktualizacja bohatera
void CoinObject::Update()
{
	BasicUpdate(); //Podstawowa funkcja z klasy interfejsu
	//destRect.h = destRect.h * 2; //Wysoko�� w grze
	//destRect.w = destRect.w * 2; //Szeroko�� w grze
}

//Renderowanie bohatera
void CoinObject::Render()
{
	BasicRender(); //Podstawowa funkcja z klasy interfejsu
}