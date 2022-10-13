#include <iostream>

using namespace std;

int T;
int n, k;
string s;
	
int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n >> k;
		cin >> s;
		bool wordTrue = true;
		if (2 * k + 1 > n) wordTrue = false;
		for (int i = 1; i <= k; i++) {
			if (s.at(i) != s.at(n - i - 1)) wordTrue = false;
		}
		if (wordTrue) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
	