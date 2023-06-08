#include "EnemyObject.h"

//Konstruktor wroga
EnemyObject::EnemyObject(unsigned short type)
{
	const char* tempTex;

	switch (type)
	{
	case 0:
		power = 100;
		tempTex = "Images/MagicChaos.png";
		usableTextures.push_back(tempTex);
		tempTex = "Images/MagicChaos.png";
		usableTextures.push_back(tempTex);
		tempTex = "Images/AppleNormal.png";
		usableTextures.push_back(tempTex);
		break;

	case 1:
		power = 100;
		tempTex = "Images/MagicFire.png";
		usableTextures.push_back(tempTex);
		tempTex = "Images/MagicFire.png";
		usableTextures.push_back(tempTex);
		tempTex = "Images/AppleNormal.png";
		usableTextures.push_back(tempTex);
		break;


	case 2:
		power = 15;
		tempTex = "Images/HumanMageGreen_GoRight.png";
		usableTextures.push_back(tempTex);
		tempTex = "Images/HumanMageGreen_GoLeft.png";
		usableTextures.push_back(tempTex);
		tempTex = "Images/AppleNormal.png";
		usableTextures.push_back(tempTex);
		break;

	case 3:
		power = 30;
		tempTex = "Images/HumanMageBlue_GoRight.png";
		usableTextures.push_back(tempTex);
		tempTex = "Images/HumanMageBlue_GoLeft.png";
		usableTextures.push_back(tempTex);
		tempTex = "Images/AppleNormal.png";
		usableTextures.push_back(tempTex);
		break;

	case 4:
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
	
	switch (typeOfMovement)
	{
	case 1:
		MoveWithEnemyV1();
		break;

	case 2:
		MoveWithEnemyV2();
		break;

	case 3:
		MoveWithEnemyV3();
		break;

	default:
		break;
	}
	
}

//Renderowanie wroga
void EnemyObject::Render()
{
	BasicRender(); //Podstawowa funkcja z klasy interfejsu
}

void EnemyObject::RandomizeTypeOfMovement()
{
	typeOfMovement = rand() % 3 + 1;
	//std::cout << "typeOfMovement: " << typeOfMovement << std::endl;
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

//Poruszanie siê wroga
void EnemyObject::MoveWithEnemyV2()
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
		cordsOfObject.x = cordsOfObject.x + 2;
		break;

	case false:
		cordsOfObject.x = cordsOfObject.x - 2;
		break;
	}


	if (cordsOfObject.y <= 64)
		isMovingUp = true;

	else if (cordsOfObject.y >= Game::windowY - 64) //864
		isMovingUp = false;


	switch (isMovingUp)
	{
	case true:
		cordsOfObject.y = cordsOfObject.y + 8;
		break;

	case false:
		cordsOfObject.y = cordsOfObject.y - 8;
		break;
	}
}

//Poruszanie siê wroga
void EnemyObject::MoveWithEnemyV3()
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
		cordsOfObject.x = cordsOfObject.x + 8;
		break;

	case false:
		cordsOfObject.x = cordsOfObject.x - 8;
		break;
	}


	if (cordsOfObject.y <= 64)
		isMovingUp = true;

	else if (cordsOfObject.y >= Game::windowY - 64) //864
		isMovingUp = false;


	switch (isMovingUp)
	{
	case true:
		cordsOfObject.y = cordsOfObject.y + 2;
		break;

	case false:
		cordsOfObject.y = cordsOfObject.y - 2;
		break;
	}
}

void EnemyObject::ChangeCurrentTexture(int n)
{
	currentObjectTexture = ImageTextureManager::LoadTexture(usableTextures[n]);
}