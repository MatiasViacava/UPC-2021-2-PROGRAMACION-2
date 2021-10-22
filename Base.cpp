#include "Base.h"

Base::Base()
{
    eliminar = false;
    dx = dy = 0;
    orientacion = direccion::ninguno;
}

Base::Base(int px, int py, int pw, int ph)
{
    x = px;
    y = py;
    w = pw;
    h = ph;
    eliminar = false;
    orientacion = direccion::ninguno;
}

Base::Base(int px, int py, int pw, int ph, int pmaxfil, int pmaxCol, int pfila, int pcol)
{
    x = px;
    y = py;
    w = pw;
    h = ph;
    eliminar = false;
    orientacion = direccion::ninguno;
    max_columna = pmaxCol;
    max_fila = pmaxfil;
    col =pcol;
    fil = pfila;

}

Base::~Base()
{
}

void Base::set_X(int nuevo)
{
    x = nuevo;
}

void Base::set_Y(int nuevo)
{
    y = nuevo;
}

void Base::set_W(int nuevo)
{
    w = nuevo;
}

void Base::set_H(int nuevo)
{
    h = nuevo;
}

void Base::set_DX(int nuevo)
{
    dx = nuevo;
}

void Base::set_DY(int nuevo)
{
    dy = nuevo;
}

void Base::set_maxfila(int nuevo)
{
    max_fila = nuevo;
}

void Base::set_maxColumna(int nuevo)
{
    max_columna = nuevo;
}

void Base::set_fracc_movimiento_X(int nuevo)
{
    fracc_movimiento_X = nuevo;
}

void Base::set_fracc_movimiento_Y(int nuevo)
{
    fracc_movimiento_Y = nuevo;
}

void Base::set_eliminar(bool nuevo)
{
    eliminar = nuevo;
}

void Base::Desplazamiento(direccion nuevo)
{
    orientacion = nuevo;
    dx = dy = 0;
    if (orientacion == direccion::arriba) { dy = -(h / fracc_movimiento_Y); fil = 2; }
    if (orientacion == direccion::abajo) { dy = (h / fracc_movimiento_Y); fil = 3; }
    if (orientacion == direccion::izquierda) { dx = -(w / fracc_movimiento_X); fil = 0; }
    if (orientacion == direccion::derecha) { dx = (w / fracc_movimiento_X);    fil = 1; }
}

int Base::get_X()
{
    return x;
}

int Base::get_Y()
{
    return y;
}

int Base::get_DX()
{
    return dx;
}

int Base::get_DY()
{
    return dy;
}

int Base::get_W()
{
    return w;
}

int Base::get_H()
{
    return h;
}

int Base::get_maxfila()
{
    return max_fila;
}

int Base::get_maxColumna()
{
    return max_columna;
}

int Base::get_fracc_movimiento_X()
{
    return fracc_movimiento_X;
}

int Base::get_fracc_movimiento_Y()
{
    return fracc_movimiento_Y;
}

bool Base::get_eliminar()
{
    return eliminar;
}

Rectangle Base::get_Rectangle()
{
    return Rectangle(x,y,w,h);
}

void Base::Mover(Graphics^ g)
{
    if (x + dx<1 || x + dx + w>g->VisibleClipBounds.Width) dx *= -1;
    if (y + dy<1 || y + dy + h>g->VisibleClipBounds.Height)dy *= -1;
    x += dx;
    y += dy;
}

void Base::Dibujar(Graphics^ g)
{
}

void Base::Dibujar_Imagen_ball(Graphics^ g, Bitmap^ bmp)
{
    w = bmp->Width / max_columna;
    h = bmp->Height / max_fila;
    Rectangle porcion = Rectangle(col * w, fil * h, w, h);
    g->DrawImage(bmp, x, y, porcion, GraphicsUnit::Pixel);
    col++;
    if (col >= max_columna)
    {
        col = 0;
    }
}

void Base::Borrar(Graphics^ g)
{
    
}
