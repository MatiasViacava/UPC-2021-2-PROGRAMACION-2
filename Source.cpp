#include "Controladora.h"
int main()
{
	srand(time(NULL));
	const int wventana = 190;
	const int hventana = 49;
	Console::SetWindowSize(wventana, hventana);
	Console::CursorVisible = false;
	Controladora* obj = new Controladora();
	
	obj->Insrtar_pacbonus();
	while (obj->tiene_vidas()==true)
	{
		obj->Imprimir_Pacman();
		if (_kbhit())
		{
			char t;
			t = getch();
			obj->Mover_Persona(toupper(t), wventana, hventana);
			flushall();
		}
		obj->MoverTodo(wventana, hventana);
		obj->Insrtar_Fantasmas();
		_sleep(50);
	}
	Console::Clear();
	obj->Reporte();
	system("pause");
	return 0;
	delete obj;
}