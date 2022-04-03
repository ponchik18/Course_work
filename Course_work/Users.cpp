#include "Users.h"
#include"library.h"
void Administrators::estabishWorkMode(WorkingModeAdministrators& type)
{
	valarray<string> menuWorkingMode = {
		"Работа с учётными записями",
		"Paбота с редактирование полей",
		"Работа только с простмотром данных"
	};
	Console text(menuWorkingMode.size() + 4 - 1);
	int flag = -1;
	while (flag == -1) {

		text.menuShow("Меню для выбора режима работы администратора", text);
		text.CinMenu(menuWorkingMode);
		flag = text.PoinetrMoveModeAdmisrator();
		system("cls");
	}
	switch (flag)
	{
	case 0:
		type = WorkWithAccount;
		break;
	case 1:
		type = WorkWithChangeFields;
		break;
	case 2:
		type = WorkWithOnlyReadInfo;
		break;
	default:
		break;
	}
	return ;
}

void Administrators::PrintMenuAccordingToModeWorking(WorkingModeAdministrators type)
{
	bool flag = true;
	ConsoleforAdmistrators text;
	switch (type)
	{
	case Administrators::WorkWithAccount:
		text.changeEnd(8);
		while (flag)
		{
			text.changeEnd(8);
			menuWorkingWithAccount(text);
			flag = text.PointerMovemenuWorkingWithAccount();
			system("cls");
		}
		break;
	case Administrators::WorkWithChangeFields:
		text.changeEnd(9);
		while (flag)
		{
			menuWorkingWithChangingFields(text);
			flag = text.PointerMovemenuWorkingWithChangingFields();
			system("cls");
		}
		break;
	case Administrators::WorkWithOnlyReadInfo:
		text.changeEnd(9);
		while (flag)
		{
			menuForOnlyReadInfo(text);
			flag=text.PointerMovemenuForOnlyReadInfo();
			system("cls");
		}
		break;
	default:
		break;
	}
	
}

void Administrators::establishMenuForWorkingMode()
{
	system("color 2f");
	std::string menuRegist[3] = {
	"Работа с учётными записями",
	"Paбота с редактирование полей",
	"Работа только с простмотром данных"
	};

}

void Administrators::menuWorkingWithAccount(Console& text)
{
	valarray<string> menu = {
	"Показать неподтверждённые аккаунты;",
	"Удалить аккаунт;",
	"Добавить аккаунт;",
	"Вывети все аккаунты",
	"Выйти из аккаунта."

	};

	text.menuShow("Меню работы с аккаунтами", text);
	text.CinMenu(menu);
}

void Administrators::menuWorkingWithChangingFields(Console& text)
{
	valarray<string> menu = {
	"Вывести данные;",
	"Изменить данные о товаре;",
	"Удалить данные о товаре;",
	"Добавить данные о товаре;",
	"Выйти из аккаунта."
	};

	text.menuShow("Меню работы с изменение данных", text);
	text.CinMenu(menu);
}

void Administrators::ConsoleforAdmistrators::NotConfirmedAccount()
{
	PrintAllNotConfirmedUsers();
}

void Administrators::ConsoleforAdmistrators::showNotConfimedUsers()
{
	
	ifstream InfoUsers("NotConfirmedAccount.dat", ios::binary | ios::out);
	if (!InfoUsers.is_open()) {
		exit(0);
	}

}

void Users::Console::CinMenu(valarray<string>& menu)
{
	cout << "|";
	GoToXY(ActiveMenuStart-1,133);
	cout << "|";
	for (int i = 0; i < menu.size(); i++) {
		cout << "|";
		GoToXY(ActiveMenuStart+i);
		
		ConsoleActiveTextColor(ActiveMenuStart + i, *this);
		cout << menu[i] << endl;
		ConsoleTextColor();//ставим значение цвета по умолчанию
		GoToXY(ActiveMenuStart + i,133);
		cout << "|"<<endl;
	}
	cout << "+------------------------------------------------------------------------------------------------------------------------------------+" << endl;
}

