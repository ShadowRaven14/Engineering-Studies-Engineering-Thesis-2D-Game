#pragma once
#include "_ItemObject.h"

class PotionObject :
    public virtual _ItemObject
{
public:
    //Podstawowe
    PotionObject(unsigned short type); //Konstruktor
    ~PotionObject(); //Destruktor
};

