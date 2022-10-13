#include <iostream>

using namespace std;
int n, t;


int main() {
	cin >> n >> t;
	if (t < 10) {
		for (int i = 0; i < n; i++) {
			cout << t;
		}
		cout << "\n";
	}
	else if (n == 1) {
		cout << -1 << "\n";
	}
	else {
		cout << 1;
		for (int i = 1; i < n; i++) {
			cout << 0;
		}
		cout << "\n";
	}
}