void Users::Console::CinMenuAutorization(valarray<string>& menu)
{
		cout << "|";
		GoToXY(ActiveMenuStart - 1, 133);
		cout << "|";
		for (int i = 0; i < menu.size(); i++) {
			cout << "|";
			GoToXY(ActiveMenuStart + i,50);

			ConsoleActiveTextColor(ActiveMenuStart + i, *this);
			cout << menu[i] << endl;
			ConsoleTextColor();//ставим значение цвета по умолчанию
			GoToXY(ActiveMenuStart + i, 133);
			cout << "|" << endl;
		}
		cout << "+------------------------------------------------------------------------------------------------------------------------------------+" << endl;
	
}

void Users::Console::menuShow(string menuName, Console & text)
{
	cout << "+------------------------------------------------------------------------------------------------------------------------------------+" << endl << "|";
	cout.width(73);
	text.ConsoleMenuColorText();
	cout << menuName;
	text.ConsoleTextColor();
	cout.setf(ios::right);
	cout.width(60);
	cout << "|" << endl;
	cout << "+------------------------------------------------------------------------------------------------------------------------------------+" << endl;
}

bool Administrators::ConsoleforAdmistrators::PointerMovemenuWorkingWithAccount()///////////////////////////////////////
{
	char ch;
	ch = _getch();
	if (ch == -32) ch = _getch(); // Отлавливаем стрелочки
	switch (ch)
	{
	case ESC:
		exit(0);
	case DOWN:
		if (this->ActiveMenu < this->ActiveMenuEnd)
			this->ActiveMenu++;
		break;
	case UP:
		if (this->ActiveMenu > this->ActiveMenuStart)
			this->ActiveMenu--;
		break;
	case ENTRY:
		switch (ActiveMenu) {
		case 4:
			this->NotConfirmedAccount();
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			return false;
			break;
		}
		break;
	default:
		break;
	}
	return true;
}

bool Administrators::ConsoleforAdmistrators::PointerMovemenuWorkingWithChangingFields()
{
	char ch;
	ch = _getch();
	if (ch == -32) ch = _getch(); // Отлавливаем стрелочки
	switch (ch)
	{
	case ESC:
		exit(0);
	case DOWN:
		if (this->ActiveMenu < this->ActiveMenuEnd)
			this->ActiveMenu++;
		break;
	case UP:
		if (this->ActiveMenu > this->ActiveMenuStart)
			this->ActiveMenu--;
		break;
	case ENTRY:
		switch (ActiveMenu) {
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			return false;
			break;
		}
		break;
	default:
		break;
	}
	return true;
}

void Administrators::ConsoleforAdmistrators::showHeadMenuNotcofmedUsers()
{
	system("cls");
	GoToXY(1, 45);
	cout << "+------------------------------------------------+";//50
	GoToXY(2, 45);
	cout << "|";
	GoToXY(2, 52);
	this->ConsoleMenuColorText();
	cout << "Список неподтверждённых пользователей";
	this->ConsoleTextColor();
	GoToXY(2, 94);
	cout << "|";
	GoToXY(3, 45);
	cout << "+------------------------------------------------+";//50
}

