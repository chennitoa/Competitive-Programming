#include <iostream>

using namespace std;

string a, b;

int main() {
	cin >> a >> b;
	for (int i = 0; i < a.length(); i++) {
		if (a.at(i) != b.at(i)) {
			if (a.at(i) - 'a' != b.at(i) - 'A' && a.at(i) - 'A' != b.at(i) - 'a') {
				char fir, sec;
				if (a.at(i) < 'a') {
					fir = a.at(i) - 'A';
				}
				else {
					fir = a.at(i) - 'a';
				}
				if (b.at(i) < 'a') {
					sec = b.at(i) - 'A';
				}
				else {
					sec = b.at(i) - 'a';
				} 
				if (fir > sec) {
					cout << "1\n";
					return 0;
				}
				else {
					cout << "-1\n";
					return 0;
				}
			}
		}
	}
	cout << "0\n";
	return 0;
}