/*
ID: achenni1
TASK: sprime
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int N;
int Ncounter;
int Ndec = 1;
ofstream fout("sprime.out");

bool isPrime(int num) {
	if (num == 0) return true;
	if (num % 2 == 0 && num != 2) return false;
	for (int i = 3; i < num/2; i++) {
		if (num % i == 0) return false;
	}
	return true;
}	
	
void findPrime(int primeNum) {

	if (isPrime(primeNum) == true) {
		if (primeNum < Ndec / 10) {
			if (primeNum != 0) {
				findPrime(primeNum * 10 + 1);
			}
			findPrime(primeNum * 10 + 2);
			findPrime(primeNum * 10 + 3);
			findPrime(primeNum * 10 + 5);
			findPrime(primeNum * 10 + 7);
			findPrime(primeNum * 10 + 9);
		}
		else fout << primeNum << "\n";
		return;
	}
	
}
int main() {
	ifstream fin("sprime.in");
	
	fin >> N;
	for (int i = 0; i < N; i++) {
		Ndec *= 10;
	}
	findPrime(0);
	return 0;
}