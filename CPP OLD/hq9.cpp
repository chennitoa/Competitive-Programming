#include <iostream>

using namespace std;
string s;

int main() {
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		char a = s.at(i);
		if (a == 'H' || a == 'Q' || a == '9') {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}