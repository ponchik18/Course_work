#pragma once
#include"library.h"
class Autorization
{
public:

private:
	bool readMainAccountFromFile(char* MainLogin, char* MainPassword); //для считывания основного аккаунта, который нельзя будет удалить
	bool mainAdmin();
	bool registerAccount();
	bool printLoginInFile();
	bool compareAccount(char* CinLogin, char* login, char* CinPassword, char* password);//для стравнение введённых данных с данными существующих аккаунтов
	friend class Autorization;
	friend class Users;
	
	
};

