//У тех, у кого в билете функция задана таблицей, требуется сначала построить кубический сплайн,
//и интегрировать уже его с каким - то малым шагом, контролируя погрешность по методу Рунге.
//Если для вычисления интеграла Вам требуется его как - то преобразовать(например, сделать замену или разложить 
//в ряд подынтегральную функцию), опишите это в файле Readme.md(формат markdown), желательно с формулами.


#include "pch.h"
#include <iostream>
using namespace std;

//Метод трапеций для таблицы с шагом 0.25

void metodtrapec(int n,  double shag, double *F )
{
	double s = 0;
	for (int i = 1;i < n;i++) {
		s += ((shag)*(F[i] + F[i - 1]) / 2);
		//cout << "integral=" << s << endl;
	}
	cout <<endl<< "integral=" << s << endl;
}
/*
void splain(double *y) {
	y[k] = a[k] + b[k] + c[k] + d[k];

}*/

int main()
{
	int n = 9;			//количество столбцов
	double *x, *y, shag;
	shag = 0.25;
	x = new double[n];
	y = new double[n];
	y[0] = 0;		y[1] = 0.028;	y[2] = 0.054;
	y[3] = 0.078;	y[4] = 0.1;		y[5] = 0.2;
	y[6] = 0.133;	y[7] = 0.145;	y[8] = 0.154;
	double cz = 0;
	for (int i = 0;cz < n;cz++) {

		x[i] = cz / 4;
		cout << x[i]<<" | "<< y[i] << endl;
		i++;
	}



	metodtrapec(n, shag, y);

	system("pause");
}
