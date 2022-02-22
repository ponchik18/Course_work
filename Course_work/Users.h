#pragma once
#include"Product.h"
#include<Windows.h>

//�������� ������� � ���������� �������, ���������� ������� �������� � ���� <Users.cpp>

class Users // ������� ����� 
{

protected:
	void SortProductByProductName(Product* pd);//���������� �� ������������
	void SortProductByProductData(Product* pd);//���������� �� ����
	void SortProductByProductPrise(Product* pd);//���������� �� ����
	class Console {
	public:
		HANDLE hStdOut; //���������� �������
		Console() {hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);} // �������� ���������� �������
		void GoToXY(short y, short x); //����������� �������
		void ConsoleCursorVisible(bool show, short size);// �������� ������ � ��������� �������
		void ConsoleTextColor(int& n, int &am);// ������ ���� ������ ������, ��� m=n

	};
public:
	void showInfoAboutProduct(Product* pd) const;//����� ���������� �� �������
	void cinInfoAboutProduct(Product* pd); //���� ���������� �� ������
	void searchProductByFields(Product* pd) const;// ����� ������(-��) �� ����
	void SortProductByFields(Product* ps);// ���������� ������ 
	void menuForOnlyReadInfo();// ���� ��� ������ ������ � ������������� ������

	friend class Product;
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

