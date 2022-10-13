/*
ID: achenni1
TASK: dualpal
LANG: C++                
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;
int N, S;

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
	ofstream fout ("dualpal.out");
	ifstream fin ("dualpal.in");
	fin >> N >> S;
	int counter = 0;
	for (int i = S + 1; counter < N; i++) {
		int j = 0;
		for (int k = 2; k < 11; k++) {
			string result = convert(i, k);
			string resultR(result.rbegin(), result.rend());
			if (result.compare(resultR) == 0) j++;
		}
		if (j > 1) {
			fout << i << "\n";
			counter++;
		}	
	}
	return 0;
}