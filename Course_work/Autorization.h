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
	bool readMainAccountFromFile(char* MainLogin, char* MainPassword); //для считывания основного аккаунта, который нельзя будет удалить
	bool mainAdmin();
	bool EnterIntoAccount(char* MainLogin, char* MainPassword, int* mode);
	bool signInUsers(char* MainLogin, char* MainPassword);//вход пользователя в аккаунт для USERS
	bool registerAccount(char* MainLogin, char* MainPassword);// регистрируем аакаунт для USERS
	bool printLoginInFile();
	bool compareAccount(char* CinLogin, char* login, char* CinPassword, char* password);//для стравнение введённых данных с данными существующих аккаунтов
	friend class Administrators;
	friend class Users;
	
	
};

