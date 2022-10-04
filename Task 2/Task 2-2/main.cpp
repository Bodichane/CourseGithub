#include<iostream>
#include<cmath>

using namespace std;

/**
*\brief Функция расчёт значений для аргумента меньше, чем пороговое значение.
*\param x Аргумент функции.
*\param a Константное значение.
*\return Значение функции в точке \a x.
*/

double getFunction1(const double x, const double a);

/**
*\brief Функция расчёт значений для аргумента больше или равно пороговому значению.
*\param x Аргумент функции.
*\param a Константное значение.
*\return Значение функции в точке \a x.
*/

double getFunction2(const double x, const double a);

/**
*\brief Точка входа в программу.
\return Возвращает 0 случае успеха.
*/

int main()
{
    cout << "Введите значение x = ";
    double x = 0.0;
    cin >> x;

    const double THRESHOLD = 2;
    const double a = 2.3;

    if (x < THRESHOLD)
    {
        const double y = getFunction1(x, a);
        cout << "y = " << y;
    }
    else
    {
        const double y = getFunction2(x, a);
        cout << "y = " << y;
    }

    return 0;
}

double getFunction1(const double x, const double a)
{
    return 1.5 * cos(x) * cos(x);
}

double getFunction2(const double x, const double a)
{
    return (x - 2) * (x - 2) + 6;
}