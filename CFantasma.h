#pragma once
#include <iostream>
#include <conio.h>

public enum color_fantasma { verde, azul, rojo, marron };
using namespace std;
using namespace System;
class CFantasma
{
private:
	int x, y, dx, dy, w, h;
	color_fantasma color;
public:
	CFantasma();
	~CFantasma();
	void Imprimir();
	void Mover(int wventana, int hventana);
	void Borrar();
	int getX();
	int getY();
	int getW();
	int getH();

};

