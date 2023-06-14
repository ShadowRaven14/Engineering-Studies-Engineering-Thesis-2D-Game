#include "EnemySentinelObject.h"

EnemySentinelObject::EnemySentinelObject(unsigned short type)
{
	const char* tempTex;

	switch (type)
	{
	case 0:
		power = 100;
		tempTex = "Images/MagicChaos.png";
		usableTextures.push_back(tempTex);
		tempTex = "Images/MagicChaos.png";
		usableTextures.push_back(tempTex);
		tempTex = "Images/AppleNormal.png";
		usableTextures.push_back(tempTex);
		break;

	case 1:
		power = 100;
		tempTex = "Images/MagicFire.png";
		usableTextures.push_back(tempTex);
		tempTex = "Images/MagicFire.png";
		usableTextures.push_back(tempTex);
		tempTex = "Images/AppleNormal.png";
		usableTextures.push_back(tempTex);
		break;

	default:
		power = 10;
		std::cout << "Error: Type Construktor." << std::endl;
		tempTex = "Images/AppleNormal.png";
		usableTextures.push_back(tempTex);
		break;
	}

	RandomizeCoordinates(usableTextures[0]); //Podstawowa funkcja z klasy interfejsu
	RandomizeTypeOfMovement();
	isMovingRight = isMovingUp = true;
}

EnemySentinelObject::~EnemySentinelObject()
{
}
