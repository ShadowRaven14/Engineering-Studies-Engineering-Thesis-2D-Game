#include "EnemySentinelObject.h"

EnemySentinelObject::EnemySentinelObject()
{
	const char* tempTex;

	power = 10;
	std::cout << "Error: Type Construktor." << std::endl;
	tempTex = "Images/AppleNormal.png";
	usableTextures.push_back(tempTex);

	RandomizeCoordinates(usableTextures[0]); //Podstawowa funkcja z klasy interfejsu
	RandomizeTypeOfMovement();
	isMovingRight = isMovingUp = true;
}

EnemySentinelObject::EnemySentinelObject(unsigned short type)
{
	const char* tempTex;

	switch (type)
	{
	case 0:
		power = rand() % 20 + 60;
		tempTex = "Images/MagicChaos.png";
		usableTextures.push_back(tempTex);
		tempTex = "Images/MagicChaos.png";
		usableTextures.push_back(tempTex);
		tempTex = "Images/AppleNormal.png";
		usableTextures.push_back(tempTex);
		break;

	case 1:
		power = rand() % 20 + 80;
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

EnemySentinelObject::EnemySentinelObject(const char* texturesheet, int x, int y)
{
	power = 10;
	BasicInit(texturesheet, x, y); //Podstawowa funkcja z klasy interfejsu
	isMovingRight = isMovingUp = true;
}

EnemySentinelObject::EnemySentinelObject(const char* texturesheet)
{
	power = 10;
	RandomizeCoordinates(texturesheet); //Podstawowa funkcja z klasy interfejsu
	isMovingRight = isMovingUp = true;
}

EnemySentinelObject::~EnemySentinelObject()
{
}
