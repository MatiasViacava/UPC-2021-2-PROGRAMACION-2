#pragma once
#include "CFantasma.h"
class CFantasmas
{
private:
	CFantasma** arr;
	int* n_elementos;
	
public:
	CFantasmas();
	~CFantasmas();
	void Mover_Fantasmas(int wventana, int hventana);
	void Insertar_4_Fantasmas();


};

