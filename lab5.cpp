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

void splain(double *y, double *x, double *c, double *d, double *b, int n) {
	double start = x[0];
	double end = x[n-1];
	
	int n1=32;



	double step = (end - start) /n1;
	cout << step;
	printf("y\t\tx\n");

	double *x1, *y1;
	x1 = new double[n1];
	y1 = new double[n1];


	for (int i = 0;i <n;i++) 
		printf("%f\t%f\n", y[i], x[i]);
	cout << "\n\n\n";

	int k = 0;
	int i = 0;
	for (double s = start; s <= end; s += step) {

		for (k = 1; k <= n; k++) {
			if (s >= x[k - 1] && s <= x[k]) {
				break;
			}

		}
		
			double F = y[k] + b[k] * (s - x[k]) + c[k] * pow(s - x[k], 2) + d[k] * pow(s - x[k], 3);
			printf("%f\t%f\n", F, s);
			k++;

		
		y1[i] = F;
		i++;
	
	}

	metodtrapec(n1, step, y1);
}
void coef(double *y, double *x, double *c, double *d, double *b, int n) {

	double *h, *l, *delta, *lambda;

	h = new double[n];
	l = new double[n];
	delta = new double[n];
	lambda = new double[n];


	for (int k = 1; k <= n; k++) {
		h[k] = x[k] - x[k - 1];
		if (h[k] == 0) {
			printf("\nError, x[%d]=x[%d]\n", k, k - 1);

		}
		l[k] = (y[k] - y[k - 1]) / h[k];
	}
	delta[1] = -h[2] / (2 * (h[1] + h[2]));
	lambda[1] = 1.5*(l[2] - l[1]) / (h[1] + h[2]);
	for (int k = 3; k <= n; k++) {
		delta[k - 1] = -h[k] / (2 * h[k - 1] + 2 * h[k] + h[k - 1] * delta[k - 2]);
		lambda[k - 1] = (3 * l[k] - 3 * l[k - 1] - h[k - 1] * lambda[k - 2]) /
			(2 * h[k - 1] + 2 * h[k] + h[k - 1] * delta[k - 2]);
	}
	c[0] = 0;
	c[n] = 0;
	for (int k = n; k >= 2; k--) {
		c[k - 1] = delta[k - 1] * c[k] + lambda[k - 1];
	}
	for (int k = 1; k <= n; k++) {
		d[k] = (c[k] - c[k - 1]) / (3 * h[k]);
		b[k] = l[k] + (2 * c[k] * h[k] + h[k] * c[k - 1]) / 3;
	}

	int k = 0;
		printf("\nA[k]\t\tB[k]\t\tC[k]\t\tD[k]\n");

	for (k = 1; k <= n; k++) {
		printf("%f\t%f\t%f\t%f\n", y[k], b[k], c[k], d[k]);
	}
}


int main()
{

	int k = 0;
	int n = 9;			//количество столбцов
	double *x, *y, step;
	step = 0.25;
	x = new double[n];
	y = new double[n];
	y[0] = 0;		y[1] = 0.028;	y[2] = 0.054;
	y[3] = 0.078;	y[4] = 0.1;		y[5] = 0.2;
	y[6] = 0.133;	y[7] = 0.145;	y[8] = 0.154;
	double cz = 0;
	printf("x\t\ty\n");
	for (int i = 0;cz < n;cz++) {

		x[i] = cz / 4;
		printf("%f\t%f\n", x[i], y[i]);
		i++;
	}



	double *c, *b, *d;
	c = new double[n];
	d = new double[n];
	b = new double[n];
	
	
	metodtrapec(n, step, y);
	
	coef(y, x, c, b, d, n);
	splain(y, x, c, b, d, n);


	system("pause");
}
