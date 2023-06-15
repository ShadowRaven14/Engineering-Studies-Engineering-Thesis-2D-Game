#pragma once
#include "_EnemyObject.h"

class EnemySentinelObject :
    public _EnemyObject
{
public:
    EnemySentinelObject();
    EnemySentinelObject(unsigned short type);
    EnemySentinelObject(const char* texturesheet, int x, int y);
    EnemySentinelObject(const char* texturesheet);
    ~EnemySentinelObject();
};