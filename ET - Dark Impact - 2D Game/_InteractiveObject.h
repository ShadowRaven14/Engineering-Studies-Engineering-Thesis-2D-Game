#pragma once
#include "__VirtualObject.h"
class _InteractiveObject :
    public virtual __VirtualObject
{
public:
    //Podstawowe
    void Update();
    void Render();

    //Zaawansowane
    unsigned short challenge;
};

