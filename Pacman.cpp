#include "Pacman.h"

Pacman::Pacman()
{
	x = 10;
	y = 6;
	dx = dy = 0;
	vidas = 3;
	w = 5;
	h = 4;
	speed=1;
	tipo = 5;
}

void Pacman::Mover(int wventana, int hventana)
{
	Borrar();
	if (x + dx < 1 || x + w + dx >= wventana) dx = 0;
	if (y + dy < 1 || y + h + dy >= hventana) dy = 0;
	x = x + dx;
	y = y + dy;
	Imprimir();
}

void Pacman::Imprimir()
{
	Console::ForegroundColor = ConsoleColor(14);
	Console::SetCursorPosition(x, y);			cout << "  __ ";
	Console::SetCursorPosition(x, y + 1);		cout << " / o\\";
	Console::SetCursorPosition(x, y + 2);		cout << "|   <";
	Console::SetCursorPosition(x, y + 3);		cout << " \\__/";
	
}

void Pacman::Desplazamiento(direccion nuevo)
{
	dx = dy = 0;
	orientacion = nuevo;
	if (orientacion == izquierda) dx = -1* speed;
	if (orientacion == derecha) dx = 1* speed;
	if (orientacion == arriba) dy = -1* speed;
	if (orientacion == abajo) dy = 1* speed;
}

int Pacman::get_speed()
{
	return speed;
}

void Pacman::set_speed(int nuevo)
{
	speed = nuevo;
}

Pacman::~Pacman()
{
}
