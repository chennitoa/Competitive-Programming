/*
ID: achenni1
TASK: subset
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int N;
int ans, total;
unsigned long long int buckets[1024];

int main() {
	ifstream fin("subset.in");
	ofstream fout("subset.out");
	fin >> N;
	total = N * (N + 1);
	if (total % 4 != 0) {
		fout << 0 << "\n";
		return 0;
	}
	total /= 4;
	buckets[0] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = total; j >= i; j--) {
			buckets[j] += buckets[j - i];
		}
	}
	fout << buckets[total]/2 << "\n";
	return 0;
}