#pragma once

#include"OPZForm.h"

namespace GUIOPZ {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyLibraryForm : public System::Windows::Forms::Form
	{
	private:

		String^ opz="", ^ values="";

	public:

		String^ GetStr()
		{
			return opz;
		}

		String^ GetValues()
		{
			return values;
		}

		MyLibraryForm(void)
		{
			InitializeComponent();
		}

	protected:

		~MyLibraryForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::CheckedListBox^ CheckedListBox;
	private: System::Windows::Forms::CheckedListBox^ ValueCheckedListBox;
	protected:

	private: System::Windows::Forms::Button^ MyLibraryButton;


	private:

		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->CheckedListBox = (gcnew System::Windows::Forms::CheckedListBox());
			this->ValueCheckedListBox = (gcnew System::Windows::Forms::CheckedListBox());
			this->MyLibraryButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// CheckedListBox
			// 
			this->CheckedListBox->FormattingEnabled = true;
			this->CheckedListBox->Location = System::Drawing::Point(6, 12);
			this->CheckedListBox->Name = L"CheckedListBox";
			this->CheckedListBox->Size = System::Drawing::Size(169, 293);
			this->CheckedListBox->TabIndex = 0;
			// 
			// ValueCheckedListBox
			// 
			this->ValueCheckedListBox->FormattingEnabled = true;
			this->ValueCheckedListBox->Location = System::Drawing::Point(203, 12);
			this->ValueCheckedListBox->Name = L"ValueCheckedListBox";
			this->ValueCheckedListBox->Size = System::Drawing::Size(176, 293);
			this->ValueCheckedListBox->TabIndex = 1;
			// 
			// MyLibraryButton
			// 
			this->MyLibraryButton->Location = System::Drawing::Point(137, 333);
			this->MyLibraryButton->Name = L"MyLibraryButton";
			this->MyLibraryButton->Size = System::Drawing::Size(75, 23);
			this->MyLibraryButton->TabIndex = 2;
			this->MyLibraryButton->Text = L"Accept";
			this->MyLibraryButton->UseVisualStyleBackColor = true;
			this->MyLibraryButton->Click += gcnew System::EventHandler(this, &MyLibraryForm::MyLibraryButton_Click);
			// 
			// MyLibraryForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(391, 402);
			this->Controls->Add(this->MyLibraryButton);
			this->Controls->Add(this->ValueCheckedListBox);
			this->Controls->Add(this->CheckedListBox);
			this->Name = L"MyLibraryForm";
			this->Text = L"MyLibraryForm";
			this->Load += gcnew System::EventHandler(this, &MyLibraryForm::MyLibraryForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void MyLibraryForm_Load(System::Object^ sender, System::EventArgs^ e) {

		this->CheckedListBox->Items->Add("a/(b-c)*(d+e)");
		this->CheckedListBox->Items->Add("(a+b)*(c-d)/e");
		this->CheckedListBox->Items->Add("a-(b+c*d)/e");
		this->CheckedListBox->Items->Add("a/b-((c+d)*e)");
		this->CheckedListBox->Items->Add("a*(b-c+d)/e");
		this->CheckedListBox->Items->Add("(a+b)*(c-d)/e");
		this->CheckedListBox->Items->Add("a*(b-c)/(d+e)");
		this->CheckedListBox->Items->Add("a/(b*(c+d))-e");
		this->CheckedListBox->Items->Add("(a+(b/c-d))*e");
		this->CheckedListBox->Items->Add("a*(b+c)/(d-e)");
		this->CheckedListBox->Items->Add("a-(b/c*(d+e))");
		this->CheckedListBox->Items->Add("(a-b)/(c+d)*e");
		this->CheckedListBox->Items->Add("a/(b+c-d*e)");
		this->CheckedListBox->Items->Add("a*(b-c)/(d+e)");
		this->CheckedListBox->Items->Add("(a+b*c)/(d-e)");

		this->ValueCheckedListBox->Items->Add("8.6 2.4 5.1 0.3 7.9");
		this->ValueCheckedListBox->Items->Add("7.4 3.6 2.8 9.5 0.9");
		this->ValueCheckedListBox->Items->Add("3.1 5.4 0.2 9.5 7.8");
		this->ValueCheckedListBox->Items->Add("1.2 0.7 9.3 6.5 8.4");
		this->ValueCheckedListBox->Items->Add("9.7 8.2 3.6 4.1 0.5");
		this->ValueCheckedListBox->Items->Add("0.8 4.1 7.9 6.2 3.5");
		this->ValueCheckedListBox->Items->Add("1.6 4.9 5.7 0.8 2.3");
		this->ValueCheckedListBox->Items->Add("8.5 0.3 2.4 7.9 1.6");
		this->ValueCheckedListBox->Items->Add("5.6 7.4 8.9 3.1 0.2");
		this->ValueCheckedListBox->Items->Add("0.4 2.3 6.7 5.8 9.1");
		this->ValueCheckedListBox->Items->Add("5.6 3.2 0.9 1.7 4.8");
		this->ValueCheckedListBox->Items->Add("0.3 6.7 8.4 9.5 1.2");
		this->ValueCheckedListBox->Items->Add("7.6 4.8 3.5 9.1 0.2");
		this->ValueCheckedListBox->Items->Add("0.5 6.1 8.9 2.4 7.3");
		this->ValueCheckedListBox->Items->Add("9.1 0.6 2.4 3.7 8.5");
		
	}

		   // Done

	private: System::Void MyLibraryButton_Click(System::Object^ sender, System::EventArgs^ e) {

		if (this->CheckedListBox->SelectedItem == nullptr || this->CheckedListBox->SelectedIndices->Count > 1)
		{
			MessageBox::Show(this, "Incorrect choice", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		if (this->ValueCheckedListBox->SelectedItem == nullptr || this->ValueCheckedListBox->SelectedIndices->Count > 1)
		{
			MessageBox::Show(this, "Incorrect choice", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		opz = this->CheckedListBox->SelectedItem->ToString();

		values = this->ValueCheckedListBox->SelectedItem->ToString();

		MessageBox::Show(this, "Successfully chosen", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

		Close();

	}

};
}