#include "Flechas.h"

Flechas::Flechas()
{
}

Flechas::Flechas(int px, int py, int ph, int pw) :Base(px, py, pw, ph, 1, 1, 0, 0)
{
	System::Random^ r = gcnew System::Random();
	dx = 0;
	dy = -(r->Next(5, 12));
}

void Flechas::Mover(Graphics^ g)
{
	if (y + dy < 1)
	{
		dy = 0;
		eliminar = true;
	}
	y = y + dy;
}

Flechas::~Flechas()
{
}