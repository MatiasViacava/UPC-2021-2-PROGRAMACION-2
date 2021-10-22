#pragma once
#include "Figure.h"
class Fantasma :
    public Figure
{
public:

    Fantasma();
    void Imprimir();
    void Mover(int wventana, int hventana);
    ~Fantasma();
};

