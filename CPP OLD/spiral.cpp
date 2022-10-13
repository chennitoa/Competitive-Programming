#include <iostream>

using namespace std;

int t;

int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		long long x, y;
		cin >> y >> x;
		long long maxRow = max(x, y) - 1;
		long long midNum = maxRow * maxRow + maxRow + 1;
		if (maxRow % 2 == 1) {
			if (y > x) {
				cout << midNum + (maxRow - x + 1) << "\n";
			}
			else {
				cout << midNum - (maxRow - y + 1) << "\n";
			}
		}
		else {
			if (y > x) {
				cout << midNum - (maxRow - x + 1) << "\n";
			}
			else {
				cout << midNum + (maxRow - y + 1) << "\n";
			}
		}
	}
	return 0;
}	
		