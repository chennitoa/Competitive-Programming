#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int t, n;

int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		int used[101];
		for (int j = 0; j < n; j++) {
			cin >> used[j];
		}
		sort(used, used + n);
		if (used[0] != 0) {
			for (int j = 0; j < n - 1; j++) {
				cout << used[j] << " ";
			}
			cout << used[n - 1] << "\n";
		}
		else {
			vector<int> notUsed;
			int maxNum = 0;
			for (int j = 0; j < n; j++) {
				for (int k = j + 1; k < n; k++) {
					if (used[j] == used[k] - 1) {
						maxNum = used[k];
						j = k - 1;
						break;
					}
					else {
						notUsed.push_back(used[k]);
					}
				}
			}
			for (int j = 0; j < maxNum; j++) {
				cout << j << " ";
			}
			if (notUsed.size() == 0) cout << maxNum << "\n";
			else cout << maxNum << " ";
			for (int j = 0; j < notUsed.size(); j++) {
				if (j != notUsed.size() - 1) {
					cout << notUsed[j] << " ";
				}
				else cout << notUsed[j] << "\n";
			}
		}
	}
	return 0;
}