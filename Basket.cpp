#include "Basket.h"

Basket::Basket()
{
}
Basket::Basket(int px, int py, int ph, int pw) :Base(px, py, ph, pw, 4, 10, 3, 0)
{
	dx = dy = 1;
}
Basket::~Basket()
{
}