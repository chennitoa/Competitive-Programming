#include <iostream>

using namespace std;
int N;
char breeds[500000];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> breeds[i];
	}
	int solution;
	for (int i = 3; i < N; i++) {
		for (int j = 0; j <= N - i; j++) {
			int Gfound = 0;
			int Hfound = 0;
			for (int k = j; k < j + i; k++) {
				if (breeds[k] == 'G') {
					Gfound++;
				}
				if (breeds[k] == 'H') {
					Hfound++;
				}
				if (Gfound > 1 && Hfound > 1) {
					break;
				}
			}
			if (Gfound == 1 || Hfound == 1) solution++;
		}
	}
	cout << solution << "\n";
}