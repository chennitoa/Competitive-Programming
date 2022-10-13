#include <iostream>
#include <algorithm>
#define f first
#define s second

using namespace std;

int n, m, a[100000];
long long b[100000], c[100000], bp[100000], cp[100000];

pair<long long, long long> s[100000];

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		int r, t;
		cin >> r >> t;
		s[i] = make_pair(r, t);
	}
	bp[0] = 0;
	for (int i = 0; i < n - 1; i++) {
		b[i] = (long long) max(0, a[i] - a[i + 1]);
		bp[i + 1] = bp[i] + b[i];
	}
	cp[n - 1] = 0;
	for (int i = n - 1; i > 0; i--) {
		c[i] = (long long) max(0, a[i] - a[i - 1]);
		cp[i - 1] = cp[i] + c[i];
	}
	for (int i = 0; i < m; i++) {
		if (s[i].f < s[i].s) {
			cout << bp[s[i].s - 1] - bp[s[i].f - 1] << "\n"; 
		}
		else {
			cout << cp[s[i].s - 1] - cp[s[i].f - 1] << "\n";
		}
	}
}