#include "AppleItemObject.h"

AppleItemObject::AppleItemObject(unsigned short type)
{
	const char* tempTex;

	switch (type)
	{
	case 0:
		power = 5;
		tempTex = "Images/AppleNormal.png";
		usableTextures.push_back(tempTex);
		break;

	case 1:
		power = 20;
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

AppleItemObject::~AppleItemObject()
{
}

void AppleItemObject::Update()
{
}

void AppleItemObject::Render()
{
}
