#include "_ItemObject.h"

//Aktualizacja
void _ItemObject::Update()
{
	BasicUpdate(); //Podstawowa funkcja z klasy interfejs
	destRect.h = destRect.h * 2 / 3; //Wysoko�� w grze
	destRect.w = destRect.w * 2 / 3; //Szeroko�� w grzeu
}

//Renderowanie
void _ItemObject::Render()
{
	BasicRender(); //Podstawowa funkcja z klasy interfejsu
}