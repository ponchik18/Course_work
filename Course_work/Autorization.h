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
	bool readMainAccountFromFile(char* MainLogin, char* MainPassword); //для считывания основного аккаунта, который нельзя будет удалить
	bool mainAdmin();
	bool EnterIntoAccount(char* MainLogin, char* MainPassword, UsersType& mode);
	bool signInUsers(char* MainLogin, char* MainPassword);//вход пользователя в аккаунт для USERS
	bool registerAccount(char* MainLogin, char* MainPassword, UsersType& mode);// регистрируем аакаунт для USERS
	bool printLoginInFile();
	bool IfCreatedAccount(char* MainLogin);//true-если аккаунт уже существует false-нет такого аккаута
	bool IfCreatedAccountChouseFail(ifstream& file, char* MainLogin);
	bool compareAccount(char* CinLogin, char* login, char* CinPassword, char* password);//для стравнение введённых данных с данными существующих аккаунтов
	friend class Administrators;
	friend class Users;
	
	
};

