#include "MegaFantasma.h"

MegaFantasma::MegaFantasma()
{
	x = 15;
	y = rand() % 45;
	dx = 3;
	w = 5;
	h = 4;
	vidas = 1;
	tipo = 1;

}

void MegaFantasma::Imprimir()
{
	Console::ForegroundColor=ConsoleColor(5);
	Console::SetCursorPosition(x, y);     cout << " ___ ";
	Console::SetCursorPosition(x, y+1);   cout << "/o o\\";
	Console::SetCursorPosition(x, y + 2); cout << "|   |";
	Console::SetCursorPosition(x, y + 3); cout << "|,,,|";

}

void MegaFantasma::Mover(int wventana, int hventana)
{
	Borrar();
	if (x + dx < 1 || x + w + dx >= wventana) dx *= -1;
	x = x + dx;
	
	Imprimir();
}
MegaFantasma::~MegaFantasma()
{
}
