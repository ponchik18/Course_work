#include "Autorization.h"

bool Autorization::EnterIntoAccount(char* MainLogin, char* MainPassword, UsersType& mode)
{
	ifstream AccountUsers("AccountActivated.dat", ios::binary | ios::in);
	if (!(AccountUsers.is_open())) {
		cout << "Ошибка открытия файла с аккаунтами" << endl;
		exit(0);
	}
	char* login = nullptr;
	char* password = nullptr;
	int flag = -1;
	while (AccountUsers.read((char*)&flag, sizeof(int))) {
		if (flag == 0)
			mode = user;
		else mode = admin;
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
			AccountUsers.read(login, len * sizeof(char));
		}

		AccountUsers.read((char*)&len, sizeof(int));

		if (i == 0) {
			AccountUsers.seekg(len, ios::cur);
		}

		else {
			AccountUsers.read(password, len * sizeof(char));
		}
		if (i != 0) {
			if (compareAccount(login, MainLogin, password, MainPassword)) {
				cout << "Аккаунт найден!" << endl;
				return true;
			}
			delete[] password;
			delete[] login;
		}
	}
	return true;
}

bool Autorization::registerAccount(char* MainLogin, char* MainPassword, UsersType &mode)
{
	if (IfCreatedAccount(MainLogin))
	{
		cout <<endl<<endl <<"\t\t\t\t\t\tДанный аккаунт уже существует"<<endl<< "\t\t\t\t\t\t";
		system("pause");
		system("cls");
		return false;
	}
	ofstream AccountUsers("NotConfirmedAccount.dat", ios::binary | ios::app);
	if (!(AccountUsers.is_open())) {
		cout << "Ошибка открытия файла с данными о пользователях" << endl;
		system("pause");
		system("cls");
		exit(0);
	}
	system("cls");
	valarray<string> menu = {
	"Пользователь;",
	"Администратор;"
	};

	Users::Console text(menu.size() + 4 - 1);
	int flag = -1;
	while (flag==-1) {

		text.menuShow("Меню для выбора режима работы", text);
		text.CinMenuAutorization(menu);
		flag=text.PointerMoveModeRegistration();
		system("cls");

	}
	if (flag == 0)
		mode = user;
	else mode = admin;
	AccountUsers.write((char*)&flag, sizeof(flag));
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

bool Autorization::IfCreatedAccountChouseFail(ifstream& file, char* MainLogin)
{
	if (!(file.is_open())) {
		system("cls");
		cout << "Ошибка открытия файла с уже зарегистрированными пользователями!" << endl;
		system("pause");
		exit(0);
	}
	int c;
	while (file.read((char*)&c, sizeof(c))) {
		char* login;

		int len = 0;

		file.read((char*)&len, sizeof(len));
		login = new char[len];
		file.read((char*)login, len * sizeof(char));
		file.read((char*)&len, sizeof(len));
		file.seekg(len * sizeof(char), ios::cur);
		if (strcmp(login, MainLogin) == 0) {
			delete[] login;
			return true;
		}
		delete[] login;
	}
	file.close();
	return false;
}

bool Autorization::IfCreatedAccount(char* MainLogin)
{
	bool flag, rezult=false;
	ifstream AccountUsers("AccountActivated.dat", ios::binary | ios::in);
	flag=IfCreatedAccountChouseFail(AccountUsers, MainLogin);
	AccountUsers.close();
	if (flag == true)
		rezult=true;
	AccountUsers.open("MainAdmin.dat", ios::binary | ios::in);
	flag = IfCreatedAccountChouseFail(AccountUsers, MainLogin);
	if (flag == true)
		rezult = true;
	AccountUsers.close();
	AccountUsers.open("NotConfirmedAccount.dat", ios::binary | ios::in);
	flag = IfCreatedAccountChouseFail(AccountUsers, MainLogin);
	if (flag == true)
		rezult = true;
	AccountUsers.close();
	return rezult;
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
	int len;
	mainAdmin.read((char*)&len, sizeof(int));
	char* login;
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
