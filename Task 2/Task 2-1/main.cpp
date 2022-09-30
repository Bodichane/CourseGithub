#include<iostream>
#include <string>

using namespace std;

/**
* \brief Рассчивает периметр прямоугольника .
* \param a Длина прямоугольника .
* \param b Ширина прямоугольника .
* \return периметр прямоугольника .
*/

double getPerimeter(double a, double b);

/**
* \brief Рассчивает площадь прямоугольника .
* \param a Длина прямоугольника .
* \param b Ширина прямоугольника .
* \return площадь прямоугольника .
*/

double getSurface(double a, double b);

/**
* \brief Рассчивает диагональ прямоугольника .
* \param a Длина прямоугольника .
* \param b Ширина прямоугольника .
* \return диагональ прямоугольникаи .
*/

double getDiagonal(double a, double b);

/**
* \brief Считать сторону прямоугольника из консоли .
* \param Побуждающее сообщение для пользователя .
* \return Сторона прямоугольника .
*/

double getSide(const string& message);

/**
* \brief Пользовательский ввод .
* \param PERIMETER Расчёт периметра прямоугольника .
* \param SURFACE Расчёт площади прямоугольника .
* \param DIAGONAL Расчёт диагонали прямоугольника .
*/

enum class userInput
{
	PERIMETER = 1,
	SURFACE,
	DIAGONAL
};

/**
* \brief Точка входа в программу
* \return Возвращает 0 случае успеха
*/

int main()
{
	try
	{
		const double a = getSide("Введите значение длины прямоугольника = ");
		const double b = getSide("Введите значение ширины прямоугольника = ");

		cout << "\nВведите число, соответсвующее заданию. \n"
			<< static_cast<int>(userInput::PERIMETER) << " - Вычисление периметра прямоугольника "
			<< static_cast<int>(userInput::SURFACE) << " - Вычисление площади прямоугольника "
			<< static_cast<int>(userInput::DIAGONAL) << " - Вычисление диагонали прямоугольника \n";

		int input = 0;
		cin >> input;
		const auto choice = static_cast<userInput>(input);

		switch (choice)
		{
		case userInput::PERIMETER:
		{
			const auto per = getPerimeter(a, b);
			cout << "Периметр прямоугольника = " << per;
			break;
		}
		case userInput::SURFACE:
		{
			const auto surf = getSurface(a, b);
			cout << "Площадь прямоугольника = " << surf;
			break;
		}
		case userInput::DIAGONAL:
		{
			const auto diag = getDiagonal(a, b);
			cout << "Диагональ прямоугольника = " << diag;
			break;
		}
		}
	}
	catch (out_of_range&)
	{
		cout << "неправильная cторона!";
		return 1;
	}

	return 0;
}

double getPerimeter(double a, double b)
{
	return (a + b) * 2;
}

double getSurface(double a, double b)
{
	return a * b;
}

double getDiagonal(double a, double b)
{
	return a * a + b * b;
}

double getSide(const string& message)
{
	double side = 0.0;
	cout << message;
	cin >> side;
	if (side <= 0)
	{
		throw out_of_range("неправильная cторона!");
	}
	return side;
}