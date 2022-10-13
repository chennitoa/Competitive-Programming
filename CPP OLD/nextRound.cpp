#include <iostream>

using namespace std;

int n, k;
int num;

int main() {
	cin >> n >> k;
	int total = 0;
	for (int i = 0; i < k; i++) {
		cin >> num;
		if (num > 0) total++;
	}
	int minNum = num;
	if (minNum == 0) {
		cout << total << "\n";
		return 0;
	}
	while (num == minNum && total < n + 1) {
		cin >> num;
		total++;
	}
	cout << total - 1 << "\n";
	return 0;
}