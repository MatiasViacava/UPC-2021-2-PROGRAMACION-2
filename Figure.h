#pragma once
#include <iostream>
#include <conio.h>

using namespace std;
using namespace System;
class Figure
{
protected:
	int x, y, dx, dy, w, h;
	int vidas;
	int tipo;
public:
	Figure();
	void Borrar();
	void PerderVida();
	int getX();
	int getDX();
	int getDY();
	int getY();
	int getH();
	int getW();
	void set_X(int nuevo);
	void set_y(int nuevo);
	void set_dx(int nuevo_dx);
	void set_dy(int nuevo_dy);
	int getVidas();
	int getTipo();
	~Figure();
};

