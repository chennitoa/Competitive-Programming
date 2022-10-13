#include <iostream>
#include <cmath>

using namespace std;

int reverse (int number) {
	if (number > 100 && number < 1000) {
		int a = number / 100;
		int b = number / 10 - 10 * a;
		int c = number - 100 * a - 10 * b;
		return a + b * 10 + c * 100;
	}
	if (number > 1000 && number < 10000) {
		int a = number / 1000;
		int b = number / 100 - 10 * a;
		int c = number / 10 - 100 * a - 10 * b;
		int d = number - 1000 * a - 100 * b - 10 * c;
		return a + b * 10 + c * 100 + d * 1000;
	}
	if (number > 10000 && number < 100000) {
		int a = number / 10000;
		int b = number / 1000 - 10 * a;
		int c = number / 100 - 100 * a - 10 * b;
		int d = number / 10 - 1000 * a - 100 * b - 10 * c;
		int e = number - 10000 * a - 1000 * b - 100 * c;
		return a + b * 10 + c * 100 + d * 1000 + e * 10000;
	}
	if (number > 100000) {
		int a = number / 100000;
		int b = number / 10000 - 10 * a;
		int c = number / 1000 - 100 * a - 10 * b;
		int d = number / 100 - 1000 * a - 100 * b - 10 * c;
		int e = number / 10 - 10000 * a - 1000 * b - 100 * c;
		int f = number - 100000 * a - 10000 * b - 1000 * c - 100 * d - 10 * e;
		return a + b * 10 + c * 100 + d * 1000 + e * 10000 + f * 100000;
	}
	return 0;
}

int main() {
	for (int i = 100; i < 200000; i++) {
		//cout << i << " " << reverse(i) << " " << reverse(i) + 450 << "\n";
		if (i == reverse(i) + 450) cout << "FOUND\n" << i << " " << reverse(i) << "\n";
	}
}