#include <iostream>
#include <algorithm>

using namespace std;

int n;
long l;
int lanterns[1000];
int distances[1001];

int main() {
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		cin >> lanterns[i];
	}
	sort(lanterns, lanterns + n);
	for (int i = 0; i < n - 1; i++) {
		distances[i + 1] = lanterns[i + 1] - lanterns[i];
	}
	distances[0] = lanterns[0] * 2;
	distances[n] = (l - lanterns[n - 1]) * 2;
	sort(distances, distances + n + 1);
	double maxD = (double) distances[n] / 2;
	cout << fixed << maxD << "\n";
	return 0;
}