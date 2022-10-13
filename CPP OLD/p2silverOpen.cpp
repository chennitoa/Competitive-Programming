#include <iostream>
#include <algorithm>

using namespace std;

int T, N;

long long integers[7];

int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> integers[j];
		}
		sort(integers, integers + N);
		if (N == 7) {
			bool isTrue = true;
			long long A = integers[0];
			long long B = integers[1];
			long long C = integers[N - 1] - A - B;
			cout << A << B << C << "\n";
			if (integers[2] != C && integers[3] != C) {
				isTrue = false;
			}
			if (integers[2] == C) {
				if (integers[3] != A + B || integers[4] != C + A || integers[5] != C + B) {
					isTrue = false;
				}
			}
			else if (integers[3] == C) {
				if (integers[2] != A + B || integers[4] != C + A || integers[5] != C + B) {
					isTrue = false;
				}
			}
			if (isTrue == true) {
				cout << 1 << "\n";
			}
			else {
				cout << 0 << "\n";
			}
		}
		if (N == 6) {
			
		return 0;
	}
}