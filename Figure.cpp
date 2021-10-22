#include "Figure.h"

Figure::Figure()
{
}

void Figure::Borrar()
{
    for (int i = x; i < x + w; i++) {
        for (int j = y; j < y + h; j++) {
            Console::SetCursorPosition(i, j);
            cout << " ";
        }
    }
}

void Figure::PerderVida()
{
    vidas--;
}



int Figure::getX()
{
    return x;
}

int Figure::getDX()
{
    return dx;
}

int Figure::getDY()
{
    return dy;
}

int Figure::getY()
{
    return y;
}

int Figure::getH()
{
    return h;
}

int Figure::getW()
{
    return w;
}

void Figure::set_X(int nuevo)
{
    x=nuevo;
}

void Figure::set_y(int nuevo)
{
    y = nuevo;
}

void Figure::set_dx(int nuevo_dx)
{
    dx = nuevo_dx;
}

void Figure::set_dy(int nuevo_dy)
{
    dy = nuevo_dy;
}

int Figure::getVidas()
{
    return vidas;
}

int Figure::getTipo()
{
    return tipo;
}

Figure::~Figure()
{
}