void Administrators::ConsoleforAdmistrators::ConfirmedAccount(int positionAccount, const int CountAccount)
{
	if (positionAccount == -1) {
		return;
	}
	ofstream ofs("New.dat"); //создать
	ofs.close();
	ifstream oldNotConfmedUsers("NotConfirmedAccount.dat", ios::binary);
	ofstream NewNotconfirmedUsers("New.dat", ios::binary| ios::in);
	ofstream Active("AccountActivated.dat", ios::binary | ios::app);
	int type;
	int lenLogin;
	int lenPass;
	char* Login;
	char* Password;
	int flag = 1;
	while (CountAccount >= flag) {
		oldNotConfmedUsers.read((char*)&type, sizeof(int));
		oldNotConfmedUsers.read((char*)&lenLogin, sizeof(int));
		Login = new char[lenLogin];
		oldNotConfmedUsers.read((char*)Login, lenLogin);
		oldNotConfmedUsers.read((char*)&lenPass, sizeof(int));
		Password = new char[lenPass];
		oldNotConfmedUsers.read((char*)Password, lenPass);
		if (flag == positionAccount) {
			Active.write((char*)&type, sizeof(int));
			Active.write((char*)&lenLogin, sizeof(int));
			Active.write((char*)Login, lenLogin);
			Active.write((char*)&lenPass, sizeof(int));
			Active.write((char*)Password, lenPass);
		}
		else {
			NewNotconfirmedUsers.write((char*)&type, sizeof(int));
			NewNotconfirmedUsers.write((char*)&lenLogin, sizeof(int));
			NewNotconfirmedUsers.write((char*)Login, lenLogin);
			NewNotconfirmedUsers.write((char*)&lenPass, sizeof(int));
			NewNotconfirmedUsers.write((char*)Password, lenPass);
		}
		flag++;
		delete[] Password;
		delete[] Login;
	}
	oldNotConfmedUsers.close();
	NewNotconfirmedUsers.close();
	Active.close();
	remove("NotConfirmedAccount.dat");
	if (rename("New.dat", "NotConfirmedAccount.dat") != 0) {
		system("cls");
		cout << "ERROR!!!!!!" << endl;
	}

}

void Administrators::ConsoleforAdmistrators::PrintAllNotConfirmedUsers()
{
	int TypeAccount = 0;
	ifstream AccountNotConfirmed("NotConfirmedAccount.dat", ios::binary | ios::out);
	if (!AccountNotConfirmed.is_open()) {
		exit(0);
	}
	int Yposition=4;
	int CountAccount = 0;
	while (AccountNotConfirmed.read((char*)&TypeAccount, sizeof(TypeAccount)))
	{

		CountAccount++;
		ScanOneAccount(AccountNotConfirmed, CountAccount, TypeAccount);
	}
	AccountNotConfirmed.close();
	Print outline;
	outline.SetPos(&Yposition);
	int SelectFields = 0;
	this->changeEnd(3 + (int)ListWithAccountOrder.size());
	while (SelectFields==0) {
		Yposition = 4;
		showHeadMenuNotcofmedUsers();
		for (auto c = ListWithAccountOrder.begin(); c != ListWithAccountOrder.end(); c++) {
			outline(*c, ActiveMenu);
		}
		GoToXY(Yposition, 45);
		cout << "+------------------------------------------------+";//50
		SelectFields=PointerForApproveAccount();
		//////////////Вывод и выбор аккаунтов////////
		GoToXY(Yposition + 1, 47);

	}
	if (SelectFields != -1) {
		string Question = "Подтвердить данные аккаунт";
		if (ApproveYourChoice(Question, Yposition + 1, 57)) {
			ConfirmedAccount(SelectFields, (const int)ListWithAccountOrder.size());
		}
	}
	ListWithAccountOrder.clear();
	GoToXY(Yposition+5, 45);
	system("pause");
}

int Administrators::ConsoleforAdmistrators::PointerMoveForApproveYourChoice()
{
	char ch;
	ch = _getch();
	const int Yes = ActiveMenuStart;
	const int No = ActiveMenuEnd;
	if (ch == -32) ch = _getch(); // Отлавливаем стрелочки
	switch (ch)
	{
	case RIGHT:
		if (this->ActiveMenu < this->ActiveMenuEnd)
			this->ActiveMenu++;
		break;
	case LEFT:
		if (this->ActiveMenu > this->ActiveMenuStart)
			this->ActiveMenu--;
		break;
	case ENTRY:
		if (ActiveMenu == Yes) {
			return 1;
		}
		else {
			return 0;
		}
		break;
	default:
		break;
	}
	return -1;
}

