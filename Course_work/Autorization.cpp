#include "Autorization.h"

bool Autorization::EnterIntoAccount(char* MainLogin, char* MainPassword, int *mode)
{
	ifstream AccountUsers("AccountUsersAdministration.dat", ios::binary | ios::in);
	if (!(AccountUsers.is_open())) {
		cout << "Ошибка открытия файла с аккаунтами" << endl;
		exit(0);
	}
	char* login = nullptr;
	char* password = nullptr;
	while (!(AccountUsers.eof())) {
		AccountUsers.read((char*)mode, sizeof(int));
		int len;
		
		AccountUsers.read((char*)&len, sizeof(int));//читаем длинну логин
		login = new char[len];
		AccountUsers.read((char*)login, sizeof(char) * len);//читаем логин

		AccountUsers.read((char*)&len, sizeof(int));//читаем длинну пароль
		password = new char[len];
		AccountUsers.read((char*)password, sizeof(char) * len);//читаем пароль
		if (compareAccount(MainLogin, login, MainPassword, password)) {
			delete[] login;
			delete[] password;
			AccountUsers.close();
			return true;
		}
		delete[] login;
		delete[] password;

	}
	AccountUsers.close();
	return false;
}

bool Autorization::signInUsers(char* MainLogin, char* MainPassword)
{
	ifstream AccountUsers("FileWithAcconutForUsersAndAdministrators.dat", ios::binary | ios::in);
	if (!(AccountUsers.is_open())) {
		cout << "Ошибка открытия файла с аккаунтами" << endl;
		return false;
	}
	char* login=nullptr;
	char* password=nullptr;
	while (!(AccountUsers.eof())) {
		int i = 0;
		AccountUsers.read((char*)&i, sizeof(int));
		int len;
		AccountUsers.read((char*)&len, sizeof(int));
		if (i == 0) {
			AccountUsers.seekg(len, ios::cur);
		}

		else {
			AccountUsers.read((char*)login, len * sizeof(char));
		}

		AccountUsers.read((char*)&len, sizeof(int));

		if (i == 0) {
			AccountUsers.seekg(len, ios::cur);
		}

		else {
			AccountUsers.read((char*)password, len * sizeof(char));
		}
		if (i != 0) {
			if (login, MainLogin, password, MainPassword) {
				cout << "Аккаунт найден!" << endl;
				return true;
			}
			delete[] password;
			delete[] login;
		}
	}
	return true;
}

bool Autorization::registerAccount(char* MainLogin, char* MainPassword)
{
	ofstream AccountUsers("AccountUsersAdministration.dat", ios::binary | ios::app);
	if (!(AccountUsers.is_open())) {
		cout << "Ошибка открытия файла с главным админом" << endl;
		system("pause");
		system("cls");
		return false;
	}
	int j = AccountUsers.tellp();
	system("cls");
	cout << "выберите режим работы 1-Users, 2-Administrators";
	int i=0;
	//AccountUsers.write((char*)&i, sizeof(int));
	cin >> i;
	AccountUsers.write((char*)&i, sizeof(i));
	int len = strlen(MainLogin) + 1;
	AccountUsers.write((char*)&len,sizeof(len));
	AccountUsers.write((char*)MainLogin, sizeof(char) * len);
	len = strlen(MainPassword) + 1;
	AccountUsers.write((char*)&len, sizeof(len));
	AccountUsers.write((char*)MainPassword, sizeof(char) * len);
	cout << endl << "Регистрация завершена! Модератор позже подтвердит(опровергнет) регистрацию!";
	_getch();
	system("cls");
	AccountUsers.close();
	return true;
}

bool Autorization::printLoginInFile()
{

	
	return true;
}

bool Autorization::compareAccount(char* CinLogin, char* login, char* CinPassword, char* password)
{
	if ((strcmp(CinLogin, login) == 0) && (strcmp(CinPassword, password) == 0)) {
		return true;
	}
	return false;
}

bool Autorization::readMainAccountFromFile(char* MainLogin, char* MainPassword)
{
	ifstream mainAdmin("MainAdmin.dat", ios::binary | ios::in);
	if (!(mainAdmin.is_open())) {
		cout << "Ошибка открытия файла с главным админом" << endl;
		exit(0);
	}
	char* login;
	int len;
	mainAdmin.read((char*)&len, sizeof(int));
	login = new char[len];
	mainAdmin.read((char*)login, sizeof(char)*len);
	char* password;
	mainAdmin.read((char*)&len, sizeof(int));
	password = new char[len];
	mainAdmin.read((char*)password, sizeof(char) * len);
	mainAdmin.close();
	bool flag = compareAccount(MainLogin, login, MainPassword, password);
	delete[] login;
	delete[] password;
	return flag;
}
