#pragma once
#include"library.h"
class Autorization
{
public:

private:
	bool readMainAccountFromFile(char* MainLogin, char* MainPassword); //��� ���������� ��������� ��������, ������� ������ ����� �������
	bool mainAdmin();
	bool registerAccount();
	bool printLoginInFile();
	bool compareAccount(char* CinLogin, char* login, char* CinPassword, char* password);//��� ���������� �������� ������ � ������� ������������ ���������
	friend class Autorization;
	friend class Users;
	
	
};

