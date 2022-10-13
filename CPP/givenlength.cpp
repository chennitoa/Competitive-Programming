#include <iostream>

using namespace std;

int main() {
	int m, s;
	int minNum = 0;
	int maxNum = 0;
	cin >> m >> s;
	int ninesFit = s / m;
	int remain = s - (ninesFit * 9);
	if (ninesFit > m || (ninesFit == m && remain > 0) {
		cout << "-1 -1\n";
	}
	else {
		for (int i = 0; i < ninesFit; i++) {
			cout << 9;
		}
		
		cout << remain << " ";
		
	}
		