#pragma once
#include"library.h"
#include"Users.h"
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
	bool EnterIntoAccount(char* MainLogin, char* MainPassword, UsersType& mode);
	bool signInUsers(char* MainLogin, char* MainPassword);//���� ������������ � ������� ��� USERS
	bool registerAccount(char* MainLogin, char* MainPassword, UsersType& mode);// ������������ ������� ��� USERS
	bool printLoginInFile();
	bool IfCreatedAccount(char* MainLogin);//true-���� ������� ��� ���������� false-��� ������ �������
	bool IfCreatedAccountChouseFail(ifstream& file, char* MainLogin);
	bool compareAccount(char* CinLogin, char* login, char* CinPassword, char* password);//��� ���������� �������� ������ � ������� ������������ ���������
	friend class Administrators;
	friend class Users;
	
	
};

