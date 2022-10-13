/*
ID: achenni1
TASK: combo
LANG: C++                
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;
int N;
bool comboWorks[1000000];

int main() {
	ofstream fout("combo.out");
	ifstream fin("combo.in");
	fin >> N;
	int com1[3];
	int com2[3];
	for (int i = 0; i < 3; i++) {
		fin >> com1[i];
	}
	for (int i = 0; i < 3; i++) {
		fin >> com2[i];
	}
	int possLap[3];
	possLap[0] = possLap[2] = possLap[1] = 0;
	for (int i = 0; i < 3; i++) {
		int d1 = min(com1[i], N - com1[i]);
		int d2 = min(com2[i], N - com2[i]);
		int distance = min(abs(com1[i] - com2[i]), d1 + d2);
		possLap[i] = max(5 - distance, 0);
		possLap[i] = min(possLap[i], 5);
	}
	int overlap = possLap[1] * possLap[2] * possLap[0];
	int numDials = min(N*N*N, 250);
	int total = 250 - overlap;
	total = min(numDials, abs(total));
	fout << total << "\n";
	return 0;
}