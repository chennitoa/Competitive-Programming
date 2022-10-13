#include <iostream>

using namespace std;
int n;
int nums[100];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	if (nums[0] % 2 != nums[1] % 2) {
		if (nums[0] % 2 == nums[2] % 2) {
			cout << 2 << "\n";
			return 0;
		}
		else if (nums[1] % 2 == nums[2] % 2) {
			cout << 1 << "\n";
			return 0;
		}
	}
	for (int i = 0; i < n; i++) {
		if (nums[0] % 2 != nums[i] % 2) {
			cout << i + 1 << "\n";
			return 0;
		}
	}
}