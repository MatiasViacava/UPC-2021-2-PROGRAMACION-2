#pragma once
#include "Base.h"
class Flechas :
	public Base
{
private:
	int vidas;
public:
	Flechas();
	Flechas(int px, int py, int ph, int pw);
	void Mover(Graphics^ g);
	~Flechas();
};

