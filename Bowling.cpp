#include "Bowling.h"

Bowling::Bowling()
{
	
}
Bowling::Bowling(int px, int py, int ph, int pw) :Base(px, py, ph, pw, 4, 10, 0, 0)
{
	dx = (gcnew System::Random())->Next(10, 20);
}
Bowling::~Bowling()
{
}

void Bowling::Mover(Graphics^ g)
{
	if (x+dx<1||x+dx+w>g->VisibleClipBounds.Width)
	{
		dx *= -1;
	}
	x += dx;
}
