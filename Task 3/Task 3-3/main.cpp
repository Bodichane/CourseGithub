#include <iostream>
#include<cmath>
#include<limits>
#include<iomanip>

using namespace std;

/**
* \brief Расчёт функции в  точке х.
* \param x Аргумент функции.
* \return Значение функции в точке х.
*/

double getY(const double x);

/**
* \brief Расчёт сумма в  точке х.
* \param x Аргумент сумма.
* \param epsilon Погрешность вычислений.
* \return Значение сумма в точке х.
*/

double getSum(const double x, const double epsilon);

/**
* \brief Рассчитывает рекуррентный член последовательности.
* \param n Количество членов последовательности.
* \return Значение рекуррентного член последовательности.
*/

double getRecurrent(const double x);

/**
 * \brief Форматный вывод в поток вывода out (по умолчанию std::cout).
 * \param argument Аргумент табулируемой функции.
 * \param function Значение табулируемой функции.
 * \param series Аппроксимация табулируемой функции.
 * \param out Поток вывода, в который будет осуществлен форматный вывод.
 */
 
void FormatOutput(const double argument, const double function, const double sum, ostream& out = cout);

/**
* \brief Точка входа в программу в  точке х.
* \return Возвращает 0 случае успеха
*/

int main()
{
	const double xStart = 0.1;
	const double xFinish = 0.8;
	const double epsilon = 0.0003;
	const double step = 0.01;
	
    double x = xStart;
	while (x <= xFinish + epsilon)
	{
		const double y = getY(x);
		const double sum = getSum(x, epsilon);
	
	        FormatOutput(x, y, sum);

		x += step;
	}

	return 0;
}

double getY(const double x)
{
	return 1.0 / 4 * log(1 + x / 1 - x) + 1.0 / 2 * atan(x);
}

double getSum(const double x, const double epsilon)
{
	auto previous = 0.0;
    auto current = 1.0;
    auto sum = current;

    do
    {
        previous = current;
        current = previous * getRecurrent(x);
        sum += current;
    } while (abs(previous - current) >= epsilon);

    return sum;
}

double getRecurrent(const double x)
{
    return pow(5, x) / 5;
}

void FormatOutput(const double argument, const double function, const double sum, ostream& out)
{
    out << setw(10) << argument << " | "
        << setw(15) << function << " | "
        << setw(15) << sum << "\n";
}
