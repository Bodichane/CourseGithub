#include <iostream>

using namespace std;

/**
* \brief Рассчивает Время в пути для путешественника.
* \param v Скорость путешественника.
* \param s Расстояние, пройденное путешественника.
* \return Время в пути путника.
*/

double getTime(const double v, const double s);   

/**
* \brief Рассчивает Время в пути для путешественника.
* \param t1 Время в пути для путешественника для скорости v1.
* \param t2 Время в пути для путешественника для скорости v2.
* \param t3 Время в пути для путешественника для скорости v3.
* \return Время в пути путника.
*/

double sum(const double t1, const double t2, const double t3);

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

        const double t1 = getTime(v1, s1);
        const double t2 = getTime(v2, s2);
        const double t3 = getTime(v3, s3);
        const double T = sum(t1, t2, t3);
    
        cout << "\nВремя, чтобы пройти половину пути, составляет : " << T << " м/с";
    }
    catch (out_of_range&)
	{
		cout << "\nНеправильные значения!";
		return 1;
	}
    
    return 0;
}

double getTime(const double v, const double s)
{
    return s / v;  
}

double sum(const double t1, const double t2, const double t3)
{
    const double half = 0.5;
    return half * (t1 + t2 + t3);
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
