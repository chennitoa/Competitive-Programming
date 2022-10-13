#include <iostream>

using namespace std;

int n, total;

char a, b, c;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		if (a == '+' || c == '+') total++;
		if (a == '-' || c == '-') total--;
	}
	cout << total << "\n";
	return 0;
}