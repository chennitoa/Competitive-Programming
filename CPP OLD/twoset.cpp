#include <iostream>

using namespace std;
bool used[1000001];
int n;

int main() {
	cin >> n;
	long long total = (n + 1) * n;
	if (total % 4 != 0) {
		cout << "NO\n";
		return 0;
	}
	else {
		cout << "YES\n";
	}
	long long counter = 0;
	int counterNum = 0;
	for (long long i = n; i > 1; i--) {
		if (counter + i >= total / 4) {
			used[total / 4 - counter - 1] = true;
			counterNum++;
			break;
		}
		counter += i;
		counterNum++;
		used[i - 1] = true;
	}
	cout << counterNum << "\n";
	for (int i = 0; i < n - 1; i++) {
		if (used[i] == true) cout << i + 1 << " ";
	}
	cout << n << "\n" << n - counterNum << "\n";
	int counterNum2 = 0;
	for (int i = 0; counterNum2 <= n - counterNum && i < n; i++) {
		if (used[i] == false) {
			cout << i + 1;
			counterNum2++;
		}
		if (counterNum2 < n - counterNum) cout << " ";
		else cout << "\n";
	}
	return 0;
}
	