#include <iostream>
#include <algorithm>

using namespace std;

long long n, q, p[1000000], psum[1000000], x, y;

int main() {
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	sort(begin(p), end(p));
	int len = sizeof(p) / sizeof(p[0]);
	psum[0] = p[0];
	for (int i = 1; i < len; i++) {
		psum[i] = psum[i - 1] + p[i];
	}
	for (int i = 0; i < q; i++) {
		cin >> x >> y;
		long long ans = psum[len - 1 - x + y] - psum[len - 1 - x];
		cout << ans << "\n";
	}
}