#pragma once
#include "Base.h"
class Dragon :
	public Base
{
private:
	int vidas;
public:
	Dragon();
	Dragon(int px, int py, int ph, int pw);
	void Mover(Graphics^ g);
	void Perder_Vidas();
	int	 get_Vidas();
	~Dragon();
};
