#include "Controladora.h"

Controladora::Controladora()
{
    objC = new Caballero(50, 350, 20, 20);
    objD = new Dragon(20, 20, 20, 20);
    num_disparos = 0;
}

void Controladora::Draw_Nave(Graphics^ g, Bitmap^ bmp)
{
    objC->Dibujar_Imagen_ball(g, bmp);
    objC->Mover(g);
    Colision();
}

void Controladora::Move_Nave(direccion nuevo)
{
    objC->Desplazamiento(nuevo);
}

void Controladora::Draw_Dragon(Graphics^ g, Bitmap^ bmp)
{
    objD->Dibujar_Imagen_ball(g, bmp);
    objD->Mover(g);
}

void Controladora::Disparar()
{
    objC->Disparar();
    num_disparos++;
}

void Controladora::Dibujar_Balas(Graphics^ g, Bitmap^ bmp)
{
    objC->Mover_Fechas(g, bmp);
}
bool Controladora::Colision()
{
    bool resultado_colision = false;
    Rectangle Caballero = objC->get_Rectangle();
    for (int i = 0; i < objC->get_cant_fecha(); i++)
    {
        Rectangle Flechas = objC->retornar_flecha_indice(i)->get_Rectangle();
        Rectangle Dragon = objD->get_Rectangle();
        if (Flechas.IntersectsWith(Dragon))
        {
            resultado_colision = true;
            objC->retornar_flecha_indice(i)->set_eliminar(true);
            objD->Perder_Vidas();
        }
    }
    return resultado_colision;
}

bool Controladora::termino()
{
    bool game_over = false;
    if (objD->get_Vidas() <= 0)
    {
        game_over = true;
    }
    
    return game_over;
}

bool Controladora::termino_sinflechas()
{
    bool gamer_kks = false;
    if (num_disparos>25)
    {
        gamer_kks = true;
    }
    return gamer_kks;
}

Controladora::~Controladora()
{
    delete objC, objD;
}
