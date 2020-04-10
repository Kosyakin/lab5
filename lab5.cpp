//У тех, у кого в билете функция задана таблицей, требуется сначала построить кубический сплайн,
//и интегрировать уже его с каким - то малым шагом, контролируя погрешность по методу Рунге.
//Если для вычисления интеграла Вам требуется его как - то преобразовать(например, сделать замену или разложить 
//в ряд подынтегральную функцию), опишите это в файле Readme.md(формат markdown), желательно с формулами.


#include "pch.h"
#include <iostream>
using namespace std;

// Функция вычисления определенного интеграла
double Integral(double *f, double step) {
	double value = 0;
	for (int i = 0; i < NUMPOINT; i++) {
		value += f[i];
	}
	value *= step;
	return value;
}
int main() {
	double *f;
	double step, t;
	double S;
	int i;
	system("chcp 1251");
	system("cls");
	f = (double*)malloc(NUMPOINT * sizeof(double));
	printf("Количество точек = %d\n", NUMPOINT);
	step = PI / NUMPOINT; // величина шага (высота трапеций)
	printf("Величина шага = %lf\n", step);
	t = 0.0;
	// Инициализация значений функции f(t)=sin(t)
	for (i = 0; i < NUMPOINT; i++) {
		f[i] = sin(t);
		t += step;
	}
	S = Integral(f, step); // вычисление интеграла
	printf("Значение интеграла = %lf", S);
	getchar();
	return 0;
}




int main()
{
	int n = 10;//количество столбцов

}
