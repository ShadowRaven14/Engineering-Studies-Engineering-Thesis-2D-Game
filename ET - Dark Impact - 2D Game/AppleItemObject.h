#pragma once
#include "_ItemObject.h"

class AppleItemObject :
    public virtual _ItemObject
{
public:
    //Podstawowe
    AppleItemObject(unsigned short type); //Konstruktor
    ~AppleItemObject(); //Destruktor
};

