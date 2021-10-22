#pragma once
#include "Bonus.h"
#include "Fantasma.h"
#include "MegaFantasma.h"
#include "PacDots.h"
class ArrFigure
{
private:
	Figure** arr;
	int* n;
public:
	ArrFigure();
	void Insertar_Fantasma();
	void Insertar_MegaFantasma();
	void Insertar_PacDots();
	void Insertar_Bonus();
	void Eliminar();
	int get_N();
	void Mover_Objetos(int wventana, int hventana);
	Figure* getElemento(int e);
	~ArrFigure();
};

