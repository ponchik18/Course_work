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

//1)������ ���������� �����������
//2)������ ���������� ������ ���������
//3)�������� ������ ��� ������ Product
//4)�������� �� UTF-8 ���������� � ���������� �� GitHub
// ����� �� ��������� ������ ����� "MaksBovkun2003"
// ������ "asdf1234"

//int c = 0;
//std::string pwd;
//std::cout << "Enter password: ";
//
//while (true)
//{
//    c = getch();
//    if (c == 0)
//        c = getch();
//    if (c == '\r' || c == '\n')
//        break;
//    cout << '*';
//    pwd += c;
//}
//
//std::cout << "\nYou entered: " << pwd.c_str();
//return 0;
