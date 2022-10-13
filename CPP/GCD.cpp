#include <iostream>

using namespace std;

int t, n;
int odd[2000], even[2000];

int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		int a = 0;
		int b = 0;
		for (int j = 0; j < 2 * n; j++) {
			int k;
			cin >> k;
			if ((k % 2) == 0) {
				even[a] = j;
				a++;
			}
			else {
				odd[b] = j;
				b++;
			}
		}
		if (b == 0) a -= 2;
		for (int j = 0; j < a / 2; j++) {
			cout << even[j * 2] + 1 << " " << even[j * 2 + 1] + 1 << "\n";
		}
		if (b % 2 == 0 && a % 2 == 0) b -= 2;
		for (int j = 0; j < b / 2; j++) {
			cout << odd[j * 2] + 1 << " " << odd[j * 2 + 1] + 1 << "\n";
		}
	}
}