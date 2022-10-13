#include <iostream>

using namespace std;

long long t, m, n, x;

int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> m >> x;
		long long row = (x - 1) / n;
		long long column = (x - 1) % n;
		long long ans = column * m + row + 1;
		cout << ans << "\n";
	}
	return 0;
}