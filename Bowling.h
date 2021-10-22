#pragma once
#include "Base.h"
class Bowling :
    public Base
{
public:
    Bowling();
    Bowling(int px, int py, int ph, int pw);
    ~Bowling();
    void Mover(Graphics^ g);
};

