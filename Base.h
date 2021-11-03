#pragma once
using namespace System::Drawing;
public enum direccion { arriba, abajo, izquierda, derecha, ninguno };
class Base
{
protected:
	int x, y, w, h, dx, dy;
	bool eliminar;
	direccion orientacion;
	int max_fila, max_columna; //animacion de sprites
	int col, fil;
	int fracc_movimiento_X;
	int fracc_movimiento_Y;
public:
	Base();
	Base(int px, int py, int pw, int ph);
	Base(int px, int py, int pw, int ph, int pxmaxfil, int pmaxCol, int pfila, int pcol);
	~Base();
	void set_X(int nuevo);
	void set_Y(int nuevo);
	void set_W(int nuevo);
	void set_H(int nuevo);
	void set_DX(int nuevo);
	void set_DY(int nuevo);
	void set_maxfila(int nuevo);
	void set_maxColumna(int nuevo);
	void set_fracc_movimiento_X(int nuevo);
	void set_fracc_movimiento_Y(int nuevo);
	void set_eliminar(bool nuevo);
	void Desplazamiento(direccion nuevo);
	int get_X();
	int get_Y();
	int get_DX();
	int get_DY();
	int get_W();
	int get_H();
	int get_maxfila();
	int get_maxColumna();
	int get_fracc_movimiento_X();
	int get_fracc_movimiento_Y();
	bool get_eliminar();
	Rectangle get_Rectangle();
	virtual void Mover(Graphics^ g);
	void Dibujar(Graphics^ g);
	void Dibujar_Imagen_ball(Graphics^ g, Bitmap^ bmp);
	void Borrar(Graphics^ g);
};