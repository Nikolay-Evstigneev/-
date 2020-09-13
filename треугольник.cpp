#include <iostream>
#include <string>
#include <cmath>//подключение библиотек
using namespace std;
class Dot //класс точек
{
public:
	string name;
	float x;
	float y;
	Dot() //конструкторы
	{
		name = "";
		x = 0;
		y = 0;
	}
	void setValues(string n) //задание параметров
	{
		string to_x, to_y;
		cout << "Введите название " << n << " точки" << endl;
		cin >> name;
		cout << "Введите X для точки " << name << endl;
		cin >> to_x;
		x = validate(to_x, "Координата точки X - некорректна\nВведите снова");
		cout << "Введите Y для точки " << name << endl;
		cin >> to_y;
		y = validate(to_y, "Координата точки Y - некорректна\nВведите снова");
	} //проверка данных

	float R(Dot object) //расстояние между 2 точками
	{
		float d = 0;
		d = sqrt(pow(x - object.x, 2) + pow(y - object.y, 2));
		d = floor(d * 100) / 100;
		return d;
	}
private:
	// Принимает строку, возвращает, является ли строка числом
	bool is_digit(std::string s) 
	{
		const char* str = s.c_str();
		while ((*str < '0' || *str > '9') && *str != '-' && *str != '.' ? false : *str++); // проверка строки
		return !*str;
	}
	//Конвертирует строку в формат float
	float to_float_digit(std::string s)
	{
		return atof(s.c_str());
	}
	float validate(string to_digit, string error)
	{
		while (!(is_digit(to_digit)))
		{
			cout << "Ошибка, " << error << endl;
			cin >> to_digit;
		}
		return to_float_digit(to_digit);
	}
};
class Delta //класс треугольника
{
public:
	void setValues()  //задание параметров
	{
		A.setValues("первой");
		B.setValues("второй");
		C.setValues("третьей");
	}
	void calculate() //расчет периметра и площади
	{
		float S, a, b, c, p;
		a = A.R(B);
		b = B.R(C);
		c = C.R(A);
		if ((a < b + c) and (b < a + c) and (c < a + b)) //проверка существования треугольника
		{
			p = (a + b + c) / 2; //полупериметр
			S = sqrt(p * (p - a) * (p - b) * (p - c)); //формула Герона
			cout << "Площадь треугольника " << A.name << B.name << C.name << ": S = " << round(S * 100) / 100 << endl;
			cout << "Периметр треугольника " << A.name << B.name << C.name << ": P = " << round(p * 2 * 100) / 100 << endl;
		}
		else
		{
			cout << "Треугольник невозможен" << endl;
		}
	}
private:
	Dot A, B, C;//создание объектов внутри класса треугольника
};
int main()
{
	setlocale(LC_ALL, "Russian");
	string function, name;
	while (true) //основной цикл программы запрашивающий команды и вызывающий функции вычисления и вывода
	{
		cout << "Что вы хотите вычислить? (расстояние между точками:введите R; треугольник:введите T)" << endl;
		cin >> function;
		if (function == "R")
		{
			cout << "Подсчет расстояния между двумя точками " << endl;
			Dot first, second;
			first.setValues("первой");
			second.setValues("второй");
			float D = first.R(second);
			cout << "Расстояние между точками " << first.name << " и " << second.name << " равно: " << D;
			cout << endl;
		}
		else if (function == "T")
		{
			cout << "Подсчет площади и периметра треугольника" << endl;
			Delta t;
			t.setValues();
			t.calculate();
		}
	}
}
