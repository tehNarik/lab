#pragma once
#include "MyException.h"
#include "PhoneNumber.h"
#include <regex>
namespace Project3 {

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
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ numberBox;
		   int counter = 0;
		   array<phoneNumber^>^ numbersArray = gcnew array<phoneNumber^>(3);
	protected:

	private: System::Windows::Forms::Button^ button_add;
	private: System::Windows::Forms::Label^ error_label;


	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button_check;
	private: System::Windows::Forms::Label^ number1;
	private: System::Windows::Forms::Label^ number2;
	private: System::Windows::Forms::Label^ number3;
	private: System::Windows::Forms::Label^ result;
	private: System::Windows::Forms::Button^ button1;







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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->numberBox = (gcnew System::Windows::Forms::TextBox());
			this->button_add = (gcnew System::Windows::Forms::Button());
			this->error_label = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button_check = (gcnew System::Windows::Forms::Button());
			this->number1 = (gcnew System::Windows::Forms::Label());
			this->number2 = (gcnew System::Windows::Forms::Label());
			this->number3 = (gcnew System::Windows::Forms::Label());
			this->result = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(65, 29);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(202, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Введіть номер телефону";
			// 
			// numberBox
			// 
			this->numberBox->Location = System::Drawing::Point(69, 81);
			this->numberBox->Name = L"numberBox";
			this->numberBox->Size = System::Drawing::Size(188, 26);
			this->numberBox->TabIndex = 1;
			// 
			// button_add
			// 
			this->button_add->Location = System::Drawing::Point(383, 70);
			this->button_add->Name = L"button_add";
			this->button_add->Size = System::Drawing::Size(161, 49);
			this->button_add->TabIndex = 2;
			this->button_add->Text = L"Додати номер";
			this->button_add->UseVisualStyleBackColor = true;
			this->button_add->Click += gcnew System::EventHandler(this, &MyForm::button_add_Click);
			// 
			// error_label
			// 
			this->error_label->AutoSize = true;
			this->error_label->Location = System::Drawing::Point(107, 150);
			this->error_label->Name = L"error_label";
			this->error_label->Size = System::Drawing::Size(150, 20);
			this->error_label->TabIndex = 3;
			this->error_label->Text = L"Номер не введено";
			this->error_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(44, 219);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(134, 20);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Введені номери:";
			// 
			// button_check
			// 
			this->button_check->Location = System::Drawing::Point(69, 348);
			this->button_check->Name = L"button_check";
			this->button_check->Size = System::Drawing::Size(188, 59);
			this->button_check->TabIndex = 5;
			this->button_check->Text = L"Перевірити наявність однакових номерів";
			this->button_check->UseVisualStyleBackColor = true;
			this->button_check->Click += gcnew System::EventHandler(this, &MyForm::button_check_Click);
			// 
			// number1
			// 
			this->number1->AutoSize = true;
			this->number1->Location = System::Drawing::Point(231, 235);
			this->number1->Name = L"number1";
			this->number1->Size = System::Drawing::Size(72, 20);
			this->number1->TabIndex = 6;
			this->number1->Text = L"Номер 1";
			// 
			// number2
			// 
			this->number2->AutoSize = true;
			this->number2->Location = System::Drawing::Point(231, 267);
			this->number2->Name = L"number2";
			this->number2->Size = System::Drawing::Size(72, 20);
			this->number2->TabIndex = 7;
			this->number2->Text = L"Номер 2";
			// 
			// number3
			// 
			this->number3->AutoSize = true;
			this->number3->Location = System::Drawing::Point(231, 302);
			this->number3->Name = L"number3";
			this->number3->Size = System::Drawing::Size(72, 20);
			this->number3->TabIndex = 8;
			this->number3->Text = L"Номер 3";
			// 
			// result
			// 
			this->result->AutoSize = true;
			this->result->Location = System::Drawing::Point(85, 428);
			this->result->Name = L"result";
			this->result->Size = System::Drawing::Size(89, 20);
			this->result->TabIndex = 9;
			this->result->Text = L"Результат";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(372, 348);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(195, 59);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Почати заново";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(648, 492);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->result);
			this->Controls->Add(this->number3);
			this->Controls->Add(this->number2);
			this->Controls->Add(this->number1);
			this->Controls->Add(this->button_check);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->error_label);
			this->Controls->Add(this->button_add);
			this->Controls->Add(this->numberBox);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void button_add_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ text = numberBox->Text;
		try {
			String^ res = numberBox->Text; // Припустимо, що введений текст знаходиться в TextBox з ідентифікатором textBox1

			if (res->Length != 13)
				throw gcnew System::Exception("Не може існувати номер з такою кількістю символів. \nВпишіть номер за зразком +380501259253.");
			if (res[0] != '+')
				throw gcnew System::ArgumentException("Впишіть номер використовуючи '+' на початку.");
			if (res[1] != '3' || res[2] != '8' || res[3] != '0')
				throw gcnew MyException("Даний номер не є українським.");
			if (!textValidation(res)) {
				throw gcnew System::FormatException("Номер повинен містити лише + на початку і цифри.");
			}
			error_label->Text = "";
			if (counter == 0) { addNumber1(res); }
			if (counter == 1) { addNumber2(res); }
			if (counter == 2) { addNumber3(res); }
			counter = counter + 1;
			
		}
		catch (System::Exception^ ex) {
			error_label->Text = ex->Message;
		}
		catch (System::ArgumentException^ ex) {
			error_label->Text = ex->Message;
		}
		catch (MyException^ ex) {
			error_label->Text = ex->Message;
		}
		
		}
	private: System::Boolean textValidation(String^ res) {
		for (int i = 1; i < res->Length; i++) {
			if (!Char::IsDigit(res[i])) {
				return false;
			}
		}
		return true;
	}
	private: System::Void addNumber1(String^ res) {
		number1->Text = res;
		numbersArray[0] = gcnew phoneNumber(res);
	}
	private: System::Void addNumber2(String^ res) {
		number2->Text = res;
		numbersArray[1] = gcnew phoneNumber(res);
	}
	private: System::Void addNumber3(String^ res) {
		number3->Text = res;
		numbersArray[2] = gcnew phoneNumber(res);
	}
private: System::Void button_check_Click(System::Object^ sender, System::EventArgs^ e) {
	if (checkAvailability()) {
		result->Text = "Однакові номери присутні.";
	}
	else {
		result->Text = "Однакові номери відсутні.";
	}
}
private: System :: Boolean checkAvailability() {
	for (int i = 0; i < 2; i++) {
		if (numbersArray[0]->getNumber() == numbersArray[i + 1]->getNumber()) {
			return true;
		}
	}
	if (numbersArray[1]->getNumber() == numbersArray[2]->getNumber()) {
		return true;
	}
	return false;
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	Array::Clear(numbersArray, 0, numbersArray->Length);

	// Скинути лічильник
	counter = 0;

	// Очистити текстові поля та мітки
	numberBox->Text = "";
	error_label->Text = "";
	number1->Text = "Номер 1";
	number2->Text = "Номер 2";
	number3->Text = "Номер 3";
	result->Text = "";

	// Відновити форму
	//InitializeComponent();
}
};
}
