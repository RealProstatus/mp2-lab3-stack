#pragma once

#include<string>
#include<msclr/marshal_cppstd.h>
#include"../src/Calc.h"
#include"../src/Exception.h"
#include"../src/Calc.cpp"

namespace CppWinForm1 {

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
		}
	private: System::Windows::Forms::TextBox^ tb_expression;
	protected:
	private: System::Windows::Forms::Button^ b_calculate;
	private: System::Windows::Forms::Label^ l_result;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tb_expression = (gcnew System::Windows::Forms::TextBox());
			this->b_calculate = (gcnew System::Windows::Forms::Button());
			this->l_result = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// tb_expression
			// 
			this->tb_expression->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tb_expression->Location = System::Drawing::Point(79, 77);
			this->tb_expression->Name = L"tb_expression";
			this->tb_expression->Size = System::Drawing::Size(249, 29);
			this->tb_expression->TabIndex = 0;
			this->tb_expression->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::tb_keyPress);
			// 
			// b_calculate
			// 
			this->b_calculate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->b_calculate->Location = System::Drawing::Point(335, 77);
			this->b_calculate->Name = L"b_calculate";
			this->b_calculate->Size = System::Drawing::Size(94, 29);
			this->b_calculate->TabIndex = 1;
			this->b_calculate->Text = L"=";
			this->b_calculate->UseVisualStyleBackColor = true;
			this->b_calculate->Click += gcnew System::EventHandler(this, &MyForm::b_calculate_Click);
			// 
			// l_result
			// 
			this->l_result->AutoSize = true;
			this->l_result->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->l_result->Location = System::Drawing::Point(79, 123);
			this->l_result->Name = L"l_result";
			this->l_result->Size = System::Drawing::Size(0, 24);
			this->l_result->TabIndex = 2;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(595, 268);
			this->Controls->Add(this->l_result);
			this->Controls->Add(this->b_calculate);
			this->Controls->Add(this->tb_expression);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void b_calculate_Click(System::Object^ sender, System::EventArgs^ e) {
		std::string inf;
		inf = msclr::interop::marshal_as<std::string>(tb_expression->Text);	//String^ to std::string conv
		Calc calc;
		try {
			l_result->Text = Convert::ToString(calc.calc(inf));
		}
		catch (EWrongExpression exc) {
			exc.show();
			l_result->Text = "Wrong expression!";
		}
		catch (EDivizionByZero exc) {
			exc.show();
			l_result->Text = "Divizion by zero!";
		}
	}
	private: System::Void tb_keyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (e->KeyChar == 13) {
			b_calculate_Click(sender, e);
		}
	}
};
}
