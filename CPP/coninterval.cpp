#include <iostream>
#include <algorithm>

using namespace std;
int N, M;
long long painted[5001];
long long dpainted[10001];

int main() {
	cin >> N >> M;
	for (int i = 0; i < 5000; i++) {
		painted[i] = 0;
	}
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		for (int i = a; i <= b; i++) {
			painted[i]++;
		}
		for (int i = a * 2; i <= b * 2; i++) {
			dpainted[i]++;
		}
	}
	for (int i = 0; i < 2 * M + 1; i++) {
		long long solution = 0;
		for (int j = i; j >= i - j; j--) {
			if (j == i - j) {
				solution = max(solution, painted[j] - dpainted[2 * j]);
			}
			else {
				solution = max(solution, min(painted[j], painted[i - j]) - dpainted[j * 2] ;
			}
		}
		cout << solution + dpainted[i] << "\n";
	}
}