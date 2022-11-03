#include<iostream>
#include <random>
#include<string>
#include<algorithm>

using namespace std;

/
*\brief Считать размер массива.
* \param message Побуждающее сообщение для пользователя.
* \return размер массива.
* /

size_t getSize(const string & message);

/
*\brief Считывает значения элементов массива клавиатуры.
* \param size Длина массива.
* \ return Массив.
* /

int* getManualInputArray(const size_t size);

/
*\brief Заполнение массива случайными числами.
* \param size Длина массива.
* \param minValue Минимальное значение массива.
* \param maxValue максимальное значение массива.
* \ return Массив.
* /

int* getRandomInputArray(const size_t size, const int minValue = -100, const int maxValue = 100);

/
*\brief Печатает массив.
* \param array Массив.
* \param size Длина массива.
* \param out Поток вывода.
* /

void print(int* array, const size_t size, ostream & out = cout);

void replaceElementByZero(int* array, const size_t size);

void insertK(int* array, const size_t size, size_t k);

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
        int* array = nullptr;

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
            array = getManualInputArray(size);
            break;
        }
        case arrayInputChoice::RANDOM:
        {
            array = getRandomInputArray(size);
            break;
        }
        default:
            cerr << "Вы ввели некорректное действие!";
            return 1;
        }

        replaceElementByZero(array, size);
        print(array, size);
        const auto k = getSize("\n\nВведите значение k = ");
        insertK(array, size, k);
        print(array, size);

        if (array != nullptr)
        {
            delete[] array;
            array = nullptr;
        }
    }
    catch (exception& e)
    {
        cerr << e.what();
        return 1;
    }

    return 0;
}

size_t getSize(const string & message)
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

    int* array = new int[size];

    cout << "\nМассив:\n";
    for (size_t i = 0; i < size; i++)
    {
        array[i] = distrib(gen);
        cout << array[i] << " ";
    }

    return array;
}

void print(int* array, const size_t size, ostream & out)
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

void replaceElementByZero(int* array, const size_t size)
{
    if (array == nullptr)
    {
        throw out_of_range("Массив не определен!");
    }

    bool b = false;
    cout << "\n\nЗамените первый отрицательный элемент массивa нулем.\n";
    for (size_t i = 0; i < size; i++)
    {
        if (array[i] < 0)
        {
            array[i] = 0;
            b = true;
            break;
        }
    }

    if (b == false)
    {
        throw out_of_range("В массиве нет отрицательных элементов!");
    }
}

void insertK(int* array, const size_t size, size_t k)
{
    if (array == nullptr)
    {
        throw out_of_range("Массив не определен!");
    }

    int number = 3;
    bool b = false;

    for (size_t i = 0; i < size; i++)
    {
        if ((array[i] % number) == 0)
        {
            array[i + 1] = k;
            b = true;
        }
    }

    if (b == false)
    {
        cout << "В массиве не существует кратного " << number;
    }
}