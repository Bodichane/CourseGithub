#include<iostream>
#include<cmath>
#include<limits>
#include<iomanip>

using namespace std;

/**
* \brief Существует ли функция в точке х.
* \param x Аргумент функции.
* \ return true,  если существует.
*/

bool isExists(const double x);

/**
* \brief Расчёт функции в  точке х.
* \param x Аргумент функции.
* \return Значение функции в точке х.
*/

double getY(const double x);

/**
* \brief Точка входа в программу в  точке х.
* \return Возвращает 0 случае успеха
*/

int main()
{
	const double xStart = 1;
	const double xFinish = 2;
	const double step = 0.1;
	double x = xStart;

	cout << setw(10) << " x " << " " << " y " << "\n";

	while (x <= xFinish)
	{
		if (isExists(x))
		{
			const double y = getY(x);
			cout << setw(10) << x << " " << y << "\n";
		}
		else
		{
			cout << setw(10) << x << " " << "Нет решения \n";
		}

		x += step;
	}

	return 0;
}

bool isExists(const double x)
{
	return abs(x) > numeric_limits<double>::min();
}

double getY(const double x)
{
	return  cos(2 / x) - 2 * sin(1 / x) + 1 / x;
}