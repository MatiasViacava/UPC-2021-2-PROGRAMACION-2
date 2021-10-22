#pragma once
#include "Figure.h"
public enum direccion { izquierda, derecha, arriba, abajo };
class Pacman :
    public Figure
{
private:
    direccion orientacion;
    int speed;
public:
    Pacman();
    void Mover(int wventana, int hventana);
    void Imprimir();
    void Desplazamiento(direccion nuevo);
    int get_speed();
    void set_speed(int nuevo);
    ~Pacman();
};
/*
  __ 
 / o\
|   <
C



*/

