/*
ID: achenni1
TASK: hamming
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

//N is number of codes, B is length, D is hamming distance
int N, B, D;
ifstream fin("hamming.in");
ofstream fout("hamming.out");

int dist(int x, int y) {
	bitset<8> b(x^y);
	return b.count();
}


int main() {
	fin >> N >> B >> D;
	vector<int> ans;
	ans.push_back(0);
	for (int i = 0; i < 1 << B; i++) {
		bool y = true;
		for (int x: ans) {
			y = y && (dist(i, x) >= D);
		}
		if (y == true) ans.push_back(i);
		if (ans.size() == N) break;
	}
	for (int i = 0; i < ans.size(); i++) {
		fout << ans[i];
		if (i % 10 == 9 && i != ans.size() - 1) fout << "\n";
		else if (i != ans.size() - 1) fout << " ";
	}
	fout << "\n";
	return 0;
}