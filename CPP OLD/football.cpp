#include <iostream>

using namespace std;
string s;

int main() {
	cin >> s;
	int counter1, counter0;
	counter1 = counter0 = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s.at(i) == '1') {
			counter1++;
			counter0 = 0;
		}
		if (s.at(i) == '0') {
			counter0++;
			counter1 = 0;
		}
		if (counter1 == 7 || counter0 == 7) {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}