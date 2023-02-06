#include "TeleportObject.h"

TeleportObject::TeleportObject(unsigned short type)
{
	switch (type)
	{
	case 1:
		destination = 1;
		const char* tex1 = "Images/PortalBlue.png";
		usableTextures.push_back(tex1);
		break;

	case 2:
		destination = 2;
		const char* tex1 = "Images/PortalRed.png";
		usableTextures.push_back(tex1);
		break;

	case 3:
		destination = 3;
		const char* tex1 = "Images/PortalViolet.png";
		usableTextures.push_back(tex1);
		break;

	default:
		std::cout << "Error: Type Construktor." << std::endl;
		break;
	}

	RandomizeCoordinates(usableTextures[0]); //Podstawowa funkcja z klasy interfejsu
}

//PODSTAWOWE
//Konstruktor bohatera
TeleportObject::TeleportObject(const char* texturesheet, int x, int y, int des)
{
	BasicInit(texturesheet, x, y); //Podstawowa funkcja z klasy interfejsu
	coordinatesOfTeleport.x = x;
	coordinatesOfTeleport.y = y;
	destination = des;
}

//Konstruktor bohatera
TeleportObject::TeleportObject(const char* texturesheet, Point* point, int des)
{
	BasicInit(texturesheet, point->x, point->y); //Podstawowa funkcja z klasy interfejsu
	coordinatesOfTeleport.x = point->x;
	coordinatesOfTeleport.y = point->y;
	destination = des;
}

TeleportObject::TeleportObject(const TeleportObject& tempObject)
{
	currentObjectTexture = tempObject.currentObjectTexture;
	cordsOfObject = tempObject.cordsOfObject;
}

//Aktualizacja bohatera
void TeleportObject::Update()
{
	BasicUpdate(); //Podstawowa funkcja z klasy interfejsu
}

//Renderowanie bohatera
void TeleportObject::Render()
{
	BasicRender(); //Podstawowa funkcja z klasy interfejsu
}
//PODSTAWOWE