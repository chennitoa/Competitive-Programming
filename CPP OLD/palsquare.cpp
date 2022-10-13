/*
ID: achenni1
TASK: palsquare
LANG: C++                
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;
int B;

string numbers = "0123456789ABCDEFGHIJK";
string convert(int dec, int base) {
	string binR = "";
	while (dec > 0) {
		int temp = dec % base;
		binR += numbers[temp];
		dec -= temp;
		dec /= base;
	}
	string bin(binR.rbegin(), binR.rend());
	return bin;
}	

int main() {
	ofstream fout ("palsquare.out");
	ifstream fin ("palsquare.in");
	fin >> B;
	for (int i = 1; i < 301; i++) {
		string square = convert(i*i, B);
		string root = convert(i, B);
		string squareR(square.rbegin(), square.rend());
		if (square == squareR) fout << root << " " << square << "\n";
	}
	return 0;
}