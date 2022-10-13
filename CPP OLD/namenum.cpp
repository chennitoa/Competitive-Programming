/*
ID: achenni1
TASK: namenum
LANG: C++14                
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
string N;

char charNum(char x) {
	if (x == 'A' || x == 'B' || x == 'C') return '2';
	else if (x == 'D' || x == 'E' || x == 'F') return '3';
	else if (x == 'G' || x == 'H' || x == 'I') return '4';
	else if (x == 'J' || x == 'K' || x == 'L') return '5';
	else if (x == 'M' || x == 'N' || x == 'O') return '6';
	else if (x == 'P' || x == 'R' || x == 'S') return '7';
	else if (x == 'T' || x == 'U' || x == 'V') return '8';
	else return '9';
}


int main() {
	ofstream fout ("namenum.out");
	ifstream fin ("namenum.in");
	ifstream dict ("dict.txt");
	
	string stringE;
	fin >> stringE;
	string name;
	bool nameEqual = false;
	int f = stringE.length();
	int d = 0;
	while (dict >> name) {
		int x = name.length();
		int q = 0;
		if (x == f) {
			//fout << "New name. \n";
			for (int i = 0; i < x; i++) {
				char z = charNum(name.at(i));
				char y = stringE.at(i);
				//fout << z << " " << y << "\n";
				if (z == y) q++; 
			}
		}
		if (q == x) {
			fout << name << "\n";
			d++;
		}
		q = 0;
	}
	if (d == 0) fout << "NONE\n";
	return 0;
}