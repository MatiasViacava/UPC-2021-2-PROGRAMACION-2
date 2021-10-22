#include "Playa.h"

Playa::Playa()
{

}
Playa::Playa(int px, int py, int ph, int pw) :Base(px, py, ph, pw, 4, 10, 1, 0)
{
	dy = (gcnew System::Random())->Next(10,30);
}
Playa::~Playa()
{
}

void Playa::Mover(Graphics^ g)
{
	if (y + dy<1 || y + dy + h>g->VisibleClipBounds.Height)
	{
		dy *= -1;
	}
	y += dy;
}
