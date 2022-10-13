#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int t;
long long a, k;

int numDigits(long long num) {
	int result = 0;
	while (num > 9) {
		num /= 10;
		result++;
	}
	return result + 1;
}

int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> a >> k;
		while (k > 1) {
			int aLen = numDigits(a);
			pair<int, int> maxDigit = make_pair(0, 0);
			pair<int, int> minDigit = make_pair(9, 0);
			long long b = a;
			for (int i = 0; i < aLen; i++) {
				int c = b % 10;
				if (c >= maxDigit.first) {
					maxDigit = make_pair(c, i);
				}
				if (c <= minDigit.first) {
					minDigit = make_pair(c, i);
				}
				b /= 10;
			}
			if (minDigit.first == 0) {
				break;
			}
			b = a;
			int minIndex = min(minDigit.second, maxDigit.second);
			int d = 0;
			for (int i = 0; i < minIndex; i++) {
				d += (b % 10) * pow(10, i);
				b /= 10;
			}
			k--;
			a += minDigit.first * maxDigit.first;
		}
		cout << a << "\n";
	}
}