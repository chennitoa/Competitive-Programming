/*
ID: achenni1
TASK: nocows
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#define MOD 9901

using namespace std;

int table[101][202];
int smallTrees[101][202];
int N, K, c;

int main() {
	ifstream fin("nocows.in");
	ofstream fout("nocows.out");
	fin >> N >> K;
	table[1][1] = 1;
	for (int i = 2; i <= K; i++) {
		for (int j = 1; j <= N; j+=2) {
			for (int k = 1; k <= j - 1 - k; k+=2) {
				if (k != j - 1 - k) c = 2;
				else c = 1;
				table[i][j] += c * (smallTrees[i - 2][k] * table[i - 1][j - 1 - k] + table[i - 1][k] * smallTrees[i - 2][j - 1 - k] + table[i - 1][k] * table[i - 1][j - 1 - k]);
				table[i][j] %= MOD;
			}
		}
		for (int k = 0; k <= N; k++) {
			smallTrees[i - 1][k] += table[i - 1][k] + smallTrees[i - 2][k];
			smallTrees[i - 1][k] %= MOD;
		}
	}
	fout << table[K][N] << "\n";
	
	return 0;
}