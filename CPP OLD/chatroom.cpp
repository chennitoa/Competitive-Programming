#include <iostream>

using namespace std;

char hello[5] = {'h', 'e', 'l', 'l', 'o'};
string s;

int main() {
	cin >> s;
	int j = 0;
	for (int i = 0; i < s.length(); i++) {
		if (j < 5) {
			if (hello[j] == s.at(i)) j++;
		}
	}
	if (j == 5) {
		cout << "YES\n";
		return 0;
	}
	cout << "NO\n";
	return 0;
}