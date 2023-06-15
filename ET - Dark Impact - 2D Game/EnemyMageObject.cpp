#include "EnemyMageObject.h"

EnemyMageObject::EnemyMageObject()
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

EnemyMageObject::EnemyMageObject(unsigned short type)
{
	const char* tempTex;

	switch (type)
	{
	case 0:
		power = 15;
		tempTex = "Images/HumanMageGreen_GoRight.png";
		usableTextures.push_back(tempTex);
		tempTex = "Images/HumanMageGreen_GoLeft.png";
		usableTextures.push_back(tempTex);
		tempTex = "Images/AppleNormal.png";
		usableTextures.push_back(tempTex);
		break;

	case 1:
		power = 30;
		tempTex = "Images/HumanMageBlue_GoRight.png";
		usableTextures.push_back(tempTex);
		tempTex = "Images/HumanMageBlue_GoLeft.png";
		usableTextures.push_back(tempTex);
		tempTex = "Images/AppleNormal.png";
		usableTextures.push_back(tempTex);
		break;

	case 2:
		power = 50;
		tempTex = "Images/HumanMageRed_GoRight.png";
		usableTextures.push_back(tempTex);
		tempTex = "Images/HumanMageRed_GoLeft.png";
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

EnemyMageObject::EnemyMageObject(const char* texturesheet, int x, int y)
{
	power = 10;
	BasicInit(texturesheet, x, y); //Podstawowa funkcja z klasy interfejsu
	isMovingRight = isMovingUp = true;
}

EnemyMageObject::EnemyMageObject(const char* texturesheet)
{
	power = 10;
	RandomizeCoordinates(texturesheet); //Podstawowa funkcja z klasy interfejsu
	isMovingRight = isMovingUp = true;
}

EnemyMageObject::~EnemyMageObject()
{
}
