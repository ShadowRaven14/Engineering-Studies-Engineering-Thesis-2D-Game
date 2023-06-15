#pragma once
#include "_ItemObject.h"

class PotionObject :
    public virtual _ItemObject
{
public:
    PotionObject(unsigned short type);
    ~PotionObject(); //Destruktor skrzynki
};

