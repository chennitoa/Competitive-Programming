/*
ID: achenni1
TASK: runround
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

unsigned long N;
ifstream fin("runround.in");
ofstream fout("runround.out");
bool used[10];
bool usedNum[10];

bool checkNum(unsigned long num) {
	string numString = to_string(num);
	int leng = numString.length();
	for (int i = 0; i < 10; i++) {
		used[i] = false;
	}
	int i = 0;
	while (used[i] == false) {
		used[i] = true;
		int j = numString.at(i) - '0';
		if (j >= leng) j -= leng;
		i += j;
		i = i % leng;
	}
	for (int j = 0; j < leng; j++) {
		if (used[j] == false || i != 0) return false;
	}
	return true;
}

void solve(char* s, bool *usedNum, int nd, int md) {
	if (nd == md) {
		s[nd] = '\0';
		if (atoi(s) > N && checkNum(atoi(s))) {
			fout << s << "\n";
			exit(0);
		}
		return;
	}
	char original = s[nd];
	for (int i = 1; i <= 9; i++) {
		if (usedNum[i] == false) {
			s[nd] = i + '0';
			usedNum[i] = true;
			solve(s, usedNum, nd + 1, md);
			usedNum[i] = false;
			s[nd] = original;
		}
	}
	return;
}

int main() {
	fin >> N;
	char s[10];
	for (int i = 0; i < 10; i++) {
		usedNum[i] = false;
	}
	for (int i = 1; i <= 9; i++) {
		solve(s, usedNum, 0, i);
	}
	return 0;
}