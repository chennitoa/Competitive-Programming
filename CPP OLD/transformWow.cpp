#include <iostream>
#include <map>

using namespace std;
int t, n;
map<long long> nums;

int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		for (int j = 0; j < 10; j++) {
			nums[j] = 0;
		}
		int num;
		long long maxNum = 0;
		for (int j = 0; j < n; j++) {
			cin >> num;
			nums[num - 1]++;
			maxNum = max(nums[num - 1], maxNum);
		}
		if (maxNum > n - maxNum) cout << 2 * maxNum - n << "\n";
		else cout << 0 << "\n";

	}
	return 0;
}