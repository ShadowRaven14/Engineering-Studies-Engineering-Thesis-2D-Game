#include "PotionObject.h"

PotionObject::PotionObject(unsigned short type)
{
	const char* tempTex;

	switch (type)
	{
	case 1:
		power = 10;
		tempTex = "Images/PotionHealth.png";
		usableTextures.push_back(tempTex);
		break;

	case 2:
		power = 10;
		tempTex = "Images/PotionMana.png";
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

void PotionObject::Update()
{
	BasicUpdate(); //Podstawowa funkcja z klasy interfejsu
}

void PotionObject::Render()
{
	BasicRender(); //Podstawowa funkcja z klasy interfejsu
}