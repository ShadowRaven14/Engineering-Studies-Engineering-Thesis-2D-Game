#pragma once
#include "__VirtualObject.h"
class _InteractiveObject :
    public virtual __VirtualObject
{
public:
	//Podstawowe
	void Update(); //Aktualizacja
	void Render(); //Renderowanie

    //Zaawansowane
    unsigned short challenge = 0;
};

