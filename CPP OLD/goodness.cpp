#include <iostream>
#include <cmath>

using namespace std;

int T, N, K;
char theString[10001];

int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N >> K;
		for (int j = 0; j < N; j++) {
			cin >> theString[j];
		}
		int goodness = 0;
		for (int j = 0; j < N/2; j++) {
			if (theString[j] != theString[N - j - 1]) goodness++;
		}
		cout << "Case #" << i + 1 << ": " << abs(goodness - K) << "\n";
	}
}