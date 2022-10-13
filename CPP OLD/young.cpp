#include <iostream>

using namespace std;

int n, a, b, c;

int main() {
	cin >> n;
	int a1, b1, c1;
	for (int i = 0; i < n; i++) {
		cin >> a1 >> b1 >> c1;
		a += a1;
		b += b1;
		c += c1;
	}
	if (a == 0 && b == 0 && c == 0) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}
	return 0;
}