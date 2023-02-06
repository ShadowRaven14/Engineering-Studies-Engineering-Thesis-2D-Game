#include "CoinObject.h"
using namespace std;

CoinObject::CoinObject(unsigned short type)
{
	const char* tempTex;

	switch (type)
	{
	case 1:
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
	srcRect.h = srcRect.h * 2; //Wysokoœæ w pikselach
	srcRect.w = srcRect.w * 2; //Szerokoœæ w pikselach
}

//Renderowanie bohatera
void CoinObject::Render()
{
	BasicRender(); //Podstawowa funkcja z klasy interfejsu
}