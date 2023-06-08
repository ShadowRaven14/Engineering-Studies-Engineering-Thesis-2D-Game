#include "PotionObject.h"

PotionObject::PotionObject(unsigned short type)
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
		power = 10;
		tempTex = "Images/PotionHealth.png";
		usableTextures.push_back(tempTex);
		break;

	case 2:
		power = 15;
		tempTex = "Images/PotionMana.png";
		usableTextures.push_back(tempTex);
		break;

	case 3:
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

void PotionObject::Update()
{
	BasicUpdate(); //Podstawowa funkcja z klasy interfejsu
	destRect.h = destRect.h / 1.5; //Wysokoœæ w grze
	destRect.w = destRect.w / 1.5; //Szerokoœæ w grze
}

void PotionObject::Render()
{
	BasicRender(); //Podstawowa funkcja z klasy interfejsu
}
