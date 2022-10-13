#include <iostream>

using namespace std;
int x;

int main() {
	cin >> x;
	int numOdd = 0;
	int numEven = 0;
	for (int i = 1; i < x + 1; i++) {
		if (x % i == 0 && i % 2 == 0) {
			numEven++;
		}
		else if (x % i == 0 && i % 2 == 1) {
			numOdd++;
		}
	}
	if (numOdd == numEven) cout << "yes\n";
	else cout << "no\n";
	return 0;
}