#include <iostream>
#include<unordered_map>

using namespace std;
int t, n;
long long a[200000];

int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		unordered_map<int, bool> threeSumNum;
		for (int j = 0; j < n; j++) {
			cin >> a[j];
			threeSumNum[j] = true;
		}
		bool found = true;
		for (int j = 0; j < n - 2; j++) {
			for (int k = j + 1; k < n - 1; k++) {
				for (int l = k + 1; l < n; l++) {
					if (!threeSumNum[a[j] + a[k] + a[l]]) {
						if (t == 1000) {
							cout << "Checking " << a[j] << " " << a[k] << " " << a[l] << a[j] + a[k] + a[l] << "\n";
							cout << threeSumNum[a[j] + a[k] + a[l]] << "\n";
						}
						found = false;
						break;
					}
				}
				if (!found) break;
			}
			if (!found) break;
		}
		if (found) cout << "YES\n";
		else cout << "NO\n";
	}
}