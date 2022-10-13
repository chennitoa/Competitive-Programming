/*
ID: achenni1
TASK: preface
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int N;

int main() {
	ifstream fin ("preface.in");
	ofstream fout ("preface.out");
	fin >> N;
	int I, V, X, L, C, D, M;
	I = V = X = L = C = D = M = 0;
	
	for (int i = 1; i <= N; i++) {
		if (i % 5 == 1 || i % 5 == 2 || i % 5 == 3) {
			I += i % 5;
		}
		else if (i % 5 == 4) {
			I += 1;
			V += 1;
		}
		if (i % 10 >= 5 && i % 10 <= 8) {
			V += 1;
		}
		int tenths = i % 50 / 10;
		if (tenths == 1 || tenths == 2 || tenths == 3) {
			X += tenths;
		}
		else if (tenths == 4) {
			X += 1;
			L += 1;
		}
		if (i % 100 / 10 >= 5 && i % 100 / 10 <= 8) {
			L += 1;
		}
		if (i % 10 == 9) {
			X += 1;
			V -= 1;
		}
		int hundredths = i % 500 / 100;
		if (hundredths == 1 || hundredths == 2 || hundredths == 3) {
			C += hundredths;
		}
		else if (hundredths == 4) {
			C += 1;
		}
		if (i % 100 / 10 == 9) { 
			C += 1;
			L -= 1;
		}
		if ((i + 100) % 1000 / 100 >= 5) {
			D += 1;
		}
		if (i % 1000 / 100 == 9) {
			M += 1;
		}
		int mils = i % 5000 / 1000;
		M += mils;
	}
	fout << "I" << " " << I << "\n";
	if (N >= 5) fout << "V" << " " << V << "\n";
	if (N >= 10) fout << "X" << " " << X << "\n";
	if (N >= 50) fout << "L" << " " << L << "\n";
	if (N >= 100) fout << "C" << " " << C << "\n";
	if (N >= 500) fout << "D" << " " << D << "\n";
	if (N >= 1000) fout << "M" << " " << M << "\n";
	return 0;
}