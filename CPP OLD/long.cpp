#include <iostream>
#include <string>

using namespace std;

int n;
string s;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s.length() > 10) cout << s.at(0) << s.length() - 2 << s.at(s.length() - 1) << "\n";
		else cout << s << "\n";
	}
	return 0;
}