void Administrators::ConsoleforAdmistrators::MenuYesOrNo(string& Question,int YPosition, int Xposition)
{
	GoToXY(YPosition, Xposition);
	ConsoleMenuColorText();
	cout << Question;
	GoToXY(YPosition+1, Xposition+5);
	if (ActiveMenu == ActiveMenuStart) {
		this->SetTextActiveColor(*this);
	}
	else this->ConsoleTextColor();
	cout << "ДА";
	GoToXY(YPosition + 1, Xposition+10);
	if (ActiveMenu == ActiveMenuEnd) {
		this->SetTextActiveColor(*this);
	}
	else this->ConsoleTextColor();
	cout << "Нет";
	this->ConsoleTextColor();
}

bool Administrators::ConsoleforAdmistrators::ApproveYourChoice(string& Question, int YPosition, int Xposition)
{
	ConsoleforAdmistrators ApproveRoutine(YPosition+1, YPosition);
	int flag = -1;
	while (flag==-1) {

		ApproveRoutine.MenuYesOrNo(Question, YPosition + 2, Xposition);
		flag = ApproveRoutine.PointerMoveForApproveYourChoice();
	}
	if (flag == 1)
		return true;
	return false;
}

void Administrators::ConsoleforAdmistrators::ScanOneAccount(ifstream& AccountNotConfirmed, int& PositionInFile, int &TypeAccount)
{
	int len = 0;
	shared_ptr<char> login2;
	char* login = NULL;
	AccountNotConfirmed.read((char*)&len, sizeof(len));
	login = new char[len];
	AccountNotConfirmed.read((char*)login, len * sizeof(char));
	login2 = (shared_ptr<char>)login;
	AccountNotConfirmed.read((char*)&len, sizeof(len));
	AccountNotConfirmed.seekg(len * sizeof(char), ios::cur);
	Account oneUser;
	oneUser.login = login2;
	oneUser.mode = TypeAccount;
	oneUser.PositionInList = PositionInFile;
	this->ListWithAccountOrder.push_back(oneUser);
	
}

int Administrators::ConsoleforAdmistrators::PointerForApproveAccount()
{
	char ch;
	ch = _getch();
	if (ch == -32) ch = _getch(); // Отлавливаем стрелочки
	switch (ch)
	{
	case ESC:
		return -1;
	case DOWN:
		if (this->ActiveMenu < this->ActiveMenuEnd)
			this->ActiveMenu++;
		break;
	case UP:
		if (this->ActiveMenu > this->ActiveMenuStart)
			this->ActiveMenu--;
		break;
	case ENTRY:
		
			return ActiveMenu - 3;
		break;
	default:
		break;
	}
	return 0;
}

char* Users::CoutString(Console& p)
{

		char c;
		int len = 1;
		char* str = new char[0];
			while ((c = _getch()) != '\r')
			{
				if ((c != 8) && (len < 15)) {

					char* temp = new char[len + 1];


					for (int i = 0; i < len - 1; i++) {
						temp[i] = str[i];
					}
					temp[len - 1] = c;
					temp[len] = '\0';
					delete[] str;
					str = temp;
					len++;
					cout << str[len-2];
				}
				else if (len != 1) {
					//c = _getch();
					char* temp = new char[len];
					for (int i = 0; i < len - 2; i++) {
						temp[i] = str[i];
					}
					temp[len - 2] = '\0';

					delete[] str;
					str = temp;
					len--;
					p.GoToXY(16, 59);
					for (int i = 0; i < len + 1; i++) {
						p.GoToXY(16, 59 + i);
						cout << " ";
					}
					p.GoToXY(16, 59);
					for (int i = 0; i < len - 1; i++) {
						cout << str[i];
					}
				}
			}
		return str;
	
}

