#include "_ItemObject.h"

//Aktualizacja
void _ItemObject::Update()
{
	BasicUpdate(); //Podstawowa funkcja z klasy interfejs
	destRect.h = destRect.h * 2 / 3; //Wysokoœæ w grze
	destRect.w = destRect.w * 2 / 3; //Szerokoœæ w grzeu
}

//Renderowanie
void _ItemObject::Render()
{
	BasicRender(); //Podstawowa funkcja z klasy interfejsu
}