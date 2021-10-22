#include "Futbol.h"

Futbol::Futbol()
{
}
Futbol::Futbol(int px, int py, int ph, int pw) :Base(px, py, ph, pw, 4, 10, 2, 0)
{
	dx = dy = 1;
}
Futbol::~Futbol()
{
}
