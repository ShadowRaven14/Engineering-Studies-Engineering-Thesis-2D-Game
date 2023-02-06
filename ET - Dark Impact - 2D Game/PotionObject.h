#pragma once
#include "_VirtualObject.h"

class PotionObject :
    public virtual _VirtualObject
{
public:
    PotionObject(unsigned short type);
    ~PotionObject(); //Destruktor skrzynki
    void Update(); //Aktualizacja skrzynki
    void Render(); //Renderowanie skrzynki

    short power;
};

