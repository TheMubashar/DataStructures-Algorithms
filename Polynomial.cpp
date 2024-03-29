// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;

class Polynomial
{
	int degree;
	int SecondPtrdegree;
	int *ptr = NULL;
	int *Secondptr = NULL;
	int size;
public:

	Polynomial(int d) {
		degree = d;
		size = d + 1;
		ptr = new int[size];
	}
	void SetDegree(int d) {
		SecondPtrdegree = d;
		Secondptr = new int[d + 1];
	}
	void init() {
		for (int i = 0; i <= size; i++) {
			ptr[i] = 0;
		}
	}
	void Display() {
		if (Secondptr[SecondPtrdegree] != 0) {
			cout << Secondptr[SecondPtrdegree] << "X^" << SecondPtrdegree;
		}
		for (int i = (SecondPtrdegree - 1); i >= 0; i--) {
			if (i != 0 && Secondptr[i]>0) {
				cout << " +" << Secondptr[i] << "X^" << i;
			}
			else if (i != 0 && Secondptr[i]<0) {
				cout << " " << Secondptr[i] << "X^" << i;
			}
			else if (Secondptr[i] != 0 && Secondptr[i] > 0) {
				cout << " +" << Secondptr[i];
			}
			else if (Secondptr[i] != 0 && Secondptr[i] < 0) {
				cout << " " << Secondptr[i];
			}
		}
		cout << endl;
	}
	void input() {
		for (int i = degree; i >= 0; i--) {
			cout << "Enter the cofficient for the Degree " << i << endl;
			cin >> ptr[i];
		}
	}
	void Multiplication(Polynomial& P) {
		delete[]P.Secondptr;
		P.SetDegree(degree + P.degree);
		for (int i = 0; i <= degree + P.degree + 1; i++) {
			P.Secondptr[i] = 0;
		}
		for (int i = 0; i <= degree; i++) {
			if (ptr[i] != 0) {
				for (int j = 0; j <= P.degree; j++) {
					if (P.ptr[j] != 0) {
						P.Secondptr[(i + j)] += (ptr[i] * P.ptr[j]);
					}
				}
			}
		}
		cout << "Multiplication: ";
	}
	void Division(Polynomial P) {
		if (degree >= P.degree) {
			double *Remainder;
			Remainder = new double[size];
			for (int i = 0; i < size; i++) {
				Remainder[i] = ptr[i];
			}
			P.Secondptr = new int[size];
			int D = degree - P.degree;
			Polynomial Temp(D);
			Secondptr = new int[D + 1];
			SecondPtrdegree = D;
			Temp.init();
			for (int i = degree; i >= P.degree; i--) {
				if (ptr[i] != 0) {
					for (int i = 0; i <= size; i++) {
						P.Secondptr[i] = 0;
					}
					if (ptr[i] % P.ptr[P.degree] == 0) {
						Temp.ptr[D] = static_cast<int>(abs(Remainder[i] / P.ptr[P.degree]));
					}
					else {
						Temp.ptr[D] = static_cast<int>(floor(abs(Remainder[i] / P.ptr[P.degree])));
					}
					int x = i - P.degree;
					if (ptr[i]>0) {
						for (int k = P.degree; k >= 0; k--) {
							P.Secondptr[(k + x)] = Temp.ptr[D] * P.ptr[k];
						}
					}
					else {
						for (int k = P.degree; k >= 0; k--) {
							P.Secondptr[(k + x)] = (Temp.ptr[D] * -1) * P.ptr[k];
						}
						Temp.ptr[D] *= -1;
					}
					for (int j = degree; j >= 0; j--) {
						Remainder[j] -= P.Secondptr[j];
					}
					D--;
				}
			}
			for (int i = 0; i <= SecondPtrdegree; i++) {
				Secondptr[i] = Temp.ptr[i];
			}
			cout << "Division \n Remainder:";
			for (int i = P.degree - 1; i >= 0; i--) {

			}
		}
		else {
			cout << "Division not possible because dividend degree is smaller" << endl;
		}
	}
	void Addition(Polynomial& P) {
		if (degree == P.degree) {
			P.SetDegree(degree);
			for (int i = degree; i >= 0; i--) {
				P.Secondptr[i] = ptr[i] + P.ptr[i];
			}
		}
		else if (degree > P.degree) {
			P.SetDegree(degree);
			for (int i = degree; i > P.degree; i--) {
				P.Secondptr[i] = ptr[i];
			}
			for (int i = P.degree; i >= 0; i--) {
				P.Secondptr[i] = ptr[i] + P.ptr[i];
			}
		}
		else if (degree < P.degree) {
			P.SetDegree(P.degree);
			for (int i = P.degree; i > degree; i--) {
				P.Secondptr[i] = P.ptr[i];
			}
			for (int i = degree; i >= 0; i--) {
				P.Secondptr[i] = ptr[i] + P.ptr[i];
			}
		}
		cout << "Addition: ";
	}
	void Subtraction(Polynomial& P) {
		delete[]P.Secondptr;
		if (degree == P.degree) {
			P.SetDegree(degree);
			for (int i = degree; i >= 0; i--) {
				P.Secondptr[i] = ptr[i] - P.ptr[i];
			}
		}
		else if (degree > P.degree) {
			P.SetDegree(degree);
			for (int i = degree; i > P.degree; i--) {
				P.Secondptr[i] = ptr[i];
			}
			for (int i = P.degree; i >= 0; i--) {
				P.Secondptr[i] = ptr[i] - P.ptr[i];
			}
		}
		else if (degree < P.degree) {
			P.SetDegree(P.degree);
			for (int i = P.degree; i > degree; i--) {
				P.Secondptr[i] = P.ptr[i];
			}
			for (int i = degree; i >= 0; i--) {
				P.Secondptr[i] = ptr[i] - P.ptr[i];
			}
		}
		cout << "Subtraction: ";
	}
	~Polynomial();
};

Polynomial::~Polynomial()
{

}
int main()
{
	Polynomial P1(3);
	Polynomial P2(4);

	P1.init();
	P1.input();
	P2.init();
	P2.input();

	P2.Addition(P1);
	P1.Display();

	P2.Subtraction(P1);
	P1.Display();

	P2.Multiplication(P1);
	P1.Display();

	P2.Division(P1);
	P2.Display();

	return 0;
}