#pragma once
#include"library.h"
#include"Product.h"
#include"Autorization.h"
//�������� ������� � ���������� �������, ���������� ������� �������� � ���� <Users.cpp>

class Users // ������� ����� 
{
	
protected:
	class Console;
	void SortProductByProductName(Product* pd);//���������� �� ������������
	void SortProductByProductData(Product* pd);//���������� �� ����
	void SortProductByProductPrise(Product* pd);//���������� �� ����

	char* CoutString(Console& p);//������� ����� ������ 
	char* CoutStringPassword(Console& p);//������� ����� ������(������)
	//void showMenuAutorization(Console& p);

	class Console {
	public:
		HANDLE hStdOut; //���������� �������
		int ActiveMenu; //�������� ����� ����
		int ActiveMenuStart; // ����� ������ ����
		int ActiveMenuEnd; //����� ����� ����
		Console(int amend=9, int amstart = 4) {
			hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);// �������� ���������� �������
			this->ActiveMenu = this->ActiveMenuStart=amstart;
			this->ActiveMenuEnd = amend;
			ConsoleCursorVisible(false, 10);
			} 
		void changeEnd(int amend){ this->ActiveMenuEnd = amend; }
		void CinMenu(valarray<string>& menu); //����� ���������� ����
		void CinMenuAutorization(valarray<string>& menu);
		void GoToXY(short y, short x=40); //����������� �������
		void ConsoleCursorVisible(bool show, short size);// �������� ������ � ��������� �������
		void ConsoleActiveTextColor(int&& n, Console& p);// ������ ���� ������ ������, ��� m = n
		void SetTextActiveColor(Console& p);//������ ���� ��������� ���� ����
		void ConsoleTextColor();// ������ ���� �������� ������
		void ConsoleMenuColorText();//������ ���� ����
		bool PointerMovemenuForOnlyReadInfo();// ����� ��� ������������ ������� �������
		int PointerMoveModeRegistration();
		int PoinetrMoveModeAdmisrator();
		void menuShow(string menuName, Console& text); //� ������� ��������� ������, ������� ����� ���������� �� ������ ����

		

	};

	
public:

	void showInfoAboutProduct(Product* pd) const;//����� ���������� �� �������
	void cinInfoAboutProduct(Product* pd); //���� ���������� �� ������
	void searchProductByFields(Product* pd) const;// ����� ������(-��) �� ����
	void SortProductByFields(Product* ps);// ���������� ������ 
	void menuForOnlyReadInfo(Console& text);// ���� ��� ������ ������ � ������������� ������
//	void registerUsers();//���������� ������������
	friend class Autorization;
};

///////////////////////////////



////////////////////////////////

class Administrators : public Users { //����� �������������, ������� ������������ �� ����� Users � ������������� ������� private
private:
	enum WorkingModeAdministrators //����������� ������� ��� �������� ��������� ������ ������ 
	{
		WorkWithAccount = 1, //������ � ����������
		WorkWithChangeFields, //������ � �������������� ����� 
		WorkWithOnlyReadInfo // ������ ������ � ���������� �����
	};
	class ConsoleforAdmistrators : public Console {
	public:
		ConsoleforAdmistrators(int amend = 9, int amstart = 4): Console(amend, amstart){}
		bool PointerMovemenuWorkingWithAccount();// ����� ��� ������������ ������� �������
		bool PointerMovemenuWorkingWithChangingFields();// ����� ��� ������������ ������� �������
		void NotConfirmedAccount();
		void showNotConfimedUsers();
		void showHeadMenuNotcofmedUsers();
		void PrintAllNotConfirmedUsers();
		class Account {
		public:
			int mode;
			shared_ptr<char> login;
			int PositionInList;
		};
		list<Account> ListWithAccountOrder;
		void ConfirmedAccount(int positionAccount, const int CountAccount);
		void ScanOneAccount(ifstream& AccountNotConfirmed, int& PositionInFile, int& TypeAccount);

		class Print {
		public:
			int* Yposition;
			void operator()(Account& Element, int ActiveField) {
				ConsoleforAdmistrators text;
				text.GoToXY(*Yposition, 45);
				cout << "|";
				text.GoToXY(*Yposition, 47);
				if (*Yposition == ActiveField) {
					text.SetTextActiveColor(text);
				}
				if (Element.mode == 0) {
					cout << "������������";
				}
				else cout << "�������������";
				text.GoToXY(*Yposition, 75);
				cout << Element.login << endl;
				text.GoToXY(*Yposition, 94);
				text.ConsoleTextColor();
				cout << "|";
				(*Yposition)+=1;
			}

			void SetPos(int* Pos) { this->Yposition = Pos; }
		};
		int PointerForApproveAccount();
		bool ApproveYourChoice(string& Question, int YPosition, int Xposition);
		int PointerMoveForApproveYourChoice();
		void MenuYesOrNo(string& Question, int YPosition, int Xposition);
		
	};
	//void establishMenuForWorkingMode(Product* ps);// ������������� �������� ����� ������� � ����� ���������� ����� � �������������� ���� ������
public:
	void showMenuAutorization(Console& p, bool flag);// ������� ����� ������ ���� ��� ������������
	void menuForOnlyReadInfo(Console& text);// ���� ��� ������ ������ � ������������� ������
	bool registerUsers();//���������� ������������
	void ShowMenuAcordingToMode(UsersType& mode);
	void SortProductByFields(Product* ps);// ���������� ������ 
	void showInfoAboutProduct() const; //����� ���������� �� �������
	void cinInfoAboutProduct(Product* pd); //���� ���������� �� ������
	void searchProductByFields(Product* pd) const;// ����� ������(-��) �� ����
	void changeProductFields(Product* pd);//��������� ���������� �� ������
	void estabishWorkMode(WorkingModeAdministrators & type);//����������� ������ ������
	void PrintMenuAccordingToModeWorking(WorkingModeAdministrators type);
	void establishMenuForWorkingMode();// ������������� �������� ����� ������� � ����� ���������� ����� � �������������� ���� ������
	void menuForWorkingWithAccount();//���� ��� ������ � ����������
	void menuForWorkingWithCnangeFields();//���� ��� ������ � ������������� ������
	void menuWorkingWithAccount(Console& text);
	void menuWorkingWithChangingFields(Console& text);
};

