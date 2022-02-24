#include "Users.h"
#include"library.h"
void Administrators::establishMenuForWorkingMode()
{
	system("color 2f");
	std::string menu[4] = {
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


void Users::menuShow(string menuName, Console & text)
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

void Users::menuForOnlyReadInfo()
{

	valarray<string> menu = {
	"Чтение информации о товаре с файла;",
	"Вывести данные об всех товарах;",
	"Поиск элемента по параметру;",
	"Сортировка элементов по параметру;",
	"Вывести список товаров, хранящихся более 'x' месяцев со стоимостью более 'y' рублей",
	};
	
	Console text(menu.size()+4-1);
	while (true) {
		Users::menuShow("Меню для чтения данных", text);
		CinMenu(menu, text);
		text.PointerMove();
		system("cls");
	}
}



void Users::Console::GoToXY(short y, short x)
{
	SetConsoleCursorPosition(hStdOut, { x,y });
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

