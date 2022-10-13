#include <iostream>

using namespace std;

int n, m, a, b;

int main() {
	cin >> n >> m >> a >> b;
	int remainder = n % m;
	if (b > m * a) {
		cout << n * a << "\n";
	}
	else {
		if (remainder * a > b) {
			cout << (n / m + 1) * b << "\n";
		}
		else {
			cout << (n / m) * b + remainder * a << "\n";
		}
	}
	return 0;
}