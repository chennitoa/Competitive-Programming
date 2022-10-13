/*
ID: achenni1
TASK: frac1
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
#define f first
#define s second

using namespace std;

int N;
map<pair<int, int>, float> fractions;

bool sortMap(const pair<pair<int, int>, float> &a, const pair<pair<int, int>, float> &b) {
	return (a.s < b.s);
}

int gcd(int a, int b) {
	int t;
	while (b != 0) {
		t = a;
		a = b;
		b = t%b;
	}
	return a;
}

int main() {
	ifstream fin("frac1.in");
	ofstream fout("frac1.out");
	fin >> N;
	//i is denominator, j is numerator
	fractions[make_pair(0, 1)] = 0;
	fractions[make_pair(1, 1)] = 1;
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			if (gcd(i, j) == 1 || j == 1)  {
				float value = (float) j / (float) i;
				fractions[make_pair(j, i)] = value;
			}
		}
	}
	vector<pair<pair<int, int>, float> > sorter;
	map<pair<int, int>, float> :: iterator it;
	for (it = fractions.begin(); it != fractions.end(); it++) {
		sorter.push_back(make_pair(make_pair(it->first.f, it->first.s), it->second));
	}
	sort(sorter.begin(), sorter.end(), sortMap);
	for (int i = 0; i < sorter.size(); i++) {
		fout << sorter[i].f.f << "/" << sorter[i].f.s << "\n";
	}
	return 0;
}