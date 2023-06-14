#pragma once
#include "ItemObject.h"

class AppleItemObject :
    public virtual ItemObject
{
public:
    AppleItemObject(unsigned short type);
    ~AppleItemObject(); //Destruktor jab�ka
    void Update(); //Aktualizacja jab�ka
    void Render(); //Renderowanie jab�ka
};

