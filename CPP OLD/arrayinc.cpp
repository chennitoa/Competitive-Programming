#include <iostream>

using namespace std;

int n;
long long nums[200001];

int main() {
	cin >> n;
	long long total = 0;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	for (int i = 1; i < n; i++) {
		if (nums[i] < nums[i - 1]) {
			total += (nums[i - 1] - nums[i]);
			nums[i] = nums[i - 1];
		}
	}
	cout << total << "\n";
	return 0;
}