#include "ChestObject.h"

ChestObject::ChestObject(unsigned short type)
{
	switch (type)
	{
	case 1:
		const char* tex1 = "Images/WoodenChest.png";
		const char* tex2 = "Images/WoodenChest_Open.png";
		usableTextures.push_back(tex1);
		usableTextures.push_back(tex2);
		break;

	default:
		std::cout << "Error: Type Construktor." << std::endl;
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