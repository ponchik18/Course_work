#pragma once
#include"library.h"
class Autorization
{
public:

private:
	enum WorkingMode {
		UsersMode, 
		AdministratorsMode
	};
	bool readMainAccountFromFile(char* MainLogin, char* MainPassword); //��� ���������� ��������� ��������, ������� ������ ����� �������
	bool mainAdmin();
	bool EnterIntoAccount(char* MainLogin, char* MainPassword, int* mode);
	bool signInUsers(char* MainLogin, char* MainPassword);//���� ������������ � ������� ��� USERS
	bool registerAccount(char* MainLogin, char* MainPassword);// ������������ ������� ��� USERS
	bool printLoginInFile();
	bool compareAccount(char* CinLogin, char* login, char* CinPassword, char* password);//��� ���������� �������� ������ � ������� ������������ ���������
	friend class Administrators;
	friend class Users;
	
	
};

