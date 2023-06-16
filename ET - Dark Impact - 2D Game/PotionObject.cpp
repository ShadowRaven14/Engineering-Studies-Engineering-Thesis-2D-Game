#include "PotionObject.h"

//Konstruktor
PotionObject::PotionObject(unsigned short type)
{
	const char* tempTex;

	switch (type)
	{
	case 0:
		power = rand() % 10 + 5;
		tempTex = "Images/PotionStrength.png";
		usableTextures.push_back(tempTex);
		break;

	case 1:
		power = rand() % 10 + 5;
		tempTex = "Images/PotionIntelligence.png";
		usableTextures.push_back(tempTex);
		break;

	case 2:
		power = rand() % 10 + 5;
		tempTex = "Images/PotionAgility.png";
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
