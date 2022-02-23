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

void Users::CinMenu(string* menu, int lengh, Console &p)
{

	for (int i = 0; i < lengh; i++) {
		p.GoToXY(p.ActiveMenuStart+i);
		cout << *menu << endl;
		menu++;
	}
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
	Console text(9);
	Users::menuShow("Меню для чтения данных", text);
	string menu[5] = {
		"Чтение информации о товаре с файла;",
		"Вывести данные об всех товарах;",
		"Поиск элемента по параметру;",
		"Сортировка элементов по параметру;",
		"Вывести список товаров, хранящихся более 'x' месяцев со стоимостью более 'y' рублей",
	};
	CinMenu(menu, 5, text);

}



void Users::Console::GoToXY(short y, short x)
{
	SetConsoleCursorPosition(hStdOut, { x,y });
}

void Users::Console::ConsoleTextColor()
{
	SetConsoleTextAttribute(hStdOut, BACKGROUND_GREEN | FOREGROUND_BLUE | BACKGROUND_INTENSITY);
}

void Users::Console::ConsoleMenuColorText()
{
	SetConsoleTextAttribute(hStdOut, BACKGROUND_GREEN | FOREGROUND_RED | FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_INTENSITY);
}

void Users::Console::PointerMove(Console& p)
{
		char ch;
		ch = _getch();
		if (ch == -32) ch = _getch(); // Отлавливаем стрелочки
		switch (ch)
		{
		case ESC:
			exit(0);
		case DOWN:
			if (p.ActiveMenu < p.ActiveMenuEnd)
				p.ActiveMenu++;
			break;
		case UP:
			if (p.ActiveMenu > p.ActiveMenuStart)
				p.ActiveMenu--;
			break;
		case ENTRY:
			/*switch (p.ActiveMenu) {
				
			}
			break;*/
		default:
			break;
		}
}

