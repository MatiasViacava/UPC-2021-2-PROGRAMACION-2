#include "Controladora.h"
Controladora::Controladora()
{
	int n_pelotas = 10 + rand() % 20;
	for (int i = 0; i < n_pelotas; i++)
	{
		if (i % 2 == 0)
		{
			arr.push_back(new Playa(1 + rand() % 500, 1 + rand() % 300, 10, 10));
		}
		if (i % 3 == 0)
		{
			arr.push_back(new Futbol(4 + rand() % 300, 1 + rand() % 500, 10, 10));
		}
		if (i % 4 == 0)
		{
			arr.push_back(new Bowling(6 + rand() % 450, 1 + rand() % 800, 10, 10));
		}
		if (i % 5 == 0)
		{
			arr.push_back(new Basket(12 + rand() % 650, 1 + rand() % 900, 10, 10));
		}
		
	}
	objM = new Monigote(45, 85, 20, 20);
}

void Controladora::Draw_All(Graphics^ g, Bitmap^ bmp)
{
	for (int i = 0; i < arr.size(); i++)
	{
		arr.at(i)->Dibujar_Imagen_ball(g, bmp);
		arr.at(i)->Mover(g);
	}

}

void Controladora::Draw_Monigote(Graphics^ g, Bitmap^ bmp)
{
	objM->Dibujar_Imagen_ball(g, bmp);
	objM->Mover(g);
}

void Controladora::Move_Monigote(direccion nuevo)
{
	objM->Desplazamiento(nuevo);
	Colision();

}

bool Controladora::Colision()
{
	bool resultado_colision = false;
	Rectangle r1 = objM->get_Rectangle();
	for (int i = 0; !resultado_colision&& i < arr.size(); i++)
	{
		Rectangle r2 = arr.at(i)->get_Rectangle();
		if (r1.IntersectsWith(r2))
		{
			resultado_colision=true;
			arr.at(i)->set_DX(arr.at(i)->get_DX() * -1);
			arr.at(i)->set_DY(arr.at(i)->get_DY() * -1);
		}
	}
	return resultado_colision;
}

Controladora::~Controladora()
{
	delete objM;
	for (int i = 0; i < arr.size(); i++)
		delete arr.at(i);
	arr.clear();
	
}
