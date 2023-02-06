#include "EnemyObject.h"

//Konstruktor wroga
EnemyObject::EnemyObject(unsigned short type)
{
	const char* tempTex;

	switch (type)
	{
	case 1:
		power = 5;
		tempTex = "Images/HumanMageGreen_GoRight.png";
		usableTextures.push_back(tempTex);
		tempTex = "Images/HumanMageGreen_GoLeft.png";
		usableTextures.push_back(tempTex);
		tempTex = "Images/AppleNormal.png";
		usableTextures.push_back(tempTex);
		break;

	case 2:
		power = 10;
		tempTex = "Images/HumanMageBlue_GoRight.png";
		usableTextures.push_back(tempTex);
		tempTex = "Images/HumanMageBlue_GoLeft.png";
		usableTextures.push_back(tempTex);
		tempTex = "Images/AppleNormal.png";
		usableTextures.push_back(tempTex);
		break;

	case 3:
		power = 15;
		tempTex = "Images/HumanMageRed_GoRight.png";
		usableTextures.push_back(tempTex);
		tempTex = "Images/HumanMageRed_GoLeft.png";
		usableTextures.push_back(tempTex);
		tempTex = "Images/AppleNormal.png";
		usableTextures.push_back(tempTex);
		break;

	default:
		std::cout << "Error: Type Construktor." << std::endl;
		tempTex = "Images/AppleNormal.png";
		usableTextures.push_back(tempTex);
		break;
	}
	
	RandomizeCoordinates(usableTextures[0]); //Podstawowa funkcja z klasy interfejsu

	isMovingRight = isMovingUp = true;
}

EnemyObject::EnemyObject(const char* texturesheet, int x, int y)
{
	BasicInit(texturesheet, x, y); //Podstawowa funkcja z klasy interfejsu
	isMovingRight = isMovingUp = true;
}

EnemyObject::EnemyObject(const char* texturesheet)
{
	RandomizeCoordinates(texturesheet); //Podstawowa funkcja z klasy interfejsu
	isMovingRight = isMovingUp = true;
}

//Aktualizacja wroga
void EnemyObject::Update()
{
	BasicUpdate(); //Podstawowa funkcja z klasy interfejsu
	MoveWithEnemyV1();
}

//Renderowanie wroga
void EnemyObject::Render()
{
	BasicRender(); //Podstawowa funkcja z klasy interfejsu
}

//Poruszanie siê wroga
void EnemyObject::MoveWithEnemyV1()
{

	if (cordsOfObject.x <= 64)
	{
		isMovingRight = true;
		currentObjectTexture = ImageTextureManager::LoadTexture(usableTextures[0]);
	}
	else if (cordsOfObject.x >= Game::windowX - 64) //1248
	{
		isMovingRight = false;
		currentObjectTexture = ImageTextureManager::LoadTexture(usableTextures[1]);

	}

	switch (isMovingRight)
	{
	case true:
		cordsOfObject.x = cordsOfObject.x + 4;
		break;

	case false:
		cordsOfObject.x = cordsOfObject.x - 4;
		break;
	}
	

	if (cordsOfObject.y <= 64)
		isMovingUp = true;

	else if (cordsOfObject.y >= Game::windowY - 64) //864
		isMovingUp = false;
		

	switch (isMovingUp)
	{
	case true:
		cordsOfObject.y = cordsOfObject.y + 4;
		break;

	case false:
		cordsOfObject.y = cordsOfObject.y - 4;
		break;
	}
}

void EnemyObject::ChangeCurrentTexture(int n)
{
	currentObjectTexture = ImageTextureManager::LoadTexture(usableTextures[n]);
}