#include <iostream>

using namespace std;

int M, N;

int main() {
	cin >> M >> N;
	int total = M * N;
	if (total % 2 == 0) cout << total / 2 << "\n";
	else cout << (total - 1) / 2 << "\n";
	return 0;
}