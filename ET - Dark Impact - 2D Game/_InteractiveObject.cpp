#include "_InteractiveObject.h"

//Aktualizacja
void _InteractiveObject::Update()
{
	BasicUpdate(); //Podstawowa funkcja z klasy interfejs
	destRect.h = destRect.h * 3 / 2; //Wysokoœæ w grze
	destRect.w = destRect.w * 3 / 2; //Szerokoœæ w grzeu
}

//Renderowanie
void _InteractiveObject::Render()
{
	BasicRender(); //Podstawowa funkcja z klasy interfejsu
}