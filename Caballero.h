#pragma once
#include <vector>
#include "Base.h"
#include "Flechas.h"
using namespace std;
class Caballero :
	public Base
{
private:
	vector<Flechas*>balas;
public:
	Caballero();
	Caballero(int px, int py, int ph, int pw);
	void Mover(Graphics^ g);
	void Disparar();
	void Mover_Fechas(Graphics^ g, Bitmap^ bmp);
	vector<Flechas*>get_bala();
	int get_cant_fecha();
	Flechas* retornar_flecha_indice(int indice);
	~Caballero();
};