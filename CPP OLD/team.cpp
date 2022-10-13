#include <iostream>

using namespace std;

int n;
int a, b, c;
int total;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		if (a + b + c > 1) total++;
	}
	cout << total << "\n";
}