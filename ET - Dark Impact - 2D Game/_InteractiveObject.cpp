#include "_InteractiveObject.h"

//Aktualizacja
void _InteractiveObject::Update()
{
	BasicUpdate(); //Podstawowa funkcja z klasy interfejs
	destRect.h = destRect.h * 3 / 2; //Wysoko�� w grze
	destRect.w = destRect.w * 3 / 2; //Szeroko�� w grzeu
}

//Renderowanie
void _InteractiveObject::Render()
{
	BasicRender(); //Podstawowa funkcja z klasy interfejsu
}