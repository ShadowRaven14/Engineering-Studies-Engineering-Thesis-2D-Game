#include "_InteractiveObject.h"

void _InteractiveObject::Update()
{
	BasicUpdate(); //Podstawowa funkcja z klasy interfejs
	destRect.h = destRect.h * 1.5; //Wysoko�� w grze
	destRect.w = destRect.w * 1.5; //Szeroko�� w grzeu
}

void _InteractiveObject::Render()
{
	BasicRender(); //Podstawowa funkcja z klasy interfejsu
}