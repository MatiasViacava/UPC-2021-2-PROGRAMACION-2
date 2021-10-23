#include "CFantasma.h"

CFantasma::CFantasma()
{
	this->x = rand() % 50;
	this->y = rand() % 40;
	this->w = 6;
	this->h = 4;
	this->dx = dy = 1;


}

CFantasma::~CFantasma()
{
}

void CFantasma::Imprimir()
{
	Console::SetCursorPosition(x, y);
	cout << " ___ ";
	Console::SetCursorPosition(x, y + 1);
	cout << "/o o\\";
	Console::SetCursorPosition(x, y + 2);
	cout << "|   |";
	Console::SetCursorPosition(x, y + 3);
	cout << "|,,,|";
}

void CFantasma::Mover(int wventana, int hventana)
{
	Borrar();
	if (x + dx < 1 || x + dx + w > wventana) dx *= -1;
	if (y + dy < 1 || y + dy + h > hventana) dy *= -1;
	x = x + dx;
	y = y + dy;
	Imprimir();

}

void CFantasma::Borrar()
{
	for (int i = y; i < y + h; i++)
	{
		for (int j = x; j < x + w; j++)
		{
			Console::SetCursorPosition(j, i);
			cout << " ";
		}
	}
}
