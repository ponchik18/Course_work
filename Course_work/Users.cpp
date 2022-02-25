#include "Users.h"
#include"library.h"
void Administrators::establishMenuForWorkingMode()
{
	system("color 2f");
	std::string menuRegist[4] = {
	"Работа с учётными записями",
	"Paбота с редактирование полей",
	"Работа только с простмотром данных"
	};

}

void Users::CinMenu(valarray<string>& menu, Console &p)
{
	cout << "|";
	p.GoToXY(p.ActiveMenuStart-1,133);
	cout << "|";
	for (int i = 0; i < menu.size(); i++) {
		cout << "|";
		p.GoToXY(p.ActiveMenuStart+i);
		
		p.ConsoleActiveTextColor(p.ActiveMenuStart + i, p);
		cout << menu[i] << endl;
		p.ConsoleTextColor();//ставим значение цвета по умолчанию
		p.GoToXY(p.ActiveMenuStart + i,133);
		cout << "|"<<endl;
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

char* Users::CoutString()
{

		char c;
		int len = 1;
		char* str = new char[0];
		while ((c = cin.get()) != '\n')
		{
			char* temp = new char[len + 1];

			for (int i = 0; i < len - 1; i++) {
				temp[i] = str[i];
			}
			temp[len - 1] = c;
			temp[len] = '\0';
			delete[] str;
			str = temp;
			len++;
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
		if (c != 8) {
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

void Users::menuForOnlyReadInfo()
{
	registerUsers();
	valarray<string> menu = {
	"Чтение информации о товаре с файла;",
	"Вывести данные об всех товарах;",
	"Поиск элемента по параметру;",
	"Сортировка элементов по параметру;",
	"Вывести список товаров, хранящихся более 'x' месяцев со стоимостью более 'y' рублей",
	"Выйти из аккаунта"
	};

	Console text(menu.size() + 4 - 1);
	while (true) {
		text.menuShow("Меню для чтения данных", text);
		CinMenu(menu, text);
		text.PointerMove();
		system("cls");
	}
}

void Users::showMenuAutorization(Console& p)
{
	p.GoToXY(12, 51);
	cout << "ДОБРО ПОЖАЛОВАТЬ!!!";
	p.GoToXY(13, 46);
	cout << "Необходимо выполнить авторизацию";
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



void Users::registerUsers()
{
	int flag = 3;
	Console Auto(9);
	while (true) {
		system("cls");
		showMenuAutorization(Auto);
		char* login,*password;
		Auto.GoToXY(16, 59);
		login = Users::CoutString();
		Auto.GoToXY(17, 60);
		password = Users::CoutStringPassword(Auto);
		Autorization Maim;
		if (!Maim.readMainAccountFromFile(login, password)) {
			Auto.GoToXY(20, 30);
			cout << "Неправильно введён пароль или логин, попробуйте ещё раз. Количество попыток: " << --flag << " ." << endl;
			_getch();
			delete[] login;
			delete[] password;
		}
		else
			break;
		if (flag == 0) {
			Auto.GoToXY(21, 60);
			cout << "На это всё...." << endl;
			exit(0);
		}
	}
	Auto.GoToXY(20, 52);
	cout << "Приветсвуем вас!!!" << endl;
	_getch();
	system("cls");
	
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

void Users::Console::PointerMove()
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
			/*switch (p.ActiveMenu) {
				
			}
			break;*/
		default:
			break;
		}
}

