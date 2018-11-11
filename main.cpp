#include <iostream>
#include <sstream>
#include <cmath>

double f(double x)
{
	return -sqrt(x)*sin(x);
}
double f2(double x)
{
	return -sqrt(x)*sin(x)*sin(5*x);
}

void random_search(double a, double b, double P, double e)
{
	int n = log10(P) / log10(1 - (e / (b - a)));
	double x;
	double min = f(a);
	double Xmin = a;
	for (int i = 0; i < n; i++)
	{
		x = a + rand() % (int)b + rand() % 1000 / 10000.0;
		if (min > f(x))
		{
			min = f(x);
			Xmin = x;
		}

	}
	printf_s("%5d %8.3f %8.3f %8.3f %8.3f\n", n, P, e, Xmin, min);
}

int main()
{
	double a = 0;
	double b = 3;
	double e = 0;
	
	int counter = 1;

	for (double P = 0.90; P < 1; P += 0.01)
	{
		for (double q = 0.005; q < 0.105; q += 0.005)
		{
			e = (b - a)*q;
			printf_s("%4d",counter);
			counter++;
			random_search(a, b, P, e);
			
		}
		std::cout << "\n";
	}
	return 0;
}
