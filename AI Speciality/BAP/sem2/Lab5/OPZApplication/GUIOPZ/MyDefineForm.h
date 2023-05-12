#pragma once

#include"OPZForm.h"
#include<regex>

namespace GUIOPZ {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class MyDefineForm : public System::Windows::Forms::Form
	{

	private:

		int size = 0;
		double* arr = nullptr;

	public:

		void SetSize(int size)
		{
			this->size = size;
		}

		double* GetArr()
		{
			return this->arr;
		}

		MyDefineForm(void)
		{
			InitializeComponent();
		}

	protected:

		~MyDefineForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ OPZDataGridView;
	private: System::Windows::Forms::Button^ MyDefineButton;
	protected:

	private:

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->OPZDataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->MyDefineButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->OPZDataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// OPZDataGridView
			// 
			this->OPZDataGridView->AllowUserToAddRows = false;
			this->OPZDataGridView->AllowUserToDeleteRows = false;
			this->OPZDataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->OPZDataGridView->Location = System::Drawing::Point(82, 23);
			this->OPZDataGridView->Name = L"OPZDataGridView";
			this->OPZDataGridView->RowHeadersWidth = 51;
			this->OPZDataGridView->RowTemplate->Height = 24;
			this->OPZDataGridView->Size = System::Drawing::Size(119, 329);
			this->OPZDataGridView->TabIndex = 0;
			// 
			// MyDefineButton
			// 
			this->MyDefineButton->Location = System::Drawing::Point(105, 372);
			this->MyDefineButton->Name = L"MyDefineButton";
			this->MyDefineButton->Size = System::Drawing::Size(75, 35);
			this->MyDefineButton->TabIndex = 1;
			this->MyDefineButton->Text = L"Accept";
			this->MyDefineButton->UseVisualStyleBackColor = true;
			this->MyDefineButton->Click += gcnew System::EventHandler(this, &MyDefineForm::MyDefineButton_Click);
			// 
			// MyDefineForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(315, 407);
			this->Controls->Add(this->MyDefineButton);
			this->Controls->Add(this->OPZDataGridView);
			this->Name = L"MyDefineForm";
			this->Text = L"MyDefineForm";
			this->Load += gcnew System::EventHandler(this, &MyDefineForm::MyDefineForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->OPZDataGridView))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

		// Done

	private: System::Void MyDefineForm_Load(System::Object^ sender, System::EventArgs^ e) {

		char c = 'a';
		this->OPZDataGridView->Size = System::Drawing::Size(53, 35*size);
		this->OPZDataGridView->ColumnCount = 2;
		this->OPZDataGridView->RowCount = size;
		this->OPZDataGridView->Columns[0]->Width = 25;
		this->OPZDataGridView->Columns[1]->Width = 25;
		
		this->OPZDataGridView->RowHeadersVisible = false;
		this->OPZDataGridView->ColumnHeadersVisible = false;
		this->OPZDataGridView->AllowUserToResizeColumns = false;
		this->OPZDataGridView->AllowUserToResizeRows = false;

		for (int i = 0; i < size; i++)
		{
			this->OPZDataGridView->Rows[i]->Cells[0]->Value = Convert::ToChar(c++);
			this->OPZDataGridView->Rows[i]->Cells[0]->ReadOnly = true;
			this->OPZDataGridView->Rows[i]->Height = 33;
		}

	}

		// Done

	private: System::Void MyDefineButton_Click(System::Object^ sender, System::EventArgs^ e) {

		std::regex num("^([0-9]+[.]{1}[0-9]+)|([0-9]+)$");
		
		arr = new double[size];

		for (int i = 0; i < size; i++)
		{
			if (!std::regex_match(msclr::interop::marshal_as<std::string>(this->OPZDataGridView->Rows[i]->Cells[1]->Value->ToString()), num))
			{
				delete[] arr, arr=nullptr;
				MessageBox::Show(this, "Incorrect line"+Convert::ToString(i+1), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			else
			{
				arr[i] = Convert::ToDouble(this->OPZDataGridView->Rows[i]->Cells[1]->Value->ToString());
			}
		}

		MessageBox::Show(this, "Successfully defined", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

		Close();

	}
};
}