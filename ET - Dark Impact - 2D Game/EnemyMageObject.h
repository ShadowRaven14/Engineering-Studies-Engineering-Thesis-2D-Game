#pragma once
#include "_EnemyObject.h"

class EnemyMageObject :
    public _EnemyObject
{
public:
    //Podstawowe
    EnemyMageObject(); //Konstruktor
    EnemyMageObject(unsigned short type); //Konstruktor
    EnemyMageObject(const char* texturesheet, int x, int y); //Konstruktor
    EnemyMageObject(const char* texturesheet); //Konstruktor
    ~EnemyMageObject(); //Destruktor
};