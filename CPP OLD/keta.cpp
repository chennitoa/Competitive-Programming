#include <iostream>
#include <algorithm>

using namespace std;

int n;

int main() {
	cin >> n;
	int total = 0;
	int maxSeq = 0;
	int a = 0;
	int b = 0;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a < b) {
			maxSeq = max(maxSeq, total);
			total = 0;
		}
		total++;
		b = a;
	}
	maxSeq = max(maxSeq, total);
	cout << maxSeq << "\n";
	return 0;
}