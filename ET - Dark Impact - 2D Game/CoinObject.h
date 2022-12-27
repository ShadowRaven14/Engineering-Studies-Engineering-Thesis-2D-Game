#pragma once
#include "_VirtualObject.h"
class CoinObject :
    public virtual _VirtualObject
{
public:
    CoinObject(const char* texturesheet, int x, int y);
    CoinObject(const char* texturesheet);
    ~CoinObject();
    void Update();
    void Render();
};

