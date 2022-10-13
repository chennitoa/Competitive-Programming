#include <iostream>

using namespace std;

int n;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		long long total = 0;
		long long sizeT = i * i;
		if (i == 1) {
			cout << 0 << "\n";
		}
		else if (i == 2) {
			cout << 6 << "\n";
		}
		else if (i == 3) {
			cout << 28 << "\n";
		}
		else if (i == 4) {
			cout << 96 << "\n";
		}
		else {
			total += 16 * (sizeT - 4);
			total += (i - 4) * 4 * (sizeT - 7);
			total += (i - 4) * 4 * (sizeT - 5);
			total += (i - 4) * (i - 4) * (sizeT - 9);
			total /= 2;
			cout << total << "\n";
		}
	}
	return 0;
}