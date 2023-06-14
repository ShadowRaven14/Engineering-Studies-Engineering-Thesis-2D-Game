#pragma once
#include "ItemObject.h"

class AppleItemObject :
    public virtual ItemObject
{
public:
    AppleItemObject(unsigned short type);
    ~AppleItemObject(); //Destruktor jab³ka
    void Update(); //Aktualizacja jab³ka
    void Render(); //Renderowanie jab³ka
};

