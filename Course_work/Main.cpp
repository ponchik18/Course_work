#include"Users.h"
#include"Product.h"
using namespace std;
int main() {
	setlocale(0, "Rus");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	system("mode con cols=134 lines=40");
	system("color A1");
	Users ts;
	ts.menuForOnlyReadInfo();

	
	return 0;
}

//1)начать реализацию авторизации
//2)начать реализацию логики программы
//3)написать методы для класса Product