char* Users::CoutStringPassword(Console &p)
{
	int c = 0;
	int len = 1;
	char* str = new char[0];
	while ((c = _getch()) != '\r')
	{
		if ((c != 8) && (len<15) ) {

			char* temp = new char[len + 1];
			

			for (int i = 0; i < len - 1; i++) {
				temp[i] = str[i];
			}
			temp[len - 1] = c;
			temp[len] = '\0';
			delete[] str;
			str = temp;
			len++;
			cout << "*";
		}
		else if(len!=1){
			//c = _getch();
			char* temp = new char[len];
			for (int i = 0; i < len - 2; i++) {
				temp[i] = str[i];
			}
			temp[len - 2] = '\0';

			delete[] str;
			str = temp;
			len--;
			p.GoToXY(17, 60);
			for (int i = 0; i < len + 1; i++) {
				p.GoToXY(17, 60+i);
				cout << " ";
			}
			p.GoToXY(17, 60);
			for (int i = 0; i < len - 1; i++) {
				cout << "*";
			}
		}
	}
	return str;
}

void Administrators::menuForOnlyReadInfo(Console& text)
{
	Users::menuForOnlyReadInfo(text);
}

void Administrators::showMenuAutorization(Console& p, bool flag=true)
{
	p.GoToXY(11, 51);
	cout << "ДОБРО ПОЖАЛОВАТЬ!!!";
	p.GoToXY(12, 46);
	cout << "Необходимо выполнить авторизацию";
	p.GoToXY(13, 35);
	if (flag == true)
	{
		p.GoToXY(13, 35);
		cout << "Если вы хотите зарегестрироваться, то введите в логин и пароль '0', если выйти - то '1'";
	}
	else {
		p.GoToXY(13, 46);
		cout << "Введите новый логин и пароль!";
	}
	p.GoToXY(15, 41);
	cout << "+----------------------------------------+";
	p.GoToXY(16, 41);
	cout << "|  ";
	p.ConsoleMenuColorText();
	cout << "Введите логин: ";
	p.ConsoleTextColor();
	p.GoToXY(16, 82);
	cout << "|";
	p.GoToXY(17, 41);
	cout << "|  ";
	p.ConsoleMenuColorText();
	cout << "Введите пароль: ";
	p.ConsoleTextColor();
	p.GoToXY(17, 82);
	cout << "|";
	p.GoToXY(18, 41);
	cout << "+----------------------------------------+";
}

bool Administrators::registerUsers()
{
	UsersType mode = user;
	int flag = 3;
	Console Auto(9);
	while (true) {
		system("cls");
		showMenuAutorization(Auto);
		char* login,*password;
		Auto.GoToXY(16, 59);
		login = Users::CoutString(Auto);
		Auto.GoToXY(17, 60);
		password = Users::CoutStringPassword(Auto);
		Autorization Maim;
		if (strcmp(login, password) == 0 && strcmp(login, "1") == 0) {
			Auto.GoToXY(20, 30);
			delete[] login;
			delete[] password;
			return false;
		}
		else if (strcmp(login, password) == 0 && strcmp(login, "0") == 0) {
			system("cls");
			showMenuAutorization(Auto,false);
			Auto.GoToXY(16, 59);
			login = Users::CoutString(Auto);
			Auto.GoToXY(17, 60);
			password = Users::CoutStringPassword(Auto);
			Maim.registerAccount(login, password, mode);
		}
		else if (Maim.readMainAccountFromFile(login, password)) {
			mode = admin;
			break;
		}
		else if (Maim.EnterIntoAccount(login, password,mode)) {
			break;
		}

		else {
			Auto.GoToXY(20, 30);
			cout << "Неправильно введён пароль или логин, попробуйте ещё раз. Количество попыток: " << --flag << " ." << endl;
			_getch();
			delete[] login;
			delete[] password;
		}
		 
		if (flag == 0) {
			Auto.GoToXY(21, 60);
			cout << "На это всё...." << endl;
			return false;
		}
	}
	Auto.GoToXY(20, 52);
	cout << "Приветсвуем вас!!!" << endl;
	_getch();
	system("cls");
	this->ShowMenuAcordingToMode(mode);
	system("cls");
	return true;
	
}

void Users::Console::GoToXY(short y, short x)
{
	SetConsoleCursorPosition(hStdOut, { x,y });
}

