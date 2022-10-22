

#include <iostream>
#include <string>

using namespace std;

/**
* \brief Считать ток и напряжение.
* \param message Сообщение пользователю.
* \return значение ток и напряжение.
*/

double getValue(const string& message);

/**
* \brief Расчет работы в электродвигателе вентилятора.
* \param I Тока в электродвигателе вентилятора.
* \param U Напряжение в электродвигателе вентилятора.
* \return Значение работы в электродвигателе вентилятора
*/

double getWork(const double I, const double U);

/**
* \brief Точка входа в программу
* \return Возвращает 0 случае успеха
*/


int main()
{
    try
    {
        const double I = getValue("Введите значение тока I = ");
        const double U = getValue("Введите значение напряжение U = ");
        const double W = getWork(I, U);

        cout << "\nРабота в электродвигателе вентилятора = " << W << " Дж";
    }
    catch (out_of_range e)
    {
        cout << e.what();
        return 1;
    }

    return 0;
}

double getValue(const string& message)
{
    cout << message;
    double value = 0.0;
    cin >> value;

    if (value <= 0)
    {
        throw out_of_range("неправильная значение!");
    }

    return value;
}

double getWork(const double I, const double U)
{
    const double t = 1200;
    return I * U * t;
}
