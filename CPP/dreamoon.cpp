#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

string s1, s2;
double factorial[11] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};

int main() {
	cin >> s1 >> s2;
	int dir = 0;
	int ur = 0;
	for (int i = 0; i < s1.length(); i++) {
		if (s1.at(i) == '+') {
			dir++;
		}
		else {
			dir--;
		}
		if (s2.at(i) == '+') {
			dir--;
		}
		else if (s2.at(i) == '?') {
			ur++;
		}
		else {
			dir++;
		}
	}
	if (abs(dir) > ur || (dir + ur) % 2 == 1) {
		cout << "0\n";
	}
	else {
		int dist = (dir + ur) / 2;
		cout.precision(10);
		double answer = pow(0.5, ur) * factorial[ur] / (factorial[dist] * factorial[ur - dist]);
		cout << fixed << answer << "\n";
	}
}