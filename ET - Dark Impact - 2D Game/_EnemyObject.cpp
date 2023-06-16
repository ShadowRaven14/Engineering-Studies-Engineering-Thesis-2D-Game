#include "_EnemyObject.h"

//Aktualizacja
void _EnemyObject::Update()
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

	case 4:
		MoveWithEnemyV4();
		break;

	default:
		break;
	}
	
}

//Renderowanie
void _EnemyObject::Render()
{
	BasicRender(); //Podstawowa funkcja z klasy interfejsu
}

void _EnemyObject::RandomizeTypeOfMovement()
{
	typeOfMovement = rand() % 4 + 1;
	//std::cout << "typeOfMovement: " << typeOfMovement << std::endl;
}

//Poruszanie siê wroga 1
void _EnemyObject::MoveWithEnemyV1()
{

	if (cordsOfObject.x <= 64)
	{
		isMovingRight = true;
		currentObjectTexture = ImageTextureManager::LoadTexture(usableTextures[0]);
	}
	else if (cordsOfObject.x >= Game::windowX - 64)
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

	else if (cordsOfObject.y >= Game::windowY - 64)
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

//Poruszanie siê wroga 2
void _EnemyObject::MoveWithEnemyV2()
{

	if (cordsOfObject.x <= 64)
	{
		isMovingRight = true;
		currentObjectTexture = ImageTextureManager::LoadTexture(usableTextures[0]);
	}
	else if (cordsOfObject.x >= Game::windowX - 64)
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

	else if (cordsOfObject.y >= Game::windowY - 64)
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

//Poruszanie siê wroga 3
void _EnemyObject::MoveWithEnemyV3()
{

	if (cordsOfObject.x <= 64)
	{
		isMovingRight = true;
		currentObjectTexture = ImageTextureManager::LoadTexture(usableTextures[0]);
	}
	else if (cordsOfObject.x >= Game::windowX - 64)
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

	else if (cordsOfObject.y >= Game::windowY - 64)
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

//Poruszanie siê wroga 4
void _EnemyObject::MoveWithEnemyV4()
{

	if (cordsOfObject.x <= 32)
	{
		isMovingRight = true;
		currentObjectTexture = ImageTextureManager::LoadTexture(usableTextures[0]);
	}
	else if (cordsOfObject.x >= (Game::gameX - 64) + ((Game::windowX - Game::gameX) / 2) - 192)
	{
		isMovingRight = false;
		currentObjectTexture = ImageTextureManager::LoadTexture(usableTextures[1]);

	}

	short rx = rand() % 4 + 8;
	short ry = rand() % 4 + 8;

	switch (isMovingRight)
	{
	case true:
		cordsOfObject.x = cordsOfObject.x + rx;
		break;

	case false:
		cordsOfObject.x = cordsOfObject.x - rx;
		break;
	}


	if (cordsOfObject.y <= 32)
		isMovingUp = true;

	else if (cordsOfObject.y >= (Game::gameY - 64) + ((Game::windowY - Game::gameY) / 2) - 192)
		isMovingUp = false;


	switch (isMovingUp)
	{
	case true:
		cordsOfObject.y = cordsOfObject.y + ry;
		break;

	case false:
		cordsOfObject.y = cordsOfObject.y - ry;
		break;
	}
}

void _EnemyObject::ChangeCurrentTexture(int n)
{
	currentObjectTexture = ImageTextureManager::LoadTexture(usableTextures[n]);
}