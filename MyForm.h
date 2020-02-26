#pragma once
#include <ctype.h>
namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Collections::Generic;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		List<String^>^ TID;
		List<String^>^ TNUM;
		List<String^>^ LexName;
		List<int>^ Id;
		List<String^>^ TKey;
		List<char>^ TD;

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
	private: System::Windows::Forms::TextBox^ tbInput;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;

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
			this->tbInput = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// tbInput
			// 
			this->tbInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbInput->Location = System::Drawing::Point(12, 7);
			this->tbInput->Multiline = true;
			this->tbInput->Name = L"tbInput";
			this->tbInput->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->tbInput->Size = System::Drawing::Size(574, 313);
			this->tbInput->TabIndex = 0;
			this->tbInput->WordWrap = false;
			this->tbInput->TextChanged += gcnew System::EventHandler(this, &MyForm::TbInput_TextChanged);
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(12, 590);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(574, 68);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Compile";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::Button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 326);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox1->Size = System::Drawing::Size(142, 258);
			this->textBox1->TabIndex = 2;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(160, 564);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(426, 20);
			this->textBox2->TabIndex = 3;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(160, 326);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->ReadOnly = true;
			this->textBox3->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox3->Size = System::Drawing::Size(426, 232);
			this->textBox3->TabIndex = 4;
			this->textBox3->WordWrap = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Orange;
			this->ClientSize = System::Drawing::Size(598, 670);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->tbInput);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"TYaP";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
String^ MovAxID(int variable_id) {
	String^ command = "mov ax, [bp-" + 2 * (variable_id + 1) + "]\r\n";
	return command;
}
String^ MovAxNUM(int num) {
	String^ command = "mov byte[bp-" + 2 * (TID->Count + 1) + "], " + num + "\r\n";
	command += "mov ax, [bp-" + 2 * (TID->Count + 1) + "]\r\n";
	return command;
}
String^ OperAxIDNUM(char op, int variable, bool ID_NUM) {
	String^ oper = "";
	String^ command = "";
	switch (op)
	{
	case '+':
		oper = "add";
		break;
	case '-':
		oper = "sub";
		break;
	case '*':
		oper = "imul";
		break;
	case '/':
		if (ID_NUM)	command = "mov ax, [bp-" + 2 * (variable + 1) + "]\r\n";
		else command = "mov ax, " + (variable)+"\r\n";
		command += "idiv dl \r\n";
		return command;
		///////////////
		break;
	default:
		break;
	}
	if (ID_NUM)	command = oper + " ax, [bp-" + 2 * (variable + 1) + "]\r\n";
	else command = oper + " ax, " + (variable) + "\r\n";

	return command;
}
String^ MovIDAx(int variable_id, bool AX_ONLY) {
	String^ command = "";
	command += "mov [bp-" + 2 * (TID->Count + 1) + "], ax\r\n";
	command += "mov ax, [bp-" + 2 * (TID->Count + 1) + "]\r\n";
	if (!AX_ONLY)command += "mov [bp-" + 2 * (variable_id + 1) + "], ax\r\n";
	return command;
}
String^ OperMetka(char op, int metka, bool single) {
	String^ oper = "";
	String^ command = "";
	if (!single) {
		switch (op)
		{
		case '>':
			//oper = "jg";
			oper = "jle";
			break;
		case '<':
			//oper = "jl";
			oper = "jge";
			break;
		case ':':
			//oper = "jz";
			oper = "jnz";
			break;
		case '!':
			//oper = "jnz";
			oper = "jz";
			break;
		default:
			break;
		}
		command += "cmp [bp-" + 2 * (TID->Count + 2) + "], ax\r\n";
		command += oper + " metka" + metka + "\r\n";
	}
	else {
		//command += "cmp [bp-" + 2 * (TID->Count + 2) + "], 0\r\n";
		command += "cmp ax, 0\r\n";
		command += "jz metka" + metka + "\r\n";
	}
	//////////////////

	return command;
}
String^ PrintAx() {
	String^ command = "";
	command += "mov di, s_sword\r\n";
	command += "call cx\r\n";
	command += "call print_word_sdec\r\n";
	command += "call bx\r\n";
	return command;
}

