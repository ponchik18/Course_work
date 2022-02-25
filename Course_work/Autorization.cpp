#include "Autorization.h"

bool Autorization::printLoginInFile()
{

	//ofstream mainAdmin("MainAdmin.dat", ios::binary | ios::out);
	//if (!(mainAdmin.is_open())) {
	//	cout << "Ошибка открытия файла с главным админом" << endl;
	//	system("pause");
	//	return false;
	//}
	//char login[] = "MaksBovkun2003";
	//int len = strlen(login) + 1;
	//mainAdmin.write((char*)&len, sizeof(int));
	//mainAdmin.write((char*)login, sizeof(char) * len);
	//char password[] = "asdf1234";
	//len = strlen(password) + 1;
	//mainAdmin.write((char*)&len, sizeof(int));
	//mainAdmin.write((char*)password, sizeof(char) * len);
	//mainAdmin.close();
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
