#include "Caballero.h"

Caballero::Caballero()
{
}

Caballero::Caballero(int px, int py, int ph, int pw) :Base(px, py, pw, ph, 4, 5, 0, 0)
{
	fracc_movimiento_X = 2; //NO QUIERE DECIR QUE HAY DESPLAZAMIENTO EN X
	fracc_movimiento_Y = 2; //NO QUIERE DECIR QUE HAY DESPLAZAMIENTO EN Y
	Desplazamiento(direccion::derecha);
}

void Caballero::Mover(Graphics^ g)
{
	if (x + dx<1 || x + dx + w>g->VisibleClipBounds.Width) dx = 0;
	x += dx;
}

void Caballero::Disparar()
{
	if (balas.size()<5)
	{
		balas.push_back(new Flechas(x + w / 2, y, 1, 1));
	}
	

}

void Caballero::Mover_Fechas(Graphics^ g, Bitmap^ bmp)
{
	for (int i = 0; i < balas.size(); i++)
	{
		balas.at(i)->Dibujar_Imagen_ball(g, bmp);
		balas.at(i)->Mover(g);
	}
	for (int i = 0; i < balas.size(); i++)
	{
		if (balas.at(i)->get_eliminar() == true)
		{
			balas.erase(balas.begin() + i);
		}
	}
}

vector<Flechas*> Caballero::get_bala()
{
	return balas;
}

int Caballero::get_cant_fecha()
{
	return balas.size();
}

Flechas* Caballero::retornar_flecha_indice(int indice)
{
	return balas.at(indice);
}

Caballero::~Caballero()
{
}
