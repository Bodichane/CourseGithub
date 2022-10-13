#include<iostream>
#include<cmath>

using namespace std;

/**
* \brief Считать количество членов последовательности.
* \param message Сообщение пользователю.
* \return Количество членов последовательности.
*/

size_t getCount(const string& message);

/**
* \brief Рассчитывает сумму последовательности.
* \param count Количество членов последовательности.
* \return Сумма последовательности.
*/

double getSum(const size_t count);

/**
* \brief Рассчитывает рекуррентный член последовательности.
* \param k Количество членов последовательности.
* \return Значение рекуррентного член последовательности.
*/

double getRecurrent(const size_t k);

/**
* \brief Точка входа в программу
* \return Возвращает 0 случае успеха
*/

int main()
{
    try
    {
        const auto count = getCount("Введите количество членов последовательности = ");
	const auto sum = getSum(count);
	cout << " " << sum << "\n";
    }
    catch (out_of_range&)
	{
		cout << "неправильная cторона!";
		return 1;
	}
	

	return 0;
}

size_t getCount(const string& message)
{
	cout << message;
	int count;
	cin >> count;
	
	if (count <= 0)
	{
		throw out_of_range("неправильная cторона!");
	}
	
	return count;
}

double getSum(const size_t count)
{
	double current = 1;
	double sum = current;

	for (size_t k = 2; k <= count; k++)
	{
		current *= getRecurrent(k);
		sum += current;
	}

	return sum;
}

double getRecurrent(const size_t k)
{
	return (k + 1) * (k + 1) * (k + 1) / pow(k, 4);
}
