#include <iostream>
#include <algorithm>

using namespace std;
int T, N, K;
int nums[30];
int diff[31];

int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N >> K;
		for (int j = 0; j < 31; j++) {
			diff[j] = 0;
		}
		for (int j = 0; j < N; j++) {
			cin >> nums[j];
		}
		sort(nums, nums + N);
		diff[0] = 2 * (nums[0] - 1);
		for (int j = 1; j < N; j++) {
			diff[j] = (nums[j] - nums[j - 1]);
		}
		diff[N] = 2 * (K - nums[N - 1]);
		sort(diff, diff + N + 1);
		if (diff[N] == 1) diff[N] = 0;
		if (diff[N - 1] == 1) diff[N - 1] = 0;
		int numWin = (diff[N] + diff[N - 1]) / 2;
		double total = (double) numWin / K;
		cout << "Case #" << i + 1 << ": " << total << "\n";
	}
}