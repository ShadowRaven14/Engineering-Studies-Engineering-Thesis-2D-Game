#include "TeleportObject.h"

//Konstruktor
TeleportObject::TeleportObject(unsigned short type)
{
	const char* tempTex;

	switch (type)
	{
	case 0:
		destination = 0; //startLevel
		challenge = 15;
		tempTex = "Images/PortalBlue.png";
		usableTextures.push_back(tempTex);
		break;

	case 1:
		destination = 1; //firstLevel
		challenge = 30;
		tempTex = "Images/PortalRed.png";
		usableTextures.push_back(tempTex);
		break;

	case 2:
		destination = 2; //secondLevel
		challenge = 45;
		tempTex = "Images/PortalViolet.png";
		usableTextures.push_back(tempTex);
		break;

	case 3:
		destination = 3;
		challenge = 60;
		tempTex = "Images/PortalGreen.png";
		usableTextures.push_back(tempTex);
		break;

	case 4:
		destination = 4;
		challenge = 75;
		tempTex = "Images/PortalYellow.png";
		usableTextures.push_back(tempTex);
		break;

	default:
		destination = 0;
		std::cout << "Error: Type Construktor." << std::endl;
		tempTex = "Images/AppleNormal.png";
		usableTextures.push_back(tempTex);
		break;
	}

	RandomizeCoordinates(usableTextures[0]); //Podstawowa funkcja z klasy interfejsu
}

//Konstruktor
TeleportObject::TeleportObject(const char* texturesheet, int x, int y, int des)
{
	BasicInit(texturesheet, x, y); //Podstawowa funkcja z klasy interfejsu
	coordinatesOfTeleport.x = x;
	coordinatesOfTeleport.y = y;
	destination = des;
}

//Konstruktor
TeleportObject::TeleportObject(const char* texturesheet, Point* point, int des)
{
	BasicInit(texturesheet, point->x, point->y); //Podstawowa funkcja z klasy interfejsu
	coordinatesOfTeleport.x = point->x;
	coordinatesOfTeleport.y = point->y;
	destination = des;
}

//Konstruktor
TeleportObject::TeleportObject(const TeleportObject& tempObject)
{
	currentObjectTexture = tempObject.currentObjectTexture;
	cordsOfObject = tempObject.cordsOfObject;
	destination = tempObject.destination;
}

TeleportObject::~TeleportObject()
{
	BasicDelete();
}
