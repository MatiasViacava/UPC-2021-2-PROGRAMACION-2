#pragma once
#include <vector>
#include "Caballero.h"
#include "Dragon.h"
class Controladora
{
private:
	Caballero* objC;
	Dragon* objD;
	int num_disparos;

public:
	Controladora();
	void Draw_Nave(Graphics^ g, Bitmap^ bmp);
	void Move_Nave(direccion nuevo);
	void Draw_Dragon(Graphics^ g, Bitmap^ bmp);
	void Disparar();
	void Dibujar_Balas(Graphics^ g, Bitmap^ bmp);
	bool Colision();
	bool termino();
	bool termino_sinflechas();
	~Controladora();
};

