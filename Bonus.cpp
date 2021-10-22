#include "Bonus.h"

Bonus::Bonus()
{
	x = rand() % 180;
	y = rand() % 45;
	dx = dy = 0;
	w = 1;
	h = 1;
	vidas = 1;
	tipo = 4;
}

void Bonus::Imprimir()
{
	Console::ForegroundColor=ConsoleColor(9);
	Console::SetCursorPosition(x, y); cout << (char)16;
}

Bonus::~Bonus()
{
}
