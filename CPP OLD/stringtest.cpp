#include <iostream>

using namespace std;

string s;

int main() {
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		char a = s.at(i);
		if (a != 'a' && a != 'A' && a != 'e' && a != 'E' && a != 'i' && a != 'I' && a != 'o' && a != 'O' && a != 'u' && a != 'U' && a != 'y' && a != 'Y') {
			if (a < 'a') {
				a -= 'A';
				a += 'a';
			}
			cout << "." << a;
		}
	}
	cout << "\n";
	return 0;
}