#pragma once
#include "_ItemObject.h"

class AppleItemObject :
    public virtual _ItemObject
{
public:
    AppleItemObject(unsigned short type);
    ~AppleItemObject(); //Destruktor jab³ka
};

