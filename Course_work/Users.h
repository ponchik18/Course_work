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

	char* CoutString(Console& p);//функция ввода строки 
	char* CoutStringPassword(Console& p);//функция ввода пароля(строки)
	//void showMenuAutorization(Console& p);

	class Console {
	public:
		HANDLE hStdOut; //дискриптор консоли
		int ActiveMenu; //активная часть меню
		int ActiveMenuStart; // линия начала меню
		int ActiveMenuEnd; //линия конца меню
		Console(int amend=9, int amstart = 4) {
			hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);// Получаем дескриптор консоли
			this->ActiveMenu = this->ActiveMenuStart=amstart;
			this->ActiveMenuEnd = amend;
			ConsoleCursorVisible(false, 10);
			} 
		void changeEnd(int amend){ this->ActiveMenuEnd = amend; }
		void CinMenu(valarray<string>& menu); //вывод параметров меню
		void CinMenuAutorization(valarray<string>& menu);
		void GoToXY(short y, short x=40); //перемещение курсора
		void ConsoleCursorVisible(bool show, short size);// изменяем размер и видимость курсора
		void ConsoleActiveTextColor(int&& n, Console& p);// меняем цвет текста строки, что m = n
		void SetTextActiveColor(Console& p);//ставим цвет активного поля меню
		void ConsoleTextColor();// меняем цвет обычного текста
		void ConsoleMenuColorText();//меняем цвет меню
		bool PointerMovemenuForOnlyReadInfo();// метод для отслеживания нажатия клавиши
		int PointerMoveModeRegistration();
		int PoinetrMoveModeAdmisrator();
		void menuShow(string menuName, Console& text); //в функцию передаётся строка, которая будет отражаться на панели меню

		

	};

	
public:

	void showInfoAboutProduct(Product* pd) const;//вывод информации об товарах
	void cinInfoAboutProduct(Product* pd); //ввод информации об товаре
	void searchProductByFields(Product* pd) const;// поиск товора(-ов) по полю
	void SortProductByFields(Product* ps);// сортировка данных 
	void menuForOnlyReadInfo(Console& text);// меню для работы только с ознакомлкение данных
//	void registerUsers();//региструем пользователя
	friend class Autorization;
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
	class ConsoleforAdmistrators : public Console {
	public:
		ConsoleforAdmistrators(int amend = 9, int amstart = 4): Console(amend, amstart){}
		bool PointerMovemenuWorkingWithAccount();// метод для отслеживания нажатия клавиши
		bool PointerMovemenuWorkingWithChangingFields();// метод для отслеживания нажатия клавиши
		void NotConfirmedAccount();
		void showNotConfimedUsers();
		void showHeadMenuNotcofmedUsers();
		void PrintAllNotConfirmedUsers();
		class Account {
		public:
			int mode;
			shared_ptr<char> login;
			int PositionInList;
		};
		list<Account> ListWithAccountOrder;
		void ConfirmedAccount(int positionAccount, const int CountAccount);
		void ScanOneAccount(ifstream& AccountNotConfirmed, int& PositionInFile, int& TypeAccount);

		class Print {
		public:
			int* Yposition;
			void operator()(Account& Element, int ActiveField) {
				ConsoleforAdmistrators text;
				text.GoToXY(*Yposition, 45);
				cout << "|";
				text.GoToXY(*Yposition, 47);
				if (*Yposition == ActiveField) {
					text.SetTextActiveColor(text);
				}
				if (Element.mode == 0) {
					cout << "Пользователь";
				}
				else cout << "Администратор";
				text.GoToXY(*Yposition, 75);
				cout << Element.login << endl;
				text.GoToXY(*Yposition, 94);
				text.ConsoleTextColor();
				cout << "|";
				(*Yposition)+=1;
			}

			void SetPos(int* Pos) { this->Yposition = Pos; }
		};
		int PointerForApproveAccount();
		bool ApproveYourChoice(string& Question, int YPosition, int Xposition);
		int PointerMoveForApproveYourChoice();
		void MenuYesOrNo(string& Question, int YPosition, int Xposition);
		
	};
	//void establishMenuForWorkingMode(Product* ps);// администратор выбирает режим доступа и затем вызывается метод с соответсвенным меню режима
public:
	void showMenuAutorization(Console& p, bool flag);// вызывет метод вызова меню для пользователя
	void menuForOnlyReadInfo(Console& text);// меню для работы только с ознакомлкение данных
	bool registerUsers();//региструем пользователя
	void ShowMenuAcordingToMode(UsersType& mode);
	void SortProductByFields(Product* ps);// сортировка данных 
	void showInfoAboutProduct() const; //вывод информации об товарах
	void cinInfoAboutProduct(Product* pd); //ввод информации об товаре
	void searchProductByFields(Product* pd) const;// поиск товора(-ов) по полю
	void changeProductFields(Product* pd);//изменения информации об товаре
	void estabishWorkMode(WorkingModeAdministrators & type);//определение режима работы
	void PrintMenuAccordingToModeWorking(WorkingModeAdministrators type);
	void establishMenuForWorkingMode();// администратор выбирает режим доступа и затем вызывается метод с соответсвенным меню режима
	void menuForWorkingWithAccount();//меню для работы с аккаунтами
	void menuForWorkingWithCnangeFields();//меню для работы с редактировние данных
	void menuWorkingWithAccount(Console& text);
	void menuWorkingWithChangingFields(Console& text);
};

