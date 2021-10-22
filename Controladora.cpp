#include "Controladora.h"

Controladora::Controladora()
{
    objA = new ArrFigure();
    objP = new Pacman();
    can_fantasma = 0;
    can_megafantasma = 0;
    contador_pacdot = 0;
    inmune = false;
}

void Controladora::MoverTodo(int wventana, int hventana)
{
    objA->Mover_Objetos(wventana, hventana);
    Colision();
    inmune_5_segundos();
}

void Controladora::Insrtar_Fantasmas()
{
    if (difftime(time(0), tiempo_inicio) > 3) {
        if (can_fantasma<4)
        {
            objA->Insertar_Fantasma();
            tiempo_inicio = time(0);
            can_fantasma++;
        }
        
    }
    if (can_megafantasma <1)
    {
        objA->Insertar_MegaFantasma();
        can_megafantasma++;
    }
    
}

void Controladora::Insrtar_pacbonus()
{
    for (int  i = 1; i <= 100; i++)
    {
        objA->Insertar_PacDots();
    }
    for (int i = 1; i < 10; i++)
    {
        objA->Insertar_Bonus();
    }
   
}
void Controladora::Colision()
{
    Rectangle rpacman;
    rpacman.X = objP->getX();
    rpacman.Y = objP->getY();
    rpacman.Width = objP->getW();
    rpacman.Height = objP->getH();
    bool resultado_colision = false;
    for (int i = 0; i < objA->get_N(); i++)
    {
        if ((objA->getElemento(i)->getTipo() == 2))
        {
            Rectangle rfantasma;
            rfantasma.X = objA->getElemento(i)->getX();
            rfantasma.Y = objA->getElemento(i)->getY();
            rfantasma.Width = objA->getElemento(i)->getW();
            rfantasma.Height = objA->getElemento(i)->getH();
            resultado_colision = rpacman.IntersectsWith(rfantasma);
            if (resultado_colision==true)
            {
                objP->PerderVida();
                objP->Borrar();
                objP->set_X(1);
                objP->set_y(1);
                objP->Imprimir();
            }
        }
        else if ((objA->getElemento(i)->getTipo() == 3))
        {
            Rectangle rpacdots;
            rpacdots.X = objA->getElemento(i)->getX();
            rpacdots.Y = objA->getElemento(i)->getY();
            rpacdots.Width = objA->getElemento(i)->getW();
            rpacdots.Height = objA->getElemento(i)->getH();
            resultado_colision = rpacman.IntersectsWith(rpacdots);
            if (resultado_colision == true)
            {
                objA->getElemento(i)->PerderVida();
                objA->Eliminar();
                contador_pacdot++;
                
            }
        }
        else if ((objA->getElemento(i)->getTipo() == 4))
        {
            Rectangle rbonus;
            rbonus.X = objA->getElemento(i)->getX();
            rbonus.Y = objA->getElemento(i)->getY();
            rbonus.Width = objA->getElemento(i)->getW();
            rbonus.Height = objA->getElemento(i)->getH();
            resultado_colision = rpacman.IntersectsWith(rbonus);
            if (resultado_colision == true)
            {
                objA->getElemento(i)->PerderVida();
                objA->Eliminar();
                inmune = true;
                tiempo_bonus_inmune=time (0);
                objP->set_dx(objP->get_speed()*2);
                objP->set_dy(objP->get_speed()*2);
                objP->set_speed(2);
                
                int contador = 0;
                bool fin_secuencia = false;
                for (int i = 0; i < objA->get_N(); i++)
                {
                    if (objA->getElemento(i)->getTipo()==2)
                    {
                        contador++;
                    }
                }
                if (contador>0)
                {
                    while (fin_secuencia==false)
                    {
                        int elemento_Random = rand() % objA->get_N();
                        if (objA->getElemento(elemento_Random)->getTipo() == 2)
                        {
                            objA->getElemento(elemento_Random)->PerderVida();
                            objA->Eliminar();
                            fin_secuencia = true;
                        }
                       
                    }

                }

            }
        }
        else if ((objA->getElemento(i)->getTipo() == 1))
        {
            Rectangle rMegaFanstama;
            rMegaFanstama.X = objA->getElemento(i)->getX();
            rMegaFanstama.Y = objA->getElemento(i)->getY();
            rMegaFanstama.Width = objA->getElemento(i)->getW();
            rMegaFanstama.Height = objA->getElemento(i)->getH();
            resultado_colision = rpacman.IntersectsWith(rMegaFanstama);
            if (resultado_colision == true)
            {
                if (inmune==false)
                {
                    objP->PerderVida();
                    objP->PerderVida();
                    objP->set_X(1);
                    objP->set_y(1);
                    objP->Borrar();
                }
                

            }
        }
    }
}

void Controladora::Imprimir_Pacman()
{
    objP->Imprimir();
}

bool Controladora::termino_juego()
{
    return false;
}

void Controladora::Eliminar_Figuras()
{
    objA->Eliminar();
}

bool Controladora::tiene_vidas()
{
    return objP->getVidas()>0;
}

void Controladora::inmune_5_segundos()
{
    if (difftime(time(0), tiempo_bonus_inmune)>5)
    {
        objP->set_speed(1);
        inmune = false;
    }
}

void Controladora::Reporte()
{
    cout << "LA CANTIDAD DE PACDOTS COMIDOS FUE: " << contador_pacdot << endl;
}

void Controladora::Mover_Persona(char tecla, int wventana, int hventana)
{
    if ((tecla) == 'W')objP->Desplazamiento(arriba);
    if ((tecla) == 'A')objP->Desplazamiento(izquierda);
    if ((tecla) == 'S')objP->Desplazamiento(abajo);
    if ((tecla) == 'D')objP->Desplazamiento(derecha);
    objP->Mover(wventana, hventana);
}

Controladora::~Controladora()
{
    delete objA, objP;
}
