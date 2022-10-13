/*
ID: achenni1
TASK: wormhole
LANG: C++11                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#define MAXN 12

using namespace std;
int N;
int xCoord[MAXN + 1];
int yCoord[MAXN + 1];
int pairs[MAXN + 1];
int rightNext[MAXN + 1];
ofstream fout("wormhole.out");
ifstream fin("wormhole.in");

bool cycle(void) {
	for (int i = 1; i <= N; i++) {
		int pos = i;
		for (int j = 0; j < N; j++) {
			pos = rightNext[pairs[pos]];
		}
		if (pos != 0) {
			return true;
		}
	}
	return false;
}

int solve(void) {
	int i = 0;
	int total = 0;
	for (i = 1; i <= N; i++) {
		if (pairs[i] == 0) break;
	}
	if (i > N) {
		if(cycle() == true) return 1;
		else return 0;
	}
	for (int j = i + 1; j <= N; j++) {
		if (pairs[j] == 0) {
			pairs[i] = j;
			pairs[j] = i;
			total += solve();
			pairs[i] = pairs[j] = 0;
		}
	}
	return total;
}

int main() {
	ofstream fout("wormhole.out");
	ifstream fin("wormhole.in");
	fin >> N;
	for (int i = 1; i <= N; i++) {
		fin >> xCoord[i] >> yCoord[i];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (xCoord[j] > xCoord[i] && yCoord[i] == yCoord[j]) {
				if(rightNext[i] == 0 || xCoord[j] - xCoord[i] < xCoord[rightNext[i]] - xCoord[i]) {
					rightNext[i] = j;
				}
			}
		}
	}
	
	fout << solve() << "\n";
	return 0;
}
