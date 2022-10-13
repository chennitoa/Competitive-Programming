#include <iostream>

using namespace std;
int n;
bool nums[200001];

int main() {
	cin >> n;
	int k;
	for (int i = 0; i < n; i++) {
		cin >> k;
		nums[k] = true;
	}
	for (int i = 1; i <= n; i++) {
		if (nums[i] == false) {
			cout << i << "\n";
			return 0;
		}
	}
}