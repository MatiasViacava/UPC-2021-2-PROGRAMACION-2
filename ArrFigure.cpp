#include "ArrFigure.h"

ArrFigure::ArrFigure()
{
   n = new int;
    *n = 0;
}

void ArrFigure::Insertar_Fantasma()
{
	Figure** aux = new Figure * [*n + 1];
	for (int i = 0; i < *n; i++) {
		aux[i] = arr[i];
	}
	aux[*n] = new Fantasma();
	(*n)++;
	arr = aux;
}

void ArrFigure::Insertar_MegaFantasma()
{
	Figure** aux = new Figure * [*n + 1];
	for (int i = 0; i < *n; i++) {
		aux[i] = arr[i];
	}
	aux[*n] = new MegaFantasma();
	(*n)++;
	arr = aux;
}

void ArrFigure::Insertar_PacDots()
{
		Figure** aux = new Figure * [*n + 1];
		for (int i = 0; i < *n; i++) {
			aux[i] = arr[i];
		}
		aux[*n] = new PacDots();
		(*n)++;
		arr = aux;
}

void ArrFigure::Insertar_Bonus()
{
	
		Figure** aux = new Figure * [*n + 1];
		for (int i = 0; i < *n; i++) {
			aux[i] = arr[i];
		}
		aux[*n] = new Bonus();
		(*n)++;
		arr = aux;
	
}

void ArrFigure::Eliminar()
{
	int cont = 0;
	for (int i = 0; i < *n; i++)
	{
		if (arr[i]->getVidas() <= 0)
		{

			cont++;
		}
	}
	Figure** aux = new Figure * [*n - cont];
	int K = 0;
	for (int j = 0; j < *n; j++)
	{
		if (arr[j]->getVidas() > 0)
		{
			aux[K] = arr[j];
			K++;
		}
		else
		{
			arr[j]->Borrar();
		}
	}
	*n = *n - cont;
	arr = aux;
}

int ArrFigure::get_N()
{
    return *n;
}

void ArrFigure::Mover_Objetos(int wventana, int hventana)
{
	for (int i = 0; i < *n; i++) {
		if (arr[i]->getTipo() == 1) {
			((MegaFantasma*)arr[i])->Mover(wventana, hventana);
		}
		if (arr[i]->getTipo() == 2)
		{
			((Fantasma*)arr[i])->Mover(wventana, hventana);
		}
		if (arr[i]->getTipo() == 3)
		{
			((PacDots*)arr[i])->Imprimir();
		}
		if (arr[i]->getTipo() == 4)
		{
			((Bonus*)arr[i])->Imprimir();
		}
	}
}

Figure* ArrFigure::getElemento(int e)
{
	return arr[e];
}

ArrFigure::~ArrFigure()
{
	for (int i = 0; i < *n; i++) {
		delete arr[i];
	}
	delete n, arr;
}
