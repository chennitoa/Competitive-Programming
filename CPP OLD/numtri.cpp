/*
ID: achenni1
TASK: numtri
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int R;
int T[1000][1000];
int S[1000][1000];

int main() {
	ifstream fin("numtri.in");
	ofstream fout("numtri.out");
	fin >> R;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j <= i; j++) {
			fin >> T[i][j];
		}
	}
	for (int i = R - 1; i > 0; i--) {
		for (int j = 0; j <= i; j++) {
			S[i - 1][j] = max(S[i][j] + T[i][j], S[i][j + 1] + T[i][j + 1]);
		}
	}
	fout << S[0][0] + T[0][0] << "\n";
	return 0;
}

