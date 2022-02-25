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
	void CinMenu(valarray<string> &menu, Console& p); //����� ���������� ����
	char* CoutString();//������� ����� ������ 
	char* CoutStringPassword(Console& p);//������� ����� ������(������)
	void showMenuAutorization(Console& p);

	class Console {
	public:
		HANDLE hStdOut; //���������� �������
		int ActiveMenu; //�������� ����� ����
		int ActiveMenuStart; // ����� ������ ����
		int ActiveMenuEnd; //����� ����� ����
		Console(int amend, int amstart = 4) {
			hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);// �������� ���������� �������
			this->ActiveMenu = this->ActiveMenuStart=amstart;
			this->ActiveMenuEnd = amend;
			ConsoleCursorVisible(false, 10);
			} 
		void GoToXY(short y, short x=40); //����������� �������
		void ConsoleCursorVisible(bool show, short size);// �������� ������ � ��������� �������
		void ConsoleActiveTextColor(int&& n, Console& p);// ������ ���� ������ ������, ��� m = n
		void SetTextActiveColor(Console& p);//������ ���� ��������� ���� ����
		void ConsoleTextColor();// ������ ���� �������� ������
		void ConsoleMenuColorText();//������ ���� ����
		void PointerMove();// ����� ��� ������������ ������� �������
		
		void menuShow(string menuName, Console& text); //� ������� ��������� ������, ������� ����� ���������� �� ������ ����
	};

	
public:

	void showInfoAboutProduct(Product* pd) const;//����� ���������� �� �������
	void cinInfoAboutProduct(Product* pd); //���� ���������� �� ������
	void searchProductByFields(Product* pd) const;// ����� ������(-��) �� ����
	void SortProductByFields(Product* ps);// ���������� ������ 
	void menuForOnlyReadInfo();// ���� ��� ������ ������ � ������������� ������
	void registerUsers();//���������� ������������

};

///////////////////////////////



////////////////////////////////

class Administrators : public Users { //����� �������������, ������� ������������ �� ����� Users � ������������� ������� private
private:
	enum WorkingMode //����������� ������� ��� �������� ��������� ������ ������ 
	{
		WorkWithAccount = 1, //������ � ����������
		WorkWithChangeFields, //������ � �������������� ����� 
		WorkWithOnlyReadInfo // ������ ������ � ���������� �����
	};
	void establishMenuForWorkingMode(Product* ps);// ������������� �������� ����� ������� � ����� ���������� ����� � �������������� ���� ������
public:
	
	void SortProductByFields(Product* ps);// ���������� ������ 
	void showInfoAboutProduct() const; //����� ���������� �� �������
	void cinInfoAboutProduct(Product* pd); //���� ���������� �� ������
	void searchProductByFields(Product* pd) const;// ����� ������(-��) �� ����
	void changeProductFields(Product* pd);//��������� ���������� �� ������
	void estabishWorkMode();//����������� ������ ������
	void establishMenuForWorkingMode();// ������������� �������� ����� ������� � ����� ���������� ����� � �������������� ���� ������
	void menuForOnlyReadInfo();// ���� ��� ������ ������ � ������������� ������
	void menuForWorkingWithAccount();//���� ��� ������ � ����������
	void menuForWorkingWithCnangeFields();//���� ��� ������ � ������������� ������

};

