#pragma once
#include "_EnemyObject.h"

class EnemySentinelObject :
    public _EnemyObject
{
public:
    //Podstawowe
    EnemySentinelObject(); //Konstruktor
    EnemySentinelObject(unsigned short type); //Konstruktor
    EnemySentinelObject(const char* texturesheet, int x, int y); //Konstruktor
    EnemySentinelObject(const char* texturesheet); //Konstruktor
    ~EnemySentinelObject(); //Destruktor
};