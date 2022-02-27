#pragma once
#include"library.h"
#include"Product.h"
#include"Autorization.h"
//Создание классов и прототипов методов, реализация методов вынесена в файл <Users.cpp>

class Users // базовый класс 
{
	
protected:
	class Console;
	void SortProductByProductName(Product* pd);//сортировка по наименованию
	void SortProductByProductData(Product* pd);//сортировка по дате
	void SortProductByProductPrise(Product* pd);//сортировка по цене
	void CinMenu(valarray<string> &menu, Console& p); //вывод параметров меню
	char* CoutString(Console& p);//функция ввода строки 
	char* CoutStringPassword(Console& p);//функция ввода пароля(строки)
	//void showMenuAutorization(Console& p);

	class Console {
	public:
		HANDLE hStdOut; //дискриптор консоли
		int ActiveMenu; //активная часть меню
		int ActiveMenuStart; // линия начала меню
		int ActiveMenuEnd; //линия конца меню
		Console(int amend, int amstart = 4) {
			hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);// Получаем дескриптор консоли
			this->ActiveMenu = this->ActiveMenuStart=amstart;
			this->ActiveMenuEnd = amend;
			ConsoleCursorVisible(false, 10);
			} 
		void GoToXY(short y, short x=40); //перемещение курсора
		void ConsoleCursorVisible(bool show, short size);// изменяем размер и видимость курсора
		void ConsoleActiveTextColor(int&& n, Console& p);// меняем цвет текста строки, что m = n
		void SetTextActiveColor(Console& p);//ставим цвет активного поля меню
		void ConsoleTextColor();// меняем цвет обычного текста
		void ConsoleMenuColorText();//меняем цвет меню
		void PointerMove();// метод для отслеживания нажатия клавиши
		
		void menuShow(string menuName, Console& text); //в функцию передаётся строка, которая будет отражаться на панели меню
	};

	
public:

	void showInfoAboutProduct(Product* pd) const;//вывод информации об товарах
	void cinInfoAboutProduct(Product* pd); //ввод информации об товаре
	void searchProductByFields(Product* pd) const;// поиск товора(-ов) по полю
	void SortProductByFields(Product* ps);// сортировка данных 
//	void menuForOnlyReadInfo();// меню для работы только с ознакомлкение данных
//	void registerUsers();//региструем пользователя

};

///////////////////////////////



////////////////////////////////

class Administrators : public Users { //класс администратор, который наследуеться от класс Users с модификатором доступа private
private:
	enum WorkingModeAdministrators //перичеление сделано для удобства видимости режима работы 
	{
		WorkWithAccount = 1, //работа с аккаунтами
		WorkWithChangeFields, //работа с редактирование полей 
		WorkWithOnlyReadInfo // работа только с просмотром полей
	};
	//void establishMenuForWorkingMode(Product* ps);// администратор выбирает режим доступа и затем вызывается метод с соответсвенным меню режима
public:
	void showMenuAutorization(Console& p);// вызывет метод вызова меню для пользователя
	void menuForOnlyReadInfo();// меню для работы только с ознакомлкение данных
	void registerUsers();//региструем пользователя

	void SortProductByFields(Product* ps);// сортировка данных 
	void showInfoAboutProduct() const; //вывод информации об товарах
	void cinInfoAboutProduct(Product* pd); //ввод информации об товаре
	void searchProductByFields(Product* pd) const;// поиск товора(-ов) по полю
	void changeProductFields(Product* pd);//изменения информации об товаре
	void estabishWorkMode();//определение режима работы
	void establishMenuForWorkingMode();// администратор выбирает режим доступа и затем вызывается метод с соответсвенным меню режима
	void menuForWorkingWithAccount();//меню для работы с аккаунтами
	void menuForWorkingWithCnangeFields();//меню для работы с редактировние данных

};

