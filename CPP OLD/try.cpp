
#include <iostream>
#include <math.h>
#include <numeric>

using namespace std;

int gcd(int x, int y) {
	if (x % 2 == 0) return false;
	if (x % 3 == 0) return false;
	if (x % 5 == 0) return false;
	if (x % 7 == 0) return false;
	return true;
}

int main() {
	for (int i = 1; i < 50; i++) {
		for (int j = 1; j < 50; j++) {
			if (gcd(i + j, 210) == true) {
				if (j % i != 0 && i % j != 0) {
					unsigned long long a = pow(i, i);
					unsigned long long b = pow(j, j);
					cout << a << " " << b << "\n";
					if (a % b == 0 || b % a == 0) cout << i << " " << j << "\n";
				}
			}
		}
	}
	return 0;
}