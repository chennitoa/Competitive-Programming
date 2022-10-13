/*
ID: achenni1
TASK: barn1
LANG: C++                
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#define MAXS 200

using namespace std;

int M, S, C;
int stalls[MAXS];
int stallsD[MAXS];

int main() {
	ofstream fout("barn1.out");
	ifstream fin("barn1.in");
	fin >> M >> S >> C;
	for (int i = 0; i < C; i++) {
		fin >> stalls[i];
	}
	sort(stalls, stalls + C);
	for (int i = 0; i < C - 1; i++) {
		stallsD[i] = stalls[i + 1] - stalls[i] - 1;
	}
	sort(stallsD, stallsD + C - 1);
	int total = 0;
	//Find M largest areas to not block
	for (int i = 0; i < M - 1; i++) {
		total += stallsD[C - 2 - i];
	}
	//Find stalls unblocked from the edge
	total += stalls[0] + S - stalls[C - 1] - 1;
	int minimum = S - total;
	minimum = max(minimum, C);
	fout << minimum << "\n";
}