String^ Asm() {
	List<int>^ LastKey = gcnew List<int>(0);
	List<int>^ Metki = gcnew List<int>(0);
	List<int>^ WhileMetki = gcnew List<int>(0);
	int variable = 0;
	int last_oper = 0;
	int last_srav_oper = 0;
	int closed_sf = 0;
	int while_closed_sf = 0;
	String^ AssemblerCode = "";
	enum state { H, MATH, IF, WHILE, MATHKEY, PRINT };
	enum state TC; /* текущее состояние */
	LastKey->Add(0);
	TC = H;
	for (int i = 0; i < LexName->Count; i++) {
		switch (TC)
		{
		case H:
			if (LexName[i] == "id") {
				variable = Id[i];
				TC = MATH;
			}
			else if (LexName[i] == "key" && TKey[Id[i]] == "if") {
				LastKey->Add(2);
				TC = IF;
			}
			else if (LexName[i] == "key" && TKey[Id[i]] == "while") {
				AssemblerCode += "wmetka" + WhileMetki->Count + ":\r\n";
				WhileMetki->Add(WhileMetki->Count);
				LastKey->Add(3);
				TC = WHILE;
			}
			else if (LexName[i] == "key" && TKey[Id[i]] == "print") {
				TC = PRINT;
			}
			else if (LexName[i] == "dlm" && TD[Id[i]] == '}') {
				LastKey->RemoveAt(LastKey->Count - 1);
				if (LastKey[LastKey->Count - 1] == 3) {
					AssemblerCode += "jmp wmetka" + (WhileMetki->Count - while_closed_sf - 1) + "\r\n";
					while_closed_sf++;
					if (LastKey->Count == 0) {
						return "";
					}
					LastKey->RemoveAt(LastKey->Count - 1);
				}


				AssemblerCode += "metka" + (Metki->Count - closed_sf - 1) + ":\r\n";
				closed_sf++;
				AssemblerCode += "\r\n";
				TC = H;
			}
			break;
		case MATH:
			if (LexName[i] == "id" && last_oper != 0) {
				AssemblerCode += OperAxIDNUM(Convert::ToChar(TKey[last_oper]), Id[i], true);
				TC = MATH;
			}
			else if (LexName[i] == "num" && last_oper != 0) {
				AssemblerCode += OperAxIDNUM(Convert::ToChar(TKey[last_oper]), Convert::ToDouble(TNUM[Id[i]]), false);
				TC = MATH;
			}
			else if (LexName[i] == "id") {
				AssemblerCode += MovAxID(Id[i]);
				TC = MATH;
			}
			else if (LexName[i] == "num") {
				AssemblerCode += MovAxNUM(Convert::ToDouble(TNUM[Id[i]]));
				TC = MATH;
			}
			else if (LexName[i] == "key" && Id[i] >= 8 && Id[i] <= 11) {
				last_oper = Id[i];
				TC = MATH;
			}
			else if (LexName[i] == "dlm" && TD[Id[i]] == ';') {
				AssemblerCode += MovIDAx(variable, false);
				last_oper = 0;
				AssemblerCode += "\r\n";
				TC = H;
			}
			break;
		case IF:
			if (LexName[i] == "dlm" && TD[Id[i]] == '(') {
				TC = MATHKEY;
			}
			else if (LexName[i] == "dlm" && TD[Id[i]] == '{') {
				if (last_srav_oper == 0)AssemblerCode += OperMetka(Convert::ToChar(TKey[10]), Metki->Count, true);
				else AssemblerCode += OperMetka(Convert::ToChar(TKey[last_srav_oper]), Metki->Count, false);
				Metki->Add(Metki->Count);
				last_srav_oper = 0;
				AssemblerCode += "\r\n";
				TC = H;
			}

			break;
		case MATHKEY:
			if (LexName[i] == "id" && last_oper != 0) {
				AssemblerCode += OperAxIDNUM(Convert::ToChar(TKey[last_oper]), Id[i], true);
				TC = MATHKEY;
			}
			else if (LexName[i] == "num" && last_oper != 0) {
				AssemblerCode += OperAxIDNUM(Convert::ToChar(TKey[last_oper]), Convert::ToDouble(TNUM[Id[i]]), false);
				TC = MATHKEY;
			}
			else if (LexName[i] == "id") {
				AssemblerCode += MovAxID(Id[i]);
				TC = MATHKEY;
			}
			else if (LexName[i] == "num") {
				AssemblerCode += MovAxNUM(Convert::ToDouble(TNUM[Id[i]]));
				TC = MATHKEY;
			}
			else if (LexName[i] == "key" && Id[i] >= 8 && Id[i] <= 11) {
				last_oper = Id[i];
				TC = MATHKEY;
			}
			else if (LexName[i] == "key" && Id[i] >= 4 && Id[i] <= 7) {
				AssemblerCode += MovIDAx(TID->Count + 1, false);
				last_srav_oper = Id[i];
				last_oper = 0;
				TC = MATHKEY;
			}
			else if (LexName[i] == "dlm" && TD[Id[i]] == ')') {
				AssemblerCode += MovIDAx(0, true);
				last_oper = 0;
				TC = IF;
			}
			break;
		case WHILE:
			if (LexName[i] == "dlm" && TD[Id[i]] == '(') {
				LastKey->Add(2);
				TC = MATHKEY;
			}
			break;
		case PRINT:
			if (LexName[i] == "id" && last_oper != 0) {
				AssemblerCode += OperAxIDNUM(Convert::ToChar(TKey[last_oper]), Id[i], true);
				TC = PRINT;
			}
			else if (LexName[i] == "num" && last_oper != 0) {
				AssemblerCode += OperAxIDNUM(Convert::ToChar(TKey[last_oper]), Convert::ToDouble(TNUM[Id[i]]), false);
				TC = PRINT;
			}
			else if (LexName[i] == "id") {
				AssemblerCode += MovAxID(Id[i]);
				TC = PRINT;
			}
			else if (LexName[i] == "num") {
				AssemblerCode += MovAxNUM(Convert::ToDouble(TNUM[Id[i]]));
				TC = PRINT;
			}
			else if (LexName[i] == "key" && Id[i] >= 8 && Id[i] <= 11) {
				last_oper = Id[i];
				TC = PRINT;
			}
			else if (LexName[i] == "dlm" && TD[Id[i]] == ';') {
				AssemblerCode += MovIDAx(variable, true);
				AssemblerCode += PrintAx();
				AssemblerCode += "\r\n";
				last_oper = 0;
				TC = H;
			}
			break;
		default:
			break;
		}

	}

	return AssemblerCode;
}
String^ id_or_word(String^ buf, List<String^>^ TKey, List<String^>^ TID, List<String^>^ Name, List<int>^ Id, int &n) {

	for (int i = 0; i < TKey->Count; i++) {
		if (TKey[i] == buf) {
			Name->Add("key"); Id->Add(i);
			if (i >= 1 && i <= 2)n++;
			return"<key," + i + ">\r\n";
		}
	}

	for (int i = 0; i < TID->Count; i++) {
		if (TID[i] == buf) {
			Name->Add("id"); Id->Add(i);
			return"<id," + i + ">\r\n";
		}
	}

	TID->Add(buf);
	Name->Add("id"); Id->Add(TID->Count - 1);
	return "<id," + (TID->Count - 1) + ">\r\n";
}
bool scan(String^ Input, TextBox^ Output) {
	enum state { ER, H, ID, NUM, ASN, DLM, END, IDAsn, MATH, DLMPhase, KEY, MATHKey, IDKey, NUMKey };
	enum state TC; /* текущее состояние */
	String^ sOutput = "";
	int key_num = 0;

	TID = gcnew List<String^>(0); // таблица идентификаторов анализируемой программы;
	TNUM = gcnew List<String^>(0); // таблица чисел-констант, используемых в программе;

	LexName = gcnew List<String^>(0); // таблица имен лексем
	Id = gcnew List<int>(0); // таблица id лексем

	TKey = gcnew List<String^>(0); // таблица ключевых слов входного языка;
	TD = gcnew List<char>(0); // таблица разделителей входного языка; 

	String^ buf; /* для накопления символов лексемы */

	TKey->Add("print");
	TKey->Add("if");
	TKey->Add("while");
	TKey->Add("=");
	TKey->Add(">");
	TKey->Add("<");
	TKey->Add("!");
	TKey->Add(":");
	TKey->Add("+");
	TKey->Add("-");
	TKey->Add("*");
	TKey->Add("/");

	TD->Add('(');
	TD->Add(')');
	TD->Add('{');
	TD->Add('}');
	TD->Add(';');
	//л. анализатор
	TC = H;
	int j = 0;
	while (j < Input->Length) {
		switch (TC) {
		case H:
			buf = "";
			if (Input[j] == ' ' || Input[j] == '\n' || Input[j] == '\r' || Input[j] == '\t')j++;
			else if ((Input[j] >= 97 && Input[j] <= 122) || (Input[j] >= 65 && Input[j] <= 90)) {
				buf += Convert::ToChar(Input[j]);
				j++;
				TC = ID;
			}
			else if (Input[j] == '>' || Input[j] == '<' ||
				Input[j] == '!' || Input[j] == ':' ||
				Input[j] == '-' || Input[j] == '*' || Input[j] == '/' || Input[j] == '+') {
				buf += Convert::ToChar(Input[j]);
				j++;
				sOutput += id_or_word(buf, TKey, TID, LexName, Id, key_num);
				TC = H;
			}
			else if (Input[j] >= 48 && Input[j] <= 57) {
				buf += Convert::ToChar(Input[j]);
				j++;
				TC = NUM;
			}
			else if (Input[j] == '=') {
				buf += Convert::ToChar(Input[j]);
				j++;
				TC = ASN;
			}
			else if (Input[j] == '|') {
				TC = END;
			}
			else TC = DLM;
			break;
		case ID:
			if ((Input[j] >= 97 && Input[j] <= 122) || (Input[j] >= 65 && Input[j] <= 90)) {
				buf += Convert::ToChar(Input[j]);
				j++;
			}
			else {
				sOutput += id_or_word(buf, TKey, TID, LexName, Id, key_num);
				TC = H;
			}
			break;
		case NUM:
			if ((Input[j] >= 48 && Input[j] <= 57) || Input[j] == 46) {
				buf += Convert::ToChar(Input[j]);
				j++;
			}
			else {
				bool flag = false;
				for (int i = 0; i < TNUM->Count; i++) {
					if (TNUM[i] == buf) {
						sOutput += "<num," + i + ">\r\n";
						LexName->Add("num"); Id->Add(i);
						flag = true;
					}
				}
				if (!flag) {
					TNUM->Add(buf);
					sOutput += "<num," + (TNUM->Count - 1) + ">\r\n";
					LexName->Add("num"); Id->Add(TNUM->Count - 1);
				}
				TC = H;
			}
			break;
		case ASN:
			for (int i = 0; i < TKey->Count; i++) {
				if (TKey[i] == buf) {
					LexName->Add("asn"); Id->Add(i);
					sOutput += "<asn," + i + ">\r\n";
				}
			}
			TC = H;
			break;
		case DLM:
			bool flag = false;
			for (int i = 0; i < TD->Count; i++) {
				if (TD[i] == Input[j]) {
					sOutput += "<dlm," + i + ">\r\n";
					LexName->Add("dlm"); Id->Add(i);
					j++;
					TC = H;
					flag = true;
				}
			}
			if (!flag) {
				sOutput += "Unknown charcter: " + Input[j] + "\r\n";
				TC = ER;
				j++;

			}
			break;
		}
		if (TC == END || TC == ER)break;
	}

	if (TC == ER) {
		sOutput += "ERROR !!!\r\n";
	}
	else sOutput += "Lex analysis is ok!\r\n";

	Output->Text = sOutput;
	if (TC == ER)return 0;


	//с. анализатор
	TC = H;
	int key_sk = 0;
	int key_sf = 0;
	int sk = 0;
	int sf = 0;
	{
		bool Operflag = false;
		for (int i = 0; i < LexName->Count; i++) {
			switch (TC) {
			case H:
				if (LexName[i] == "id") {
					TC = IDAsn;
				}
				else if (LexName[i] == "key" && Id[i] == 0) {
					TC = MATH;
				}
				else if (LexName[i] == "key" && Id[i] >= 1 && Id[i] <= 2) {
					TC = KEY;
				}
				else {
					TC = ER;
				}
				break;
			case IDAsn:
				if (LexName[i] == "asn") {
					TC = MATH;
				}
				else {
					TC = ER;
				}
				break;
			case DLM:
				if (sk < 0 && sf < 0) {
					TC = ER;
					break;
				}
				if (LexName[i] == "id") {
					TC = IDKey;
				}
				else if (LexName[i] == "num") {
					TC = NUMKey;
				}
				else {
					TC = ER;
				}
				break;
			case NUM:
				if (Id[i] >= 8 && Id[i] <= 11) {
					TC = MATH;
				}
				else if (LexName[i] == "dlm" && TD[Id[i]] == ';') {
					TC = DLMPhase;
				}
				else {
					TC = ER;
				}
				break;
			case ID:
				if (Id[i] >= 8 && Id[i] <= 11) {
					TC = MATH;
				}
				else if (LexName[i] == "dlm" && TD[Id[i]] == ';') {
					TC = DLMPhase;
				}
				else {
					TC = ER;
				}
				break;
			case KEY:
				if (LexName[i] == "dlm" && TD[Id[i]] == '(') {
					sk++;
					key_sk++;
					TC = DLM;
				}
				else {
					TC = ER;
				}
				break;
			case MATH:
				if (LexName[i] == "id") {
					TC = ID;
				}
				else if (LexName[i] == "num") {
					TC = NUM;
				}
				else {
					TC = ER;
				}
				break;
			case DLMPhase:
				if (sk == 0 && LexName[i] == "dlm" && TD[Id[i]] == '{') {
					if (LexName[i - 1] != "dlm" || TD[Id[i - 1]] != ')') {
						TC = ER;
						break;
					}
					sf++;
					key_sf++;
					TC = DLMPhase;
				}
				else if (sk == 0 && LexName[i] == "dlm" && TD[Id[i]] == '}') {
					sf--;
					TC = DLMPhase;
				}
				else if (sk == 0 && LexName[i] == "dlm" && TD[Id[i]] == ';') {
					TC = DLMPhase;
				}
				else if (sk == 0 && LexName[i] == "id") {
					TC = IDAsn;
				}
				else if (LexName[i] == "key" && Id[i] == 0) {
					TC = MATH;
				}
				else if (sk == 0 && Id[i] >= 1 && Id[i] <= 2 && LexName[i] == "key") {
					TC = KEY;
				}
				else {
					TC = ER;
				}
				break;
			case ER:
				textBox2->Text = "ERROR: " + i + "\r\n";
				i = LexName->Count;
				break;
			case NUMKey:
				if (Id[i] >= 8 && Id[i] <= 11) {
					TC = MATHKey;
				}
				else if (LexName[i] == "dlm" && TD[Id[i]] == ')') {
					sk--;
					Operflag = false;
					TC = DLMPhase;
				}
				else if (LexName[i] == "key" && Id[i] >= 4 && Id[i] <= 7 && !Operflag) {
					Operflag = true;
					TC = MATHKey;
				}
				else {
					TC = ER;
				}
				break;
			case IDKey:
				if (Id[i] >= 8 && Id[i] <= 11) {
					TC = MATHKey;
				}
				else if (LexName[i] == "dlm" && TD[Id[i]] == ')') {
					sk--;
					Operflag = false;
					TC = DLMPhase;
				}
				else if (LexName[i] == "key" && Id[i] >= 4 && Id[i] <= 7 && !Operflag) {
					Operflag = true;
					TC = MATHKey;
				}
				else {
					TC = ER;
				}
				break;
			case MATHKey:
				if (LexName[i] == "id") {
					TC = IDKey;
				}
				else if (LexName[i] == "num") {
					TC = NUMKey;
				}
				else {
					TC = ER;
				}
				break;
			}
		}
		if (TC != DLMPhase)TC = ER;

	}



	if (sf != 0 || sk != 0 || key_sk != key_num || key_sf != key_num) {
		textBox2->Text = "ERROR: with '{}' or '()'";
		return 0;
	}
	return TC;
}
void FileGen() {
	String^ AsmCode = "";
	System::IO::StreamReader^ stream1 = System::IO::File::OpenText("Header.txt");
	AsmCode = stream1->ReadToEnd();
	delete (IDisposable^)stream1;

	AsmCode += "\r\n" + Asm() + "\r\n";

	System::IO::StreamReader^ stream2 = System::IO::File::OpenText("Footer.txt");
	AsmCode += stream2->ReadToEnd();
	delete (IDisposable^)stream2;

	textBox3->Text = AsmCode;

	SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog();
	saveFileDialog1->Filter = "asm files (*.asm)|*.asm";
	saveFileDialog1->FilterIndex = 1;
	saveFileDialog1->RestoreDirectory = true;

	if (saveFileDialog1->ShowDialog() != System::Windows::Forms::DialogResult::OK)return;
	System::IO::StreamWriter^ s = gcnew System::IO::StreamWriter(saveFileDialog1->FileName);
	s->Write(AsmCode);
	s->Close();
}

private: System::Void Button1_Click(System::Object^ sender, System::EventArgs^ e) {
	textBox1->Text = "";
	textBox2->Text = "";
	textBox3->Text = "";
	if (scan(tbInput->Text + "|", textBox1)) {
		textBox2->Text = "Syntax analysis is ok!";
		//textBox3->Text = Asm();
		FileGen();
	}
	else if (textBox2->Text == "")textBox2->Text = "Syntax analysis Error!";

}
private: System::Void TbInput_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	int gittest = 2;
	int gittest2 = 1;
	textBox1->Text = "";
	textBox2->Text = "";
	textBox3->Text = "";
	if (scan(tbInput->Text + "|", textBox1)) {
		textBox2->Text = "Syntax analysis is ok!";
	}
	else if (textBox2->Text == "")textBox2->Text = "Syntax analysis Error!";
}
};
}
