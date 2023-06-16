#include "AppleItemObject.h"

//Konstruktor
AppleItemObject::AppleItemObject(unsigned short type)
{
	const char* tempTex;

	switch (type)
	{
	case 0:
		power = rand() % 5 - 5;
		tempTex = "Images/AppleNormal.png";
		usableTextures.push_back(tempTex);
		break;

	case 1:
		power = rand() % 5 - 5;
		tempTex = "Images/AppleNormal.png";
		usableTextures.push_back(tempTex);
		break;

	case 2:
		power = rand() % 5 + 5;
		tempTex = "Images/AppleGolden.png";
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

//Destruktor
AppleItemObject::~AppleItemObject()
{
}
