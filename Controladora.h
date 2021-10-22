#pragma once
#include <vector>
#include "Playa.h"
#include "Futbol.h"
#include "Basket.h"
#include "Bowling.h"
#include "Monigote.h"
using namespace std;
class Controladora
{
private:
	vector<Base*>arr;
	Monigote* objM;
public:
	Controladora();
	void Draw_All(Graphics^ g, Bitmap^ bmp);
	void Draw_Monigote(Graphics^ g, Bitmap^ bmp);
	void Move_Monigote(direccion nuevo);
	bool Colision();
	~Controladora();
};

