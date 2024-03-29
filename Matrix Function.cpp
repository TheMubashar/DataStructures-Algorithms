// M.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;

int main() {
	int Row, Column, Row1, Column1, Selection;
	int **M, **M1, **result;
	cout << "Enter the number of rows and columns you want in your matrix " << endl;
	cin >> Row >> Column;
	M = new int*[Row];
	for (int i = 0; i < Row; i++) {
		M[i] = new int[Column];
	}
	for (int i = 0; i < Row; i++) {
		for (int j = 0; j < Column; j++) {
			cout << "Enter the next value of the matrix" << endl;
			cin >> M[i][j];
		}
	}

	cout << "\nEnter the number of rows and columns of 2nd matrix you want" << endl;
	cin >> Row1 >> Column1;
	M1 = new int*[Row1];
	for (int i = 0; i < Row1; i++)
	{
		M1[i] = new int[Column1];
	}
	for (int i = 0; i < Row1; i++) {
		for (int j = 0; j < Column1; j++) {
			cout << "Enter the next value of the matrix" << endl;
			cin >> M1[i][j];
		}
	}
	cout << "\nNow Select the operation you want to on these 2 matrixs from the following" << endl;
	cout << "1 Addition" << endl;
	cout << "2 Subtraction" << endl;
	cout << "3 Multiplication" << endl;
	cout << "4 Adjoint" << endl;
	cout << "Selection: ";
	cin >> Selection;
	cout << endl;
	if (Selection == 1 || Selection == 2) {
		if (Row == Row1 && Column == Column1) {
			for (int i = 0; i < Row1; i++) {
				for (int j = 0; j < Column1; j++) {
					if (Selection == 1) {
						M[i][j] += M1[i][j];
					}
					else {
						M[i][j] -= M1[i][j];
					}

				}
			}
			for (int i = 0; i < Row1; i++) {
				for (int j = 0; j < Column1; j++) {
					cout << M[i][j] << " ";
				}
				cout << endl;
			}
		}
		else {
			cout << "You must have same number of rows and columns of both matrixs" << endl;
		}
	}
	else if (Selection == 3) {
		if (Column == Row1) {
			result = new int*[Row];
			for (int i = 0; i < Row; i++) {
				result[i] = new int[Column1];
			}
			for (int i = 0; i < Row; i++) {
				for (int j = 0; j < Column1; j++) {
					result[i][j] = 0;
				}
			}
			int temp = 0;
			for (int i = 0; i < Row; i++) {
				for (int k = 0; k<Column; k++) {
					for (int l = temp; l < Row1; l++) {
						for (int j = 0; j < Column1; j++) {
							result[i][j] += (M[i][k] * M1[l][j]);
						}
						temp++;
						if (temp >= Row1) {
							temp = 0;
						}
						break;
					}
				}
			}
			for (int i = 0; i < Row; i++) {
				for (int j = 0; j < Column1; j++) {
					cout << result[i][j] << " ";
				}
				cout << endl;
			}

		}
		else {
			cout << "You can't multiply these matrixs. Number of columns of first matrixs must be equal to rows of secong matrixs" << endl;
		}
	}
	else if (Selection == 4) {
		if (Row == 3 && Column == 3) {
			result = new int*[Row];
			for (int i = 0; i < Row; i++) {
				result[i] = new int[Column];
			}
			for (int i = 0; i < Row; i++) {
				for (int j = 0; j < Column; j++) {
					result[i][j] = (M[(i + 1) % 3][(j + 1) % 3] * M[(i + 2) % 3][(j + 2) % 3]) - M[(i + 1) % 3][(j + 2) % 3] * M[(i + 2) % 3][(j + 1) % 3];
				}
			}
			for (int i = 0; i < Row; i++) {
				for (int j = 0; j < Column; j++) {
					result[i][j] = (M[(j)][(i)]);
				}
			}
			for (int i = 0; i < Row; i++) {
				for (int j = 0; j < Column; j++) {
					cout << result[i][j] << " ";
				}
				cout << endl;
			}
		}
		else {
			cout << "Only 3*3 matrix adjoint possible" << endl;
		}
	}
	return 0;
}

