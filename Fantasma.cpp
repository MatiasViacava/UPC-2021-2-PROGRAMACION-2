#include "Fantasma.h"

Fantasma::Fantasma()
{
	x = rand() % 180;
	y = rand() % 46;
	dx = dy = 2;
	w = 5;
	h = 4;
	vidas = 1;
	tipo = 2;
}

void Fantasma::Imprimir()
{
	Console::ForegroundColor=ConsoleColor(4);
	Console::SetCursorPosition(x, y);     cout << " ___ ";
	Console::SetCursorPosition(x, y + 1); cout << "/o o\\";
	Console::SetCursorPosition(x, y + 2); cout << "|   |";
	Console::SetCursorPosition(x, y + 3); cout << "|,,,|";

}

void Fantasma::Mover(int wventana, int hventana)
{
	Borrar();
	if (x + dx <= 1 || x + w + dx >= wventana) dx *= -1;
	if (y + dy <= 1 || y + h + dy >= hventana) dy *= -1;
	x = x + dx;
	y = y + dy;
	Imprimir();
}

Fantasma::~Fantasma()
{
}
