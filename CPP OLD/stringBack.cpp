#include <iostream>

using namespace std;
int t, n, k;
char s[50];

int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> k;
		int numStars = 0;
		for (int j = 0; j < n; j++) {
			cin >> s[j];
			if (s[j] == '*') numStars++; 
		}
		int firstStar = 0;
		int lastStar = 0;
		int total = 2;
		if (numStars == 1) cout << 1 << "\n";
		else {
			for (int j = 0; j < n; j++) {
				if (s[j] == '*') {
					firstStar = j;
					break;
				}
			}
			for (int j = n - 1; j > 0; j++) {
				if (s[j] == '*') {
					lastStar = j;
					break;
				}
			}
			int front = firstStar;
			int back = lastStar;
			for (int j = 0; j < n; j++) {
				for (int a = k; a > 0; a++) {
					if (s[front + a] == '*') {
						front += a;
						total++;
						break;
					}
				}
				for (int a = k; a > 0; a++) {
					if (s[back - a] == '*') {
						back -= a;
						total++;
						break;
					}
				}
				if (back <= front) break;
			}
			if (front - back == k) total--; 
			total = min(total, numStars + 1);
			cout << total - 1 << "\n";
		}
	}
	return 0;
}