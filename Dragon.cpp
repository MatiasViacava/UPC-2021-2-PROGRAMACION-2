#include "Dragon.h"

Dragon::Dragon()
{
}

Dragon::Dragon(int px, int py, int ph, int pw) : Base(px, py, pw, ph, 4, 3, 0, 0)
{
	System::Random^ r = gcnew System::Random();
	vidas = 3;
	dx = r->Next(4, 15);
	dy = 0;
	delete r;
}

void Dragon::Mover(Graphics^ g)
{
	if (x + dx<1 || x + dx + w>g->VisibleClipBounds.Width)
	{
		dx *= -1;
	}
	x += dx;
	System::Random^ r = gcnew System::Random();
	if (dx>0)
	{
		dx= r->Next(5, 20);
		fil = 1;
	}
	else if (dx<0)
	{
		dx = -1 * (r->Next(5, 20));
		fil = 3;
	}
	
}

void Dragon::Perder_Vidas()
{
	vidas--;
}

int Dragon::get_Vidas()
{
	return vidas;
}

Dragon::~Dragon()
{
}
