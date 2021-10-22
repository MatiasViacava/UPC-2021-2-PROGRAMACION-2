#pragma once
#include "Controladora.h"
namespace Project4 {

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
			objcontroladora = new Controladora();
			bmpPelota = gcnew Bitmap("ball.png");
			bmpMonigote = gcnew Bitmap("oorjG.png");
			//
			//TODO: Add the constructor code here
			//

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
			delete objcontroladora;
			delete bmpPelota;
			delete bmpMonigote;
		}
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

		Controladora* objcontroladora;
	private: System::Windows::Forms::Timer^ timer1;
		   Bitmap^ bmpPelota;
		   Bitmap^ bmpMonigote;

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
			this->ClientSize = System::Drawing::Size(1431, 681);
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
		objcontroladora->Draw_All(bf->Graphics, bmpPelota);
		objcontroladora->Draw_Monigote(bf->Graphics, bmpMonigote);
		bf->Render(g);
		delete bf, g, space;
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Left)objcontroladora->Move_Monigote(direccion::izquierda);
		if (e->KeyCode == Keys::Right)objcontroladora->Move_Monigote(direccion::derecha);
		if (e->KeyCode == Keys::Up)objcontroladora->Move_Monigote(direccion::arriba);
		if (e->KeyCode == Keys::Down)objcontroladora->Move_Monigote(direccion::abajo);
	}
	};
}
