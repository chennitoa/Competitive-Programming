#include <iostream>
#include <algorithm>

using namespace std;

int n, cubes[100];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> cubes[i];
	}
	sort(cubes, cubes + n);
	for (int i = 0; i < n - 1; i++) {
		cout << cubes[i] << " ";
	}
	cout << cubes[n - 1] << "\n";
	return 0;
}