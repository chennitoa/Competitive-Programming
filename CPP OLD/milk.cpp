/*
ID: achenni1
TASK: milk
LANG: C++                
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

int N, M;
int cost[1001];
using namespace std;

int main() {
	ofstream fout("milk.out");
	ifstream fin("milk.in");
	fin >> N >> M;
	for (int i = 0; i < M; i++) {
		int x, y;
		fin >> x >> y;
		cost[x] += y;
	}
	int curMilk = 0;
	int curMoney = 0;
	for (int i = 0; i < 1001; i++) {
		if (cost[i] != 0) {
			if (curMilk < N) {
				curMilk += cost[i];
				curMoney += cost[i] * i;
			}
			if (curMilk > N) {
				int g = curMilk - N;
				curMilk -= g;
				curMoney -= i * g;
			}
		}
	}
	fout << curMoney << "\n";
	
}