#pragma once
#include "EnemyObject.h"

class EnemySentinelObject :
    public virtual EnemyObject
{
public:
    EnemySentinelObject(unsigned short type);
    ~EnemySentinelObject();
};