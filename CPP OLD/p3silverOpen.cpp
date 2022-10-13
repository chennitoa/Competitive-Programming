#include <iostream>
#include <algorithm>

using namespace std;

int N, K, L;
int ciat[100000];

int main() {
	cin >> N >> K >> L;
	for (int i = 0; i < N; i++) {
		cin >> ciat[i];
	}
	sort(ciat, ciat + N);
	bool foundAnswer = false;
	for (int i = N; i > 0; i--) {
		long ciatNeeded = 0;
		bool canUse = true;
		for (int j = N - 1; j > N - i - 1; j--) {
			if (i - ciat[j] > K) {
				canUse = false;
				break;
			}
			if (ciat[j] < i) {
				ciatNeeded += i - ciat[j];
			}
		}
		if (canUse == true) {
			if (ciatNeeded <= (long) K * L) {
				foundAnswer = true;
			}
		}
		if (foundAnswer == true) {
			cout << i << "\n";
			break;
		}
	}
	return 0;
}