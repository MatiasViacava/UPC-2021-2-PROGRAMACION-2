#pragma once
#include "Base.h"
class Monigote : public Base
{
public:
	Monigote();
	Monigote(int px, int py, int ph, int pw);
	~Monigote();
	void Mover(Graphics^ g);
};

