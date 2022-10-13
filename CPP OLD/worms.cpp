#include <iostream>

using namespace std;

int n, numsN[100000];
int m;
int sumN[100001];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> numsN[i];
	}
	sumN[0] = 0;
	for (int i = 0; i < n; i++) {
		sumN[i + 1] = sumN[i] + numsN[i];
	}
	cin >> m;
	int num;
	for (int i = 0; i < m; i++) {
		cin >> num;
		int hi = n + 1;
		int lo = 0;
		int mid = (hi + lo) / 2;
		while (sumN[mid] < num || sumN[mid - 1] >= num) {
			if (sumN[mid] < num) {
				lo = mid;
				mid = (hi + lo) / 2;
			}
			else {
				hi = mid;
				mid = (hi + lo) / 2;
			}
		}
		cout << mid << "\n";
	}
	return 0;
}