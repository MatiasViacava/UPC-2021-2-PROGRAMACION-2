#pragma once
#include "Controladora.h"
namespace EJERCICIO2PREPC2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			objControladora = new Controladora();
			bmpCaballero = gcnew Bitmap("link.png");
			bmpDragon = gcnew Bitmap("unknown.png"); //direcciones del sprite
			bmpFlecha = gcnew Bitmap("flecha.jpg");
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
			delete objControladora;
			delete bmpCaballero;
			delete bmpDragon;
			delete bmpFlecha;
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		Controladora* objControladora;
		Bitmap^ bmpCaballero;
		Bitmap^ bmpDragon;
		Bitmap^ bmpFlecha;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1345, 645);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = CreateGraphics();
		BufferedGraphicsContext^ space = BufferedGraphicsManager::Current;
		BufferedGraphics^ bf = space->Allocate(g, ClientRectangle);
		bf->Graphics->Clear(Color::White);
		objControladora->Draw_Dragon(bf->Graphics, bmpDragon);
		objControladora->Dibujar_Balas(bf->Graphics, bmpFlecha);
		objControladora->Draw_Nave(bf->Graphics, bmpCaballero);
		bf->Render(g);
		if (objControladora->termino())
		{
			timer1->Enabled = false;
			MessageBox::Show("GANASTE CHIBOLO MONGOL, EL DRAGON SE QUEDO JATO Y  SIN VIDAS _V");
			Close();
		}
		if (objControladora->termino_sinflechas())
		{
			timer1->Enabled = false;
			MessageBox::Show("PERDISTE PAPI, DAME TU CELULAR, PSDT: TE QUEDASTE SIN BALAS");
			Close();
		}
		delete bf, g, space;
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Left)objControladora->Move_Nave(direccion::izquierda);
		if (e->KeyCode == Keys::Right)objControladora->Move_Nave(direccion::derecha);
		if (e->KeyCode == Keys::Space)objControladora->Disparar();
	}
	};
}
