#pragma once
#include "__VirtualObject.h"

class _ItemObject :
    public virtual __VirtualObject
{
public:
	//Podstawowe
	void Update(); //Aktualizacja
	void Render(); //Renderowanie

    //Zaawansowane
    unsigned short power = 0;
};