void Users::Console::ConsoleCursorVisible(bool show, short size)
{
	CONSOLE_CURSOR_INFO CursorInfo;
	CursorInfo.bVisible = show;
	CursorInfo.dwSize = size;
	SetConsoleCursorInfo(hStdOut, &CursorInfo);
}

void Users::Console::ConsoleActiveTextColor(int&& n, Console &p)
{
	if (n == this->ActiveMenu) {
		p.SetTextActiveColor(p);
		cout << "->";
	}
	else {
		p.ConsoleTextColor();
	}
}

void Users::Console::SetTextActiveColor(Console& p)
{
	SetConsoleTextAttribute(hStdOut, BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_RED  | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_INTENSITY);
}

void Users::Console::ConsoleTextColor()
{
	SetConsoleTextAttribute(hStdOut, BACKGROUND_GREEN | FOREGROUND_BLUE | BACKGROUND_INTENSITY);
}

void Users::Console::ConsoleMenuColorText()
{
	SetConsoleTextAttribute(hStdOut, BACKGROUND_GREEN | FOREGROUND_RED | FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_INTENSITY);
}

bool Users::Console::PointerMovemenuForOnlyReadInfo()
{
		char ch;
		ch = _getch();
		if (ch == -32) ch = _getch(); // Отлавливаем стрелочки
		switch (ch)
		{
		case ESC:
			exit(0);
		case DOWN:
			if (this->ActiveMenu < this->ActiveMenuEnd)
				this->ActiveMenu++;
			break;
		case UP:
			if (this->ActiveMenu > this->ActiveMenuStart)
				this->ActiveMenu--;
			break;
		case ENTRY:
			switch (ActiveMenu) {
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
			case 8:
				return false;
				break;
			}
			break;
		default:
			break;
		}
	return true;
}

int Users::Console::PointerMoveModeRegistration()
{
	char ch;
	ch = _getch();
	if (ch == -32) ch = _getch(); // Отлавливаем стрелочки
	switch (ch)
	{
	case DOWN:
		if (this->ActiveMenu < this->ActiveMenuEnd)
			this->ActiveMenu++;
		break;
	case UP:
		if (this->ActiveMenu > this->ActiveMenuStart)
			this->ActiveMenu--;
		break;
	case ENTRY:
		switch (ActiveMenu)
		{
		case 4:
			return 0;
			break;

		case 5:
			return 1;
			break;
		}
	
	default:
		break;
	}
	return -1;
}

int Users::Console::PoinetrMoveModeAdmisrator()
{
	char ch;
	ch = _getch();
	if (ch == -32) ch = _getch(); // Отлавливаем стрелочки
	switch (ch)
	{
	case DOWN:
		if (this->ActiveMenu < this->ActiveMenuEnd)
			this->ActiveMenu++;
		break;
	case UP:
		if (this->ActiveMenu > this->ActiveMenuStart)
			this->ActiveMenu--;
		break;
	case ENTRY:
		switch (ActiveMenu)
		{
		case 4:
			return 0;
			break;

		case 5:
			return 1;
			break;
		case 6:
			return 2;
			break;
		}	
	

	default:
		break;
	}
	return -1;
}

void Administrators::ShowMenuAcordingToMode(UsersType& mode)
{
	if (mode == user) {
		Console text(9);
		menuForOnlyReadInfo(text);
	}
	else {
		WorkingModeAdministrators type;
		this->estabishWorkMode(type);
		PrintMenuAccordingToModeWorking(type);
	}
}

void Users::menuForOnlyReadInfo(Console & text)
{
	valarray<string> menu = {
	"Вывести данные об всех товарах;",
	"Поиск элемента по параметру;",
	"Сортировка элементов по параметру;",
	"Вывести список товаров, хранящихся более 'x' месяцев со стоимостью более 'y' рублей",
	"Выйти из аккаунта"
	};

	text.menuShow("Меню для чтения данных", text);
	text.CinMenu(menu);
}
