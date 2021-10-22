#include "PacDots.h"

PacDots::PacDots()
{
	x = rand() % 180;
	y = rand() % 45;
	dx = dy = 0;
	w = 1;
	h = 1;
	vidas = 1;
	tipo = 3;

}

void PacDots::Imprimir()
{
	Console::ForegroundColor = ConsoleColor(11);
	Console::SetCursorPosition(x, y); cout << (char)4;
}

PacDots::~PacDots()
{
}
