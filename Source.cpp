#include "CFantasmas.h"
int main()
{
	const int wventana = 180;
	const int hventana = 40;
	Console::SetWindowSize(wventana, hventana);
	Console::CursorVisible = false;
	CFantasmas* obj = new CFantasmas();
	obj->Insertar_4_Fantasmas();
	while (true)
	{
		obj->Mover_Fantasmas(wventana, hventana);
		_sleep(80);
	}
	delete obj;
}