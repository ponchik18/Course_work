#pragma once
#include"Product.h"
#include<Windows.h>

//Создание классов и прототипов методов, реализация методов вынесена в файл <Users.cpp>

class Users // базовый класс 
{

protected:
	void SortProductByProductName(Product* pd);//сортировка по наименованию
	void SortProductByProductData(Product* pd);//сортировка по дате
	void SortProductByProductPrise(Product* pd);//сортировка по цене
	class Console {
	public:
		HANDLE hStdOut; //дискриптор консоли
		Console() {hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);} // Получаем дескриптор консоли
		void GoToXY(short y, short x); //перемещение курсора
		void ConsoleCursorVisible(bool show, short size);// изменяем размер и видимость курсора
		void ConsoleTextColor(int& n, int &am);// меняем цвет текста строки, что m=n

	};
public:
	void showInfoAboutProduct(Product* pd) const;//вывод информации об товарах
	void cinInfoAboutProduct(Product* pd); //ввод информации об товаре
	void searchProductByFields(Product* pd) const;// поиск товора(-ов) по полю
	void SortProductByFields(Product* ps);// сортировка данных 
	void menuForOnlyReadInfo();// меню для работы только с ознакомлкение данных

	friend class Product;
};

///////////////////////////////



////////////////////////////////

class Administrators : public Users { //класс администратор, который наследуеться от класс Users с модификатором доступа private
private:
	enum WorkingMode //перичеление сделано для удобства видимости режима работы 
	{
		WorkWithAccount = 1, //работа с аккаунтами
		WorkWithChangeFields, //работа с редактирование полей 
		WorkWithOnlyReadInfo // работа только с просмотром полей
	};
	void establishMenuForWorkingMode(Product* ps);// администратор выбирает режим доступа и затем вызывается метод с соответсвенным меню режима
public:
	
	void SortProductByFields(Product* ps);// сортировка данных 
	void showInfoAboutProduct() const; //вывод информации об товарах
	void cinInfoAboutProduct(Product* pd); //ввод информации об товаре
	void searchProductByFields(Product* pd) const;// поиск товора(-ов) по полю
	void changeProductFields(Product* pd);//изменения информации об товаре
	void estabishWorkMode();//определение режима работы
	void establishMenuForWorkingMode();// администратор выбирает режим доступа и затем вызывается метод с соответсвенным меню режима
	void menuForOnlyReadInfo();// меню для работы только с ознакомлкение данных
	void menuForWorkingWithAccount();//меню для работы с аккаунтами
	void menuForWorkingWithCnangeFields();//меню для работы с редактировние данных

};

