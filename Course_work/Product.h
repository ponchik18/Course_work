#pragma once
#include"library.h"
class Product //����� ����� �� ������
{
private:
	std::string productName; //�������� ������ 
	struct dataOfArrival { //��������� ��� �������� ������ � ���� �������� ������ �� �����
		int day; //���� ��������
		int month; //����� ��������
		int year; //��� ��������
	};
	int count; //���������� ������ ������ �� ������
	float priseForOneCount; //���� �� ������� ������
	struct PeopleThatAcceptedProduct { //�������, ������� ������ �����(��� ���)
		std::string LastName;//�������
		std::string FirstName;//���
		std::string SurName;//��������
	};
public:
	Product();
	void coutInfoAboutOneProduct() const; //����� ���������� �� ����� ��������(������)
	void readInfoAboutOneProductFromFile();//������ � ����� ������ ��������(������)
	void writeInfoAboutOneProductFromFile();//������ ������ �� ����� ��������(������) � ����
	void cinInfoAboutOneProduct();//���� ������ �� ����� �������� � �������
	~Product();
	
	//friend void Users::SortProductByProductName(Product* pd);//����������� ����� �����(���������� �� ������������)
	//friend void Users::SortProductByProductData(Product* pd);//����������� ����� �����(���������� �� ����)
	//friend void Users::SortProductByProductPrise(Product* pd);//����������� ����� �����(���������� �� ����)
	friend class Users;
	friend class Administrators;
};

