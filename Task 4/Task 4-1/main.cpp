#include<iostream>
#include <random>
#include<string>
#include<algorithm>

using namespace std;

/**
* \brief Считать размер массива.
* \param message Побуждающее сообщение для пользователя.
* \return размер массива.
*/
size_t getSize(const string& message);

/**
* \brief Считывает значения элементов массива клавиатуры.
* \param size Длина массива.
* \return Массив.
*/
int* getManualInputArray(const size_t size);

/**
* \brief Заполнение массива случайными числами.
* \param size Длина массива.
* \param minValue Минимальное значение массива.
* \param maxValue максимальное значение массива.
* \return Массив.
*/
int* getRandomInputArray(const size_t size, const int minValue = -100, const int maxValue = 100);

/**
* \brief Печатает массив.
* \param array Массив.
* \param size Длина массива.
* \param out Поток вывода.
*/
void print(int* array, const size_t size, ostream& out = cout);

/**
* \brief Меняет последние к элементов массива на противоположные по знаку.
* \param array Массив.
* \param size Длина массива.
* \param k Количество элементов для замены
*/
void exhcangeLastKElementByOpposite(int* array, const size_t size, size_t k);

/**
* \brief Вывести индексы тех элементов, значения которых кратны 3.
* \param array Массив.
* \param size Длина массива.
* \return индексы.
*/
void showIndex(int* array, const size_t size);

/**
* \brief Найти пару элементов из массива, сумма которых равна заданному числу.
* \param array Массив.
* \param size Длина массива.
* \return Пара элементов из массива.
*/
void getPairElements(int* array, size_t size);

enum class arrayInputChoice
{
	MANUAL = 1,
	RANDOM
};

/**
* \brief Точка входа в программу в  точке х.
* \return Возвращает 0 случае успеха
*/

int main()
{
	try
	{
		const auto size = getSize("Введите размер массива = ");
		int* myArray = nullptr;

		cout << "\nВведите требуемое действие.\n"
			<< static_cast<int>(arrayInputChoice::MANUAL) << " - Для ручного ввода массива "
			<< static_cast<int>(arrayInputChoice::RANDOM) << " - Для произвольного ввода массива\n";

		int input = 0;
		cin >> input;
		const auto choice = static_cast<arrayInputChoice>(input);

		switch (choice)
		{
		case arrayInputChoice::MANUAL:
		{
			myArray = getManualInputArray(size);
			break;
		}
		case arrayInputChoice::RANDOM:
		{
			myArray = getRandomInputArray(size);
			break;
		}
		default:
			cerr << "Вы ввели некорректное действие!";
			return 1;
		}

		const auto k = getSize("\n\nВведите значение k = ");
		exhcangeLastKElementByOpposite(myArray, size, k);
		cout << "Меняет последние к элементов массива на противоположные по знаку.\n";
		print(myArray, size);
		showIndex(myArray, size);
		getPairElements(myArray, size);

		if (myArray != nullptr)
		{
			delete[] myArray;
			myArray = nullptr;
		}
	}
	catch (exception& e)
	{
		cerr << e.what();
		return 1;
	}

	return 0;
}

size_t getSize(const string& message)
{
	cout << message;
	const int TRESHOLD = 1;
	int size = TRESHOLD;
	cin >> size;

	if (size < 1)
	{
		throw out_of_range("Введён неправильный размер массива!");
	}

	return size;
}

int* getManualInputArray(const size_t size)
{
	int* myArray = new int[size];
	cout << "\nВведите элементов массива\n";

	for (size_t i = 0; i < size; i++)
	{
		cin >> myArray[i];
	}

	return myArray;
}

int* getRandomInputArray(const size_t size, const int minValue, const int maxValue)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution <int> distrib(minValue, maxValue);

	int* myArray = new int[size];

	cout << "\nМассив:\n";
	for (size_t i = 0; i < size; i++)
	{
		myArray[i] = distrib(gen);
		cout << myArray[i] << " ";
	}

	return myArray;
}

void print(int* array, const size_t size, ostream& out)
{
	if (array == nullptr)
	{
		throw out_of_range("Массив не определен!");
	}

	out << "Массив:\n";
	for (size_t i = 0; i < size; i++)
	{
		out << array[i] << " ";
	}
}

void exhcangeLastKElementByOpposite(int* array, const size_t size, size_t k)
{
	if (array == nullptr)
	{
		throw out_of_range("Массив не определен!");
	}

	const int temp = size - 1;
	if (temp < 0)
	{
		throw out_of_range("Размер массива не позволяет выполнить данную функцию!");
	}

	for (size_t i = size - 1; i >= k; i--)
	{
		array[i] *= -1;
	}
}

void showIndex(int* array, const size_t size)
{
	if (array == nullptr)
	{
		throw out_of_range("Массив не определен!");
	}

	bool b = false;
	cout << "\n\nИндексы тех элементов, значения которых кратны 3 :\n";
	for (size_t i = 0; i < size; i++)
	{
		if ((array[i] % 3) == 0)
		{
			cout << i + 1 << " ";
			b = true;
		}
	}

	if (b == false)
	{
		cout << "В массиве нет кратных 3.";
	}
}

void getPairElements(int* array, size_t size)
{
	if (array == nullptr)
	{
		throw out_of_range("Массив не определен!");
	}

	cout << "\n\n";
	int sum;
	cout << "Введите значение = ";
	cin >> sum;

	sort(array, array + size);
	int i = 0;
	int j = size - 1;
	bool b = false;
	cout << "Элементы, сумма которых равна, " << sum << " являются :\n";
	while (i < j)
	{
		while ((array[i] + array[j]) <= sum && i < j)
		{
			if ((array[i] + array[j]) == sum)
			{
				cout << "(" << array[i] << "," << array[j] << ")" << endl;
				b = true;
			}
			i++;
		}
		j--;
		while ((array[i] + array[j]) >= sum && i < j)
		{
			if ((array[i] + array[j]) == sum)
			{
				cout << "(" << array[i] << "," << array[j] << ")" << endl;
				b = true;
			}
			j--;
		}
	}

	if (b == false)
	{
		cout << "В массиве нет пары элементов с суммой, равной " << sum;
	}
}
