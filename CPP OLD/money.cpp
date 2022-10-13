/*
ID: achenni1
TASK: money
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;
int V, N;
long long coins[10001];

int main() {
	ifstream fin("money.in");
	ofstream fout("money.out");
	fin >> V >> N;
	int C;
	coins[0] = 1;
	for (int i = 0; i < V; i++) {
		fin >> C;
		for (int j = C; j <= N; j++) {
			coins[j] += coins[j - C];
		}			
	}
	fout << coins[N] << "\n";
	return 0;
}