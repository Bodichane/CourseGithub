#include<iostream>

using namespace std;

/**
*\brief Функция расчёта по заданной формуле.
*\param p Вес.
*\return Новый вес.
*/
double getP(const double p);

/**
*\brief Точка входа в программу.
*\return Возвращает 0 случае успеха.
*/

int main()
{
        const double p;
	cout << "Введите значение веса = "; cin >> p;
	
	const double q = getP(p);	
	cout << "Beca = " << p <<" г" << endl;
	cout << "Новая веса = " << q << " унции" << endl;

	return 0;
}

double getP(const double p)
{
   const double s = 28.3;
   return p / s;
}
