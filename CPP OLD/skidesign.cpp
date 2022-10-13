/*
ID: achenni1
TASK: skidesign
LANG: C++                
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#define MAXN 1000

using namespace std;
int N;
int hill[MAXN];

int main() {
	ofstream fout("skidesign.out");
	ifstream fin("skidesign.in");
	fin >> N;
	for (int i = 0; i < N; i++) {
		fin >> hill[i];
	}
	sort(hill, hill + N);
	int minPrice = 2147483647;
	for (int i = 0; i <= 83; i++) {
		int total = 0;
		for (int j = 0; j < N; j++) {
			if (hill[j] < i) {
				int temp = i - hill[j];
				total += temp * temp;
			}
			else if (hill[j] > i + 17) {
				int temp = hill[j] - (i + 17);
				total += temp * temp;
			}
			
		}
		minPrice = min(minPrice, total);
	}
	fout << minPrice << "\n";
	return 0;
}