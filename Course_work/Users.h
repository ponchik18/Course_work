#pragma once
#include"library.h"
//—оздание классов и прототипов методов, реализаци€ методов вынесена в файл <Users.cpp>

class Users // базовый класс 
{
	
protected:
	class Console;
	void SortProductByProductName(Product* pd);//сортировка по наименованию
	void SortProductByProductData(Product* pd);//сортировка по дате
	void SortProductByProductPrise(Product* pd);//сортировка по цене
	void CinMenu(valarray<string> &menu, Console& p); //вывод параметров меню
	class Console {
	public:
		HANDLE hStdOut; //дискриптор консоли
		int ActiveMenu; //активна€ часть меню
		int ActiveMenuStart; // лини€ начала меню
		int ActiveMenuEnd; //лини€ конца меню
		Console(int amend, int amstart = 4) {
			hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);// ѕолучаем дескриптор консоли
			this->ActiveMenu = this->ActiveMenuStart=amstart;
			this->ActiveMenuEnd = amend;
			} 
		void GoToXY(short y, short x=40); //перемещение курсора
		void ConsoleCursorVisible(bool show, short size);// измен€ем размер и видимость курсора
		void ConsoleActiveTextColor(int&& n, Console& p);// мен€ем цвет текста строки, что m = n
		void SetTextActiveColor(Console& p);//ставим цвет активного пол€ меню
		void ConsoleTextColor();// мен€ем цвет обычного текста
		void ConsoleMenuColorText();//мен€ем цвет меню
		void PointerMove();// метод дл€ отслеживани€ нажати€ клавиши
		
		//void menuShow(string menuName); //в функцию передаЄтс€ строка, котора€ будет отражатьс€ на панели меню
	};
public:
	void menuShow(string menuName, Console& text); //в функцию передаЄтс€ строка, котора€ будет отражатьс€ на панели меню

	void showInfoAboutProduct(Product* pd) const;//вывод информации об товарах
	void cinInfoAboutProduct(Product* pd); //ввод информации об товаре
	void searchProductByFields(Product* pd) const;// поиск товора(-ов) по полю
	void SortProductByFields(Product* ps);// сортировка данных 
	void menuForOnlyReadInfo();// меню дл€ работы только с ознакомлкение данных

	friend class Product;
};

///////////////////////////////



////////////////////////////////

class Administrators : public Users { //класс администратор, который наследуетьс€ от класс Users с модификатором доступа private
private:
	enum WorkingMode //перичеление сделано дл€ удобства видимости режима работы 
	{
		WorkWithAccount = 1, //работа с аккаунтами
		WorkWithChangeFields, //работа с редактирование полей 
		WorkWithOnlyReadInfo // работа только с просмотром полей
	};
	void establishMenuForWorkingMode(Product* ps);// администратор выбирает режим доступа и затем вызываетс€ метод с соответсвенным меню режима
public:
	
	void SortProductByFields(Product* ps);// сортировка данных 
	void showInfoAboutProduct() const; //вывод информации об товарах
	void cinInfoAboutProduct(Product* pd); //ввод информации об товаре
	void searchProductByFields(Product* pd) const;// поиск товора(-ов) по полю
	void changeProductFields(Product* pd);//изменени€ информации об товаре
	void estabishWorkMode();//определение режима работы
	void establishMenuForWorkingMode();// администратор выбирает режим доступа и затем вызываетс€ метод с соответсвенным меню режима
	void menuForOnlyReadInfo();// меню дл€ работы только с ознакомлкение данных
	void menuForWorkingWithAccount();//меню дл€ работы с аккаунтами
	void menuForWorkingWithCnangeFields();//меню дл€ работы с редактировние данных

};

