#include "Monigote.h"

Monigote::Monigote()
{
}

Monigote::Monigote(int px, int py, int ph, int pw) :Base(px, py, pw, ph, 4, 5,0,0)
{
	fracc_movimiento_X = 4; //NO QUIERE DECIR QUE HAY DESPLAZAMIENTO EN X
	fracc_movimiento_Y = 4; //NO QUIERE DECIR QUE HAY DESPLAZAMIENTO EN Y
	Desplazamiento(direccion::derecha);
}

Monigote::~Monigote()
{
}

void Monigote::Mover(Graphics^ g)
{
	if (x + dx<1 || x + dx + w>g->VisibleClipBounds.Width) dx = 0;
	if (y + dy<1 || y + dy + h>g->VisibleClipBounds.Height)dy = 0;
	x += dx;
	y += dy;
}
