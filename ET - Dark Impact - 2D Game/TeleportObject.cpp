#include "TeleportObject.h"

TeleportObject::TeleportObject(unsigned short type)
{
	const char* tempTex;

	switch (type)
	{
	case 0:
		destination = 0; //startLevel
		tempTex = "Images/PortalBlue.png";
		usableTextures.push_back(tempTex);
		break;

	case 1:
		destination = 1; //firstLevel
		tempTex = "Images/PortalRed.png";
		usableTextures.push_back(tempTex);
		break;

	case 2:
		destination = 2; //secondLevel
		tempTex = "Images/PortalViolet.png";
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
	destRect.h = destRect.h * 1.5; //Wysokoœæ w grze
	destRect.w = destRect.w * 1.5; //Szerokoœæ w grzeu
}

//Renderowanie bohatera
void TeleportObject::Render()
{
	BasicRender(); //Podstawowa funkcja z klasy interfejsu
}
//PODSTAWOWE