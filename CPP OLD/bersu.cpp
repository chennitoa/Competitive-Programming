#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n, m;
int boys[100], girls[100];

int main() {
	cin >> n;
	for (int a = 0; a < n; a++) {
		cin >> boys[a];
	}
	cin >> m;
	for (int a = 0; a < m; a++) {
		cin >> girls[a];
	}
	int i, j;
	i = j = 0;
	sort(boys, boys + n);
	sort(girls, girls + m);
	int total = 0;
	while (i < n && j < m) {
		if (abs(boys[i] - girls[j]) < 2) {
			total++;
			i++;
			j++;
		}
		else if (boys[i] > girls[j]) {
			j++;
		}
		else {
			i++;
		}
	}
	cout << total << "\n";
	return 0;
}