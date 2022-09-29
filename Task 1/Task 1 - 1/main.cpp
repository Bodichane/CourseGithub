#include<iostream>
#include<cmath>

using namespace std;

/**
*\brief Функция расчёта по заданной формуле .
*\param x Аргумент функции .
*\param y Аргумент функции .
*\param z Аргумент функции .
*\return Значение функции .
*/

const double getA(double x, double y, double z);

/**
*\brief Функция расчёта по заданной формуле .
*\param x Аргумент функции .
*\param y Аргумент функции .
*\param z Аргумент функции .
*\return Значение функции .
*/

const double getB(double x, double y, double z);

/**
*\brief Точка входа в программу
\return Возвращает 0 случае успеха
*/

int main()
{
	const double x = -2.9;
	const double y = 15.5;
	const double z = 1.5;

	cout << " x = " << x << " y = " << y << " z = " << z << endl;

	const auto a = getA(x, y, z);
	const auto b = getB(x, y, z);
	cout << " a = " << a << " b = " << b << endl;

	return 0;
}

const double getA(double x, double y, double z)
{
	return sqrt((x * x) + y) - (y * y) * sin((x + z) / x) * sin((x + z) / x) * sin((x + z) / x);
}

const double getB(double x, double y, double z)
{
	return cos(x * x * x) * cos(x * x * x) - x / ((z * z) + (y * y));
}
