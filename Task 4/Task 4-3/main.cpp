#include<iostream>
#include <random>
#include<string>

using namespace std;

/**
*\brief Считать размер массива.
*\param message Побуждающее сообщение для пользователя.
*\return размер массива.
*/
size_t getSize(const string& message);

/**
*\brief Функция создающая массив.
*\param n количество строк массива.
*\param m количество столбцов массива.
*\return возвращает указатель на созданный массив.
*/
int** createArray(const size_t n, const size_t m);

/**
*\brief Считывает значения элементов массива клавиатуры.
*\param n количество строк массива.
*\param m количество столбцов массива.
*\return Массив.
*/
int** getManualInputArray(const size_t n, const size_t m);

/**
*\brief Заполнение массива случайными числами.
*\param n количество строк массива.
*\param m количество столбцов массива.
*\param minValue Минимальное значение массива.
*\param maxValue максимальное значение массива.
*\return Массив.
*/
int** getRandomInputArray(const size_t n, const size_t m, const int minValue = -100, const int maxValue = 100);

/**
*\brief Печатает массив.
*\param array Массив.
*\param n количество строк массива.
*\param m количество столбцов массива.
*\param out Поток вывода.
*/
void print(int** array, const size_t n, const size_t m, ostream& out = cout);

/**
*\brief Замените максимальный элемент в каждом ряду на противоположный знак.
*\param array Массив.
*\param n количество строк массива.
*\param m количество столбцов массива.
*\return Новый массив.
*/
int** replaceMaxElementByOpposite(int** array, const size_t n, const size_t m);

/**
*\brief Вставьте столбец нулей после всех столбцов, содержащих максимальный элемент.
*\param array Массив.
*\param n количество строк массива.
*\param m количество столбцов массива.
*\return Новый массив.
*/
int** insertColumn(int** array, const size_t n, const size_t m);

/**
*\brief Удалить таблицу.
*\param array Массив.
*\param n количество строк массива.
*\param m количество столбцов массива.
*/
void deleteArray(int** array, const size_t n);

enum class arrayInputChoice
{
    MANUAL = 1,
    RANDOM
};

/**
*\brief Точка входа в программу в  точке х.
*\return Возвращает 0 случае успеха.
*/

int main()
{
    try
    {
        const auto n = getSize("Введите размер линий массива = ");
        const auto m = getSize("Введите размер столбцов массива = ");
        int** array = createArray(n, m);

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
            array = getManualInputArray(n, m);
            break;
        }
        case arrayInputChoice::RANDOM:
        {
            array = getRandomInputArray(n, m);
            break;
        }
        default:
            cerr << "Вы ввели некорректное действие!";
            return 1;
        }

        int** array_1 = replaceMaxElementByOpposite(array, n, m);
        cout << "\nЗамените максимальный элемент в каждом ряду на противоположный знак.\n";
        print(array_1, n, m);

        int** array_2 = insertColumn(array, n, m);
        cout << "\n\nВставьте столбец нулей после всех столбцов, содержащих максимальный элемент.\n";
        print(array_2, n, m);
        
        deleteArray(array, n);
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

int** createArray(const size_t n, const size_t m)
{
    int** array = new int* [n];

    for (size_t i = 0; i < n; i++)
    {
        array[i] = new int[m];
    }
    return array;
}

int** getManualInputArray(const size_t n, const size_t m)
{
    int** array = createArray(n, m);
    cout << "\nВведите элементов массива.\n";

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            int k = 0;
            cout << "array[" << i << "][" << j << "] = ";
            cin >> k;
            array[i][j] = k;
        }
    }

    return array;
}

int** getRandomInputArray(const size_t n, const size_t m, const int minValue, const int maxValue)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution <int> distrib(minValue, maxValue);

    int** array = createArray(n, m);

    cout << "\nМассив:\n";
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            array[i][j] = distrib(gen);
            cout << "array[" << i << "][" << j << "] = " << array[i][j] << "\n";
        }
    }

    return array;
}

void print(int** array, const size_t n, const size_t m, ostream& out)
{
    if (array == nullptr)
    {
        throw out_of_range("Массив не определен!");
    }

    out << "Массив:\n";

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            out << array[i][j] << " ";
        }
    }
}

int** replaceMaxElementByOpposite(int** array, const size_t n, const size_t m)
{
    if (array == nullptr)
    {
        throw out_of_range("Массив не определен!");
    }

    for (size_t i = 0; i < n; i++)
    {
        int max = array[i][0];
        int max_j = 0;

        for (size_t j = 1; j < m; j++)
        {
            if (array[i][j] > max)
            {
                max = array[i][j];
                max_j = j;
            }
        }
        array[i][max_j] *= (-1);
    }
    return array;
}

int** insertColumn(int** array, const size_t n, const size_t m)
{
    if (array == nullptr)
    {
        throw out_of_range("Массив не определен!");
    }

    for (size_t i = 0; i < n; i++)
    {
        int max = array[i][0];
        int max_j = 0;

        for (size_t j = 1; j < m; j++)
        {
            if (array[i][j] > max)
            {
                max = array[i][j];
                max_j = j + 1;
            }
        }
        array[i][max_j] *= 0;
    }
    return array;
}

void deleteArray(int** array, const size_t n)
{
    for(size_t i = 0; i < n; i++)
    {
        if (array != nullptr)
        {
            delete[] array[i];
            array = nullptr;
        }
    }
}
