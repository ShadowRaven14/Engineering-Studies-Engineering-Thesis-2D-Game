#pragma once
#include "_VirtualObject.h"

class CoinObject :
    public virtual _VirtualObject
{
public:
    //Podstawowe
    CoinObject(unsigned short type);
    CoinObject(const char* texturesheet, int x, int y);
    CoinObject(const char* texturesheet);
    ~CoinObject();
    void Update();
    void Render();
};

