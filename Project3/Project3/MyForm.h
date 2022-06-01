#pragma once



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
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;



	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ButtonShadow;
			this->button1->Font = (gcnew System::Drawing::Font(L"Lato", 9.749999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button1->Location = System::Drawing::Point(12, 152);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(94, 49);
			this->button1->TabIndex = 0;
			this->button1->Text = L"COKOLWIEK";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::ButtonShadow;
			this->button2->Font = (gcnew System::Drawing::Font(L"Lato", 9.749999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button2->Location = System::Drawing::Point(178, 152);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(94, 49);
			this->button2->TabIndex = 1;
			this->button2->Text = L"MOJA GRA";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Lato", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBox1->Location = System::Drawing::Point(12, 95);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(260, 27);
			this->textBox1->TabIndex = 2;
			this->textBox1->Text = L"Uruchom";
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		
		/*System::Diagnostics::Process::Start("D:\\nfs mw\\speed.exe");*/

		OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;
		openFileDialog1->ShowDialog();
		String^ FilePath = openFileDialog1->FileName;
		System::Diagnostics::Process::Start(FilePath);
		
		/*
		if (0 == CreateProcess(argv[2], params, NULL, NULL, false, 0, NULL, NULL, &si, &pi)) {
			//runas word is a hack to require UAC elevation
			ShellExecute(NULL, "runas", argv[2], params, NULL, SW_SHOWNORMAL);
		}*/
		
	}
	
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		System::Diagnostics::Process::Start("D:\\VSTUDIO 2022\\Pongoo\\x64\\Debug\\Pongoo.exe"); 
	}



private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
