#include "ChestObject.h"

ChestObject::ChestObject(unsigned short type)
{
	const char* tempTex;

	switch (type)
	{
	case 1:
		worth = 5;
		tempTex = "Images/ChestWooden_Closed.png";
		usableTextures.push_back(tempTex);
		tempTex = "Images/ChestWooden_Open.png";
		usableTextures.push_back(tempTex);
		break;

	case 2:
		worth = 10;
		tempTex = "Images/ChestIron_Closed.png";
		usableTextures.push_back(tempTex);
		tempTex = "Images/ChestWooden_Open.png";
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

//Konstruktor wroga
ChestObject::ChestObject(const char* texturesheet, int x, int y)
{
	BasicInit(texturesheet, x, y);  //Podstawowa funkcja z klasy interfejsu
	isOpen = false;
}

//Konstruktor wroga
ChestObject::ChestObject(const char* texturesheet)
{
	RandomizeCoordinates(texturesheet);  //Podstawowa funkcja z klasy interfejsu
	isOpen = false;
}

//Aktualizacja wroga
void ChestObject::Update()
{
	BasicUpdate(); //Podstawowa funkcja z klasy interfejsu
}

//Renderowanie wroga
void ChestObject::Render()
{
	BasicRender(); //Podstawowa funkcja z klasy interfejsu
}