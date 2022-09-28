#include<iostream>

using namespace std;

/**
*\brief Точка входа в программу
*\param weight
*\param Nweight
*\return Возвращает 0 случае успеха
*/

int main()
{
	double weight;
	double Nweight;

	cout << "Введите значение веса = ";
	cin >> weight;
	
	Nweight = weight / 28.3;

	cout << "Beca = " << weight <<" г" << endl;
	cout << "Новая веса = " << Nweight << " унции" << endl;

	return 0;
}