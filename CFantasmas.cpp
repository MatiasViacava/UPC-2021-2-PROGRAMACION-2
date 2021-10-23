#include "CFantasmas.h"

CFantasmas::CFantasmas()
{
	n_elementos = new int;
	*n_elementos = 0;
	
}

CFantasmas::~CFantasmas()
{
	for (int i = 0; i < *n_elementos; i++)
		delete arr[i];
	delete[] arr;
	delete n_elementos;
}

void CFantasmas::Mover_Fantasmas(int wventana, int hventana)
{
	for (int i = 0; i < *n_elementos; i++)
	{
		arr[i]->Mover(wventana, hventana);
	}
}

void CFantasmas::Insertar_4_Fantasmas()
{
	
	for (int j = 0; j < 4; j++)
	{
		CFantasma** axu = new CFantasma * [*n_elementos + 1];
		for (int i = 0; i < *n_elementos; i++)
			axu[i] = arr[i];
		axu[*n_elementos] = new CFantasma();
		*n_elementos = *n_elementos + 1;
		arr = axu;
		
	}
	
}


