
/*
ID: achenni1
TASK: transform
LANG: C++11                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#define MAXN 10

using namespace std;
int N;
int pat1[MAXN][MAXN];
int pat2[MAXN][MAXN];

bool checkPattern(int graph1[MAXN][MAXN], int graph2[MAXN][MAXN]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (graph1[i][j] != graph2[i][j]) {
				return false;
			}
		}
	}
	return true;
}
bool checkReflect(int graph1[MAXN][MAXN], int graph2[MAXN][MAXN]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (graph1[-i + N - 1][j] != graph2[i][j]) return false;
		}
	}
	return true;
}
bool checkReflectV(int graph1[MAXN][MAXN], int graph2[MAXN][MAXN]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (graph1[i][-j + N - 1] != graph2[i][j]) return false;
		}
	}
	return true;
}

int main() {
	int ans = 7;
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");
	fin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char x;
			fin >> x;
			if (x == '@') {
				pat1[i][j] = 1;
			}
			else {
				pat1[i][j] = 0;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char x;
			fin >> x;
			if (x == '@') {
				pat2[i][j] = 1;
			}
			else {
				pat2[i][j] = 0;
			}
		}
	}
	if (checkPattern(pat1, pat2) == true) {
		ans = min(ans, 6);
	}
	if (checkReflectV(pat1, pat2) == true) {
		ans = min(ans, 4);
	}
	for (int i = 0; i < 3; i++) {
		//Process bottom left square
		for (int j = 0; j < N/2; j++) {
			for (int k = 0; k < N/2; k++) {
				int temp =  pat1[j][k];
				pat1[j][k] = pat1[N - k - 1][j];
				pat1[N - k - 1][j] = pat1[N - j - 1][N - k - 1];
				pat1[N - j - 1][N - k - 1] = pat1[k][N - j - 1];
				pat1[k][N - j - 1] = temp;
			}
		}
		//Process middle edges
		if (N % 2 == 1) {
			for (int j = 0; j < N/2; j++) {
				int temp = pat1[N/2][j];
				pat1[N/2][j] = pat1[N - j - 1][N/2];
				pat1[N - j - 1][N/2] = pat1[N/2][N - j - 1];
				pat1[N/2][N - j - 1] = pat1[j][N/2];
				pat1[j][N/2] = temp;
			}
		}
		if (checkPattern(pat1, pat2) == true) {
			ans = min(i + 1, ans);
		}
		if (i % 2 == 0) {
			if (checkReflect(pat1, pat2) == true) {
				ans = min(5, ans);
			}
		}
		else {
			if (checkReflectV(pat1, pat2) == true) {
				ans = min(5, ans);
			}
		}
	}
	fout << ans << "\n";
	return 0;
}