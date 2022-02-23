#pragma once
#include"library.h"
class Product //Класс товар на складе
{
private:
	std::string productName; //название товара 
	struct dataOfArrival { //структура для хранения данных о дате прибытия товара на склад
		int day; //день прибытия
		int month; //месяц прибытия
		int year; //год прибытия
	};
	int count; //количество едениц товара на складе
	float priseForOneCount; //цена за еденицу товара
	struct PeopleThatAcceptedProduct { //человек, который принял товар(его ФИО)
		std::string LastName;//фамилия
		std::string FirstName;//имя
		std::string SurName;//отчество
	};
public:
	Product();
	void coutInfoAboutOneProduct() const; //вывод информации об одном продукте(классе)
	void readInfoAboutOneProductFromFile();//чтение с файла одного продукта(класса)
	void writeInfoAboutOneProductFromFile();//запись данных об одном продукте(классе) в файл
	void cinInfoAboutOneProduct();//ввод данных об одном продукте в консоль
	~Product();
	
	//friend void Users::SortProductByProductName(Product* pd);//дружелюбный метод будет(сортировка по наименованию)
	//friend void Users::SortProductByProductData(Product* pd);//дружелюбный метод будет(сортировка по дате)
	//friend void Users::SortProductByProductPrise(Product* pd);//дружелюбный метод будет(сортировка по цене)
	friend class Users;
	friend class Administrators;
};

