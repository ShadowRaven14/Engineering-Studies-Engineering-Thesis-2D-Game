#include "CoinObject.h"

//Konstruktor
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

//Konstruktor
CoinObject::CoinObject(const char* texturesheet, int x, int y)
{
	BasicInit(texturesheet, x, y); //Podstawowa funkcja z klasy interfejsu
}

//Konstruktor
CoinObject::CoinObject(const char* texturesheet)
{
	RandomizeCoordinates(texturesheet);  //Podstawowa funkcja z klasy interfejsu
}
