/*
ID: achenni1
TASK: pprime
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int a, b;

bool checkPrime(int num) {
	if (num == 0 || num == 1) return false;
	if (num == 2) return true;
	if (num % 2 == 0) return false;
	for (int i = 3; i * i <= num; i+= 2) {
		if (num % i ==  0) return false;
	}
	return true;
}

int main() {
	ifstream fin("pprime.in");
	ofstream fout("pprime.out");
	fin >> a >> b;
	//One digit
	
	for (int i = 0; i < 10; i++) {
		if (i > b) return 0;
		if (checkPrime(i) == true && i >= a) fout << i << "\n";
	}
	if (11 > b) return 0;
	if (checkPrime(11) == true && 11 >= a) fout << 11 << "\n"; 
	//Three digits
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (i * 101 + j * 10 > b) return 0;
			if (checkPrime(i * 101 + j * 10) == true && i * 101 + j * 10 >= a) fout << i * 101 + j * 10 << "\n";
		}
	}
	//Five digits
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				if (i * 10001 + j * 1010 + k * 100 > b) return 0;
				if (checkPrime(i * 10001 + j * 1010 + k * 100) == true && i * 10001 + j * 1010 + k * 100 >= a) fout << i * 10001 + j * 1010 + k * 100 << "\n";
			}
		}
	}
	//Seven digits
	for (int i = 1; i < 10; i += 2) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				for (int l = 0; l < 10; l++) {
					if (i * 1000001 + j * 100010 + k * 10100 + l * 1000 > b) return 0;
					if (checkPrime(i * 1000001 + j * 100010 + k * 10100 + l * 1000) == true && i * 1000001 + j * 100010 + k * 10100 + l * 1000 >= a) fout << i * 1000001 + j * 100010 + k * 10100 + l * 1000 << "\n";
				}
			}
		}
	}
	
	return 0;
	
}