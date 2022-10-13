/*
ID: achenni1
TASK: sort3
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int N;
int numA, numB, numC;
int records[1000];
int recordsOrder[3][3];

int main() {
	ifstream fin("sort3.in");
	ofstream fout("sort3.out");
	fin >> N;
	for (int i = 0; i < N; i++) {
		fin >> records[i];
		switch (records[i]) {
			case 1: numA++;
			break;
			case 2: numB++;
			break;
			case 3: numC++;
			break;
		}
	}
	for (int i = 0; i < numA; i++) {
		switch (records[i]) {
			case 1: recordsOrder[1][1]++;
			break;
			case 2: recordsOrder[1][2]++;
			break;
			case 3: recordsOrder[1][3]++;
			break;
		}
	}
	for (int i = numA; i < numB + numA; i++) {
		switch (records[i]) {
			case 1: recordsOrder[2][1]++;
			break;
			case 2: recordsOrder[2][2]++;
			break;
			case 3: recordsOrder[2][3]++;
			break;
		}
	}
	for (int i = numB + numA; i < numC + numB + numA; i++) {
		switch (records[i]) {
			case 1: recordsOrder[3][1]++;
			break;
			case 2: recordsOrder[3][2]++;
			break;
			case 3: recordsOrder[3][3]++;
			break;
		}
	}
	int numSwitches = 0;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			if (i != j) {
				if (recordsOrder[i][j] > recordsOrder[j][i]) {
					numSwitches += recordsOrder[j][i];
					recordsOrder[i][j] -= recordsOrder[j][i];
					recordsOrder[j][i] = 0;
				}
				else {
					numSwitches += recordsOrder[i][j];
					recordsOrder[j][i] -= recordsOrder[i][j];
					recordsOrder[i][j] = 0;
				}
			}	
		}
	}
	numSwitches += 2 * recordsOrder[1][2] + 2 * recordsOrder[1][3];
	fout << numSwitches << "\n";
	return 0;
}