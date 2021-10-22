#pragma once
#include "ArrFigure.h"
#include "Pacman.h"
using namespace System::Drawing;

class Controladora
{
private:
	ArrFigure* objA;
	Pacman* objP;
	time_t tiempo_inicio = time(0);
	time_t tiempo_inici2 = time(0);
	time_t tiempo_inici3 = time(0);
	time_t tiempo_bonus_inmune = time(0);
	bool inmune;
	int can_fantasma;
	int can_megafantasma;
	int contador_pacdot;

public:
	Controladora();
	void MoverTodo(int wventana, int hventana);
	void Insrtar_Fantasmas();
	void Insrtar_pacbonus();
	void Colision();
	void Imprimir_Pacman();
	bool termino_juego();
	void Eliminar_Figuras();
	bool tiene_vidas();
	void inmune_5_segundos();
	void Reporte();
	void Mover_Persona(char tecla, int wventana, int hventana);
	~Controladora();

};

