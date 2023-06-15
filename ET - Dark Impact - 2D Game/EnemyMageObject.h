#pragma once
#include "_EnemyObject.h"

class EnemyMageObject :
    public _EnemyObject
{
public:
    EnemyMageObject();
    EnemyMageObject(unsigned short type);
    EnemyMageObject(const char* texturesheet, int x, int y);
    EnemyMageObject(const char* texturesheet);
    ~EnemyMageObject();
};