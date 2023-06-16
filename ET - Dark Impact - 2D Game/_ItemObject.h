#pragma once
#include "__VirtualObject.h"

class _ItemObject :
    public virtual __VirtualObject
{
public:
    //Podstawowe
    void Update();
    void Render();

    //Zaawansowane
    unsigned short power;
};
