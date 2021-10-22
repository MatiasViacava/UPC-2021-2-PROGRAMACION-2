#pragma once
#include "Base.h"
class Playa :
    public Base
{
public:
    Playa();
    Playa(int px, int py, int ph, int pw);
    ~Playa();
    void Mover(Graphics^g);
};

