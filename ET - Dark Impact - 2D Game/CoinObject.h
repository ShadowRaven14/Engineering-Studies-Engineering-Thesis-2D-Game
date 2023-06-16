#pragma once
#include "_ItemObject.h"

class CoinObject :
    public virtual _ItemObject
{
public:
    //Podstawowe
    CoinObject(unsigned short type); //Konstruktor
    CoinObject(const char* texturesheet, int x, int y); //Konstruktor
    CoinObject(const char* texturesheet); //Konstruktor
    ~CoinObject(); //Destruktor
};

