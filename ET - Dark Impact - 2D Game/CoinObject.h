#pragma once
#include "_ItemObject.h"

class CoinObject :
    public virtual _ItemObject
{
public:
    //Podstawowe
    CoinObject(unsigned short type);
    CoinObject(const char* texturesheet, int x, int y);
    CoinObject(const char* texturesheet);
    ~CoinObject();
};

