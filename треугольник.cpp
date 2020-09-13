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
	void setValues() //задание параметров
	{
		cin >> name;
		cin >> x;
		cin >> y; //получение данных
	}

	float R(Dot object) //расстояние между 2 точками
	{
		float d = 0;
		d = sqrt(pow(x - object.x, 2) + pow(y - object.y, 2));
		d = floor(d * 100) / 100;
		return d;
	}
};
class Delta //класс треугольника
{
public:
	void setValues()  //задание параметров
	{

		cout << "Введите название u координаты первой точки через пробел : ";
		cin >> A.name >> A.x >> A.y;
		cout << "Введите название u координаты второй точки через пробел : ";
		cin >> B.name >> B.x >> B.y;
		cout << "Введите названиe u координаты третьей точки через пробел : ";
		cin >> C.name >> C.x >> C.y;
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
			cout << "Введите название u координаты первой точки через пробел: ";
			Dot first;
			first.setValues();
			cout << "Введите название и координаты второй точки через пробел: ";
			Dot second;
			second.setValues();
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
