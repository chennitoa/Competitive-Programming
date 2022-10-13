#include <iostream>
#include <cmath>

using namespace std;
int t, n;

int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		if (n % 2 == 0) {
			cout << n / 2 << " " << n / 2 << "\n";
		}
		else {
			int factor = 1;
			for (int i = 2; i <= (int) sqrt(n) + 1; i++) {
				if (n % i == 0) {
					factor = i;
					break;
				}
			}
			if (factor == 1) {
				cout << 1 << " " << n - 1 << "\n";
			}
			else {
				int lFactor = n / factor;
				cout << lFactor << " " << n - lFactor << "\n";
			}
		}
	}
}