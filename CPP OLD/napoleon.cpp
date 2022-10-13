#include <iostream>

using namespace std;

int t, n;
bool drenched[200001];

int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		int a;
		for (int j = 0; j < 200001; j++) {
			drenched[j] = false;
		}
		for (int j = 0; j < n; j++) {
			cin >> a;
			for (int k = 0; k < a; k++) {
				if (j - k < 0) break;
				drenched[j - k] = true;
			}
		}
		for (int j = 0; j < n; j++) {
			if (j != n - 1) cout << drenched[j] << " ";
			else cout << drenched[j] << "\n";
		}
	}
	return 0;
}