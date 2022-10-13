#include <iostream>

using namespace std;
int n;

int main() {
	cin >> n;
	if (n >= 5) {
		if (n % 2 == 0) {
			for (int i = n; i > 0; i-=2) {
				cout << i << " ";
			}
			for (int i = n - 1; i > 2; i-=2) {
				cout << i << " ";
			}
			cout << 1 << "\n";
			return 0;
		}
		else {
			for (int i = n; i > 0; i-=2) {
				cout << i << " ";
			}
			for (int i = n - 1; i > 2; i-=2) {
				cout << i << " ";
			}
			cout << 2 << "\n";
			return 0;
		}
	}
	else if (n == 4) {
		cout << "2 4 1 3\n";
		return 0;
	}
	else if (n == 3 || n == 2) {
		cout << "NO SOLUTION\n";
		return 0;
	}
	else {
		cout << 1 << "\n";
		return 0;
	}
}