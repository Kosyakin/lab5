
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


int main()
{
	int n = 9;			//количество столбцов
	double *x, *F, shag;
	shag = 0.25;
	x = new double[n];
	F = new double[n];
	F[0] = 0;		F[1] = 0.028;	F[2] = 0.054;
	F[3] = 0.078;	F[4] = 0.1;		F[5] = 0.2;
	F[6] = 0.133;	F[7] = 0.145;	F[8] = 0.154;
	double c = 0;
	for (int i = 0;c < n;c++) {
		x[i] = c / 4;
		cout << x[i]<<" | "<<F[i] << endl;
	}

	metodtrapec(n, shag, F);

	system("pause");
}
