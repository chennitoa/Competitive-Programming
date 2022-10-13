#include <iostream>
using namespace std;


int main() {
	char t;
	char x;
	int counter = 1;
	int maxCounter = 1;
	while (cin >> t) {
		if (t != x) {
			x = t;
			counter = 1;
		}
		else counter++;
		maxCounter = max(maxCounter, counter);
	}
	cout << maxCounter << "\n";
	return 0;
}