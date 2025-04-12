#include<iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	int a = 2;
	int* pa = &a;
	cout << a << endl;			// вывод переменной "а" на экран
	cout << &a << endl;			// взятие адреса переменной "а" прямо при выводе
	cout << pa << endl;			// вывод адреса переменной "а", хранящегося в указателе "ра"
	cout << *pa << endl;
}