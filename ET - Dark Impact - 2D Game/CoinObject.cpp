#include "CoinObject.h"
using namespace std;

CoinObject::CoinObject(unsigned short type)
{
	switch (type)
	{
	case 1:
		const char* tex1 = "Images/Coin.png";
		usableTextures.push_back(tex1);
		break;

	default:
		std::cout << "Error: Type Construktor." << std::endl;
		break;
	}

	RandomizeCoordinates(usableTextures[0]); //Podstawowa funkcja z klasy interfejsu
}

CoinObject::CoinObject(const char* texturesheet, int x, int y)
{
	BasicInit(texturesheet, x, y); //Podstawowa funkcja z klasy interfejsu
}

CoinObject::CoinObject(const char* texturesheet)
{
	RandomizeCoordinates(texturesheet);  //Podstawowa funkcja z klasy interfejsu
}

//Aktualizacja bohatera
void CoinObject::Update()
{
	BasicUpdate(); //Podstawowa funkcja z klasy interfejsu
	srcRect.h = srcRect.h * 2; //Wysoko�� w pikselach
	srcRect.w = srcRect.w * 2; //Szeroko�� w pikselach
}

//Renderowanie bohatera
void CoinObject::Render()
{
	BasicRender(); //Podstawowa funkcja z klasy interfejsu
}