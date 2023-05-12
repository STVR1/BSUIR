#pragma once

#include"..\Classes\OPZ.h"
#include"..\Classes\Stack.h"

#include<msclr/marshal_cppstd.h>
#include<regex>

#include"MyDefineForm.h"
#include"MyLibraryForm.h"

namespace GUIOPZ {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class OPZForm : public System::Windows::Forms::Form
	{

	private:

		OPZ* task = nullptr;


		   double* arr = nullptr;

	public:

		void SetArr(double* arr)
		{
			this->arr = arr;
		}

		OPZForm(void)
		{
			InitializeComponent();
		}

	protected:

		~OPZForm()
		{
			if (arr != nullptr)delete[] arr, arr = nullptr;
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ OPZLabel;
	protected:

	private: System::Windows::Forms::Label^ ResultLabel;
	protected:

	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ RealOPZLabel;
	private: System::Windows::Forms::Label^ RealResultLabel;
	private: System::Windows::Forms::Button^ SolveButton;
	private: System::Windows::Forms::Button^ AddButton;
	private: System::Windows::Forms::Button^ LibraryButton;

	private:

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->OPZLabel = (gcnew System::Windows::Forms::Label());
			this->ResultLabel = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->RealOPZLabel = (gcnew System::Windows::Forms::Label());
			this->RealResultLabel = (gcnew System::Windows::Forms::Label());
			this->SolveButton = (gcnew System::Windows::Forms::Button());
			this->AddButton = (gcnew System::Windows::Forms::Button());
			this->LibraryButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// OPZLabel
			// 
			this->OPZLabel->AutoSize = true;
			this->OPZLabel->Location = System::Drawing::Point(12, 83);
			this->OPZLabel->Name = L"OPZLabel";
			this->OPZLabel->Size = System::Drawing::Size(37, 16);
			this->OPZLabel->TabIndex = 0;
			this->OPZLabel->Text = L"OPZ:";
			// 
			// ResultLabel
			// 
			this->ResultLabel->AutoSize = true;
			this->ResultLabel->Location = System::Drawing::Point(12, 130);
			this->ResultLabel->Name = L"ResultLabel";
			this->ResultLabel->Size = System::Drawing::Size(48, 16);
			this->ResultLabel->TabIndex = 1;
			this->ResultLabel->Text = L"Result:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(24, 30);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(146, 22);
			this->textBox1->TabIndex = 2;
			this->textBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &OPZForm::textBox1_MouseClick);
			this->textBox1->Leave += gcnew System::EventHandler(this, &OPZForm::textBox1_Leave);
			// 
			// RealOPZLabel
			// 
			this->RealOPZLabel->AutoSize = true;
			this->RealOPZLabel->Location = System::Drawing::Point(76, 83);
			this->RealOPZLabel->Name = L"RealOPZLabel";
			this->RealOPZLabel->Size = System::Drawing::Size(14, 16);
			this->RealOPZLabel->TabIndex = 3;
			// 
			// RealResultLabel
			// 
			this->RealResultLabel->AutoSize = true;
			this->RealResultLabel->Location = System::Drawing::Point(76, 130);
			this->RealResultLabel->Name = L"RealResultLabel";
			this->RealResultLabel->Size = System::Drawing::Size(14, 16);
			this->RealResultLabel->TabIndex = 4;
			// 
			// SolveButton
			// 
			this->SolveButton->Location = System::Drawing::Point(217, 29);
			this->SolveButton->Name = L"SolveButton";
			this->SolveButton->Size = System::Drawing::Size(75, 23);
			this->SolveButton->TabIndex = 5;
			this->SolveButton->Text = L"Solve";
			this->SolveButton->UseVisualStyleBackColor = true;
			this->SolveButton->Click += gcnew System::EventHandler(this, &OPZForm::SolveButton_Click);
			// 
			// AddButton
			// 
			this->AddButton->Location = System::Drawing::Point(217, 83);
			this->AddButton->Name = L"AddButton";
			this->AddButton->Size = System::Drawing::Size(75, 23);
			this->AddButton->TabIndex = 6;
			this->AddButton->Text = L"Meanings";
			this->AddButton->UseVisualStyleBackColor = true;
			this->AddButton->Click += gcnew System::EventHandler(this, &OPZForm::AddButton_Click);
			// 
			// LibraryButton
			// 
			this->LibraryButton->Location = System::Drawing::Point(234, 228);
			this->LibraryButton->Name = L"LibraryButton";
			this->LibraryButton->Size = System::Drawing::Size(75, 23);
			this->LibraryButton->TabIndex = 7;
			this->LibraryButton->Text = L"Library";
			this->LibraryButton->UseVisualStyleBackColor = true;
			this->LibraryButton->Click += gcnew System::EventHandler(this, &OPZForm::LibraryButton_Click);
			// 
			// OPZForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(321, 263);
			this->Controls->Add(this->LibraryButton);
			this->Controls->Add(this->AddButton);
			this->Controls->Add(this->SolveButton);
			this->Controls->Add(this->RealResultLabel);
			this->Controls->Add(this->RealOPZLabel);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->ResultLabel);
			this->Controls->Add(this->OPZLabel);
			this->Name = L"OPZForm";
			this->Text = L"OPZForm";
			this->Load += gcnew System::EventHandler(this, &OPZForm::OPZForm_Load);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &OPZForm::OPZForm_MouseClick);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		  // Done

	private: bool CheckInput()
		{
			std::string input = msclr::interop::marshal_as<std::string>(this->textBox1->Text);
			bool correct = true;
			bool sign = false;
			bool bracket = false;
			bool symbol = false;
			char prev = 'a' - 1;
			MyStack brackets;
			if (input.size() == 1)return false;
			for (int i = 0; i < input.size(); i++)
			{
				if (input[i] >= 'a' && input[i] <= 'z')
				{
					if (bracket == true && symbol == false && sign == false)symbol = true, bracket = false;
					else if (bracket == false && symbol == false && sign == false)symbol = true;
					else if (bracket == false && symbol == false && sign == true)symbol = true, sign = false;
					else if (bracket == true && symbol == true && sign == false)bracket = false;
					else if (sign == true && bracket == false && symbol == true)symbol = false, sign = false;
					else return false;
					if (prev + 1 != input[i])return false;
					prev = input[i];

				}
				else if (input[i] == '(')
				{
					if (sign == true)sign = false;
					brackets.push_back(')');
					bracket = true;
				}
				else if (input[i] == ')')
				{
					bracket = false;
					if (brackets.top() != nullptr)
					{
						if (brackets.top()->info == ')')
							if (brackets.top() != nullptr)brackets.pop_back();
					}
					else return false;
				}
				else if (input[i] == '+' || input[i] == '*' || input[i] == '/' || input[i] == '-')
				{
					if ((symbol == true || bracket == false) && sign == false)sign = true;
					else return false;
				}
				else return false;
			}
			if (bracket == true || sign == true)correct = false;
			if (brackets.top() != nullptr)correct = false;
			while (brackets.top() != nullptr)brackets.pop_back();
			return correct;
		}

		   // Done

	private: System::Void textBox1_Leave(System::Object^ sender, System::EventArgs^ e) {

		if (this->textBox1->Text == "")
		{
			this->textBox1->ForeColor = Color::Gray;
			this->textBox1->Text = "Input";
			this->textBox1->ReadOnly = true;
		}

	}

		   // Done

	private: System::Void textBox1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

		if (this->textBox1->ForeColor == Color::Gray)
		{
			this->textBox1->Text = "";
			this->textBox1->ForeColor = Color::Black;
			this->textBox1->ReadOnly = false;
		}

	}

		   // Done

	private: System::Void OPZForm_Load(System::Object^ sender, System::EventArgs^ e) {
		this->textBox1->Text = "Input";
		this->textBox1->ForeColor = Color::Gray;
		this->textBox1->ReadOnly = true;
	}

		   // Done

	private: System::Void OPZForm_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

		if (this->textBox1->Text == "")
		{
			this->textBox1->Text = "Input";
			this->textBox1->ForeColor = Color::Gray;
			this->textBox1->ReadOnly = true;
		}

	}

		   // Done

	private: System::Void AddButton_Click(System::Object^ sender, System::EventArgs^ e) {

		std::string input = msclr::interop::marshal_as<std::string>(this->textBox1->Text->ToString());
		int counter = 0;

		if (this->textBox1->Text == "" || CheckInput() == false)
		{
			MessageBox::Show(this, "Incorrect expression", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		if (arr != nullptr)
			if (MessageBox::Show(this, "Are you sure? Your previous meanings will be deleted", "Warning", MessageBoxButtons::OKCancel, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::OK)
				delete[] arr, arr = nullptr; else return;

		MyDefineForm newform;
		
		for (int i = 0; i < input.size(); i++)
			if (input[i] >= 'a' && input[i] <= 'z')counter++;

		newform.SetSize(counter);

		newform.FormBorderStyle= System::Windows::Forms::FormBorderStyle::FixedSingle;
		newform.MaximizeBox = false;

		newform.ShowDialog();

		arr = newform.GetArr();

	}

		   // Done

	private: System::Void SolveButton_Click(System::Object^ sender, System::EventArgs^ e) {

		std::string input = msclr::interop::marshal_as<std::string>(this->textBox1->Text->ToString());
		char* opz = new char[input.size()+1];
		strcpy(opz, input.c_str());
		double result = 0;

		if (this->textBox1->Text == "" || CheckInput() == false)
		{
			MessageBox::Show(this, "Incorrect expression", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		if (arr == nullptr)
		{
			MessageBox::Show(this, "Undefined meanings", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		task = new OPZ(opz, arr);

		input = std::string(task->GetOPZ());

		this->RealOPZLabel->Text = msclr::interop::marshal_as<String^>(input);

		result=task->Calculate();

		this->RealResultLabel->Text = Convert::ToString(result);

		MessageBox::Show(this, "Successfully solved", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

		delete[] opz;
		delete task, task = nullptr;

	}

		   // Done

	private: System::Void LibraryButton_Click(System::Object^ sender, System::EventArgs^ e) {

		MyLibraryForm newform;

		newform.FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
		newform.MaximizeBox = false;

		newform.ShowDialog();

		this->textBox1->Text=newform.GetStr();

		std::string input = msclr::interop::marshal_as<std::string>(newform.GetValues());

		if (arr != nullptr)delete[] arr, arr=nullptr;

		if(input!="")arr = new double[5];

		int start = 0;
		int index = 0;

		for (int i =start= 0; i < input.size(); i++)
		{
			if (input[i] == ' ' || i == input.size() - 1)
			{
				if(i!=input.size()-1)arr[index] = stod(input.substr(start, i - start));
				else arr[index] = stod(input.substr(start, i+1 - start));
				start = i + 1;
				index++;
			}
		}

	}

};
}