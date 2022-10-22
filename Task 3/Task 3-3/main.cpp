#include <iostream>
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

double getFunction(const double x);

/**
* \brief Расчёт сумма в  точке х.
* \param x Аргумент сумма.
* \return Значение сумма в точке х.
*/

double getSum(const double x);

/**
* \brief Точка входа в программу в  точке х.
* \return Возвращает 0 случае успеха
*/

int main()
{
	const double xStart = 0.1;
	const double xFinish = 0.8;
	const double step = 0.0003;
	double x = xStart;

	cout << setw(10) << " x " << " " << " Function " << " " << "Sum" << "\n";

	while (x <= xFinish)
	{
		if (isExists(x))
		{
			const double function = getFunction(x);
			const double sum = getSum(x);
			cout << setw(10) << x << " " << function << " " << sum << "\n";
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
	return abs(1 - x) > numeric_limits<double>::min() && (x > 1);
}

double getFunction(const double x)
{
	return 1 / 4 * log(1 + x / 1 - x) + 1 / 2 * atan(x);
}

double getSum(const double x)
{
	const int n;
	return n / 2 * ((pow(x, 4 * n + 1) / 4 * n + 1) + x);
}
/**/