#include <iostream>

using namespace std;

/**
* \brief Рассчивает Время в пути для путешественника.
* \param v1 Скорость путешественника.
* \param s1 Расстояние, пройденное путешественника.
* \return Время в пути путника.
*/

double const getTime1(const double v1, const double s1);   

/**
* \brief Рассчивает Время в пути для путешественника.
* \param v2 Скорость путешественника.
* \param s2 Расстояние, пройденное путешественника.
* \return Время в пути путника.
*/

double const getTime2(const double v2, const double s2);

/**
* \brief Рассчивает Время в пути для путешественника.
* \param v3 Скорость путешественника.
* \param s3 Расстояние, пройденное путешественника.
* \return Время в пути путника.
*/

double const getTime3(const double v3, const double s3);

/**
* \brief Считать скорость и расстояние из консоли.
* \param Побуждающее сообщение для пользователя.
* \return Скорость и расстояние, пройденное путешественником.
*/

double getSide(const string& message);

/**
* \brief Точка входа в программу
* \return Возвращает 0 случае успеха
*/

int main()
{
    try
    {
        const double v1 = getSide("Введите значение скорости v1 = ");
        const double s1 = getSide("Введите значение расстояние s1 = ");
    
        const double v2 = getSide("\nВведите значение скорости v2 = ");
        const double s2 = getSide("Введите значение расстояние s2 = ");
        
        const double v3 = getSide("\nВведите значение скорости v3 = ");
        const double s3 = getSide("Введите значение расстояние s3 = ");
        
        const double half = 0.5;
        const double T = half * (getTime1(v1, s1) + getTime2(v2, s2) + getTime3(v3, s3));
    
        cout << "\nВремя, чтобы пройти половину пути, составляет : " << T << " м/с";
    }
    catch (out_of_range&)
	{
		cout << "\nНеправильные значения!";
		return 1;
	}
    
    return 0;
}

double const getTime1(const double v1, const double s1)
{
    return s1 / v1;
}

double const getTime2(const double v2, const double s2)
{
    return s2 / v2;
}

double const getTime3(const double v3, const double s3)
{
    return s3 / v3;
}

double getSide(const string& message)
{
	double side = 0.0;
	cout << message;
	cin >> side;
	if (side <= 0)
	{
		throw out_of_range("\nНеправильные значения!");
	}
	return side;
}
