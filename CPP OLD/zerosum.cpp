/*
ID: achenni1
TASK: zerosum
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

int N;
int used[9];
ifstream fin("zerosum.in");
ofstream fout("zerosum.out");

bool calculate(int* used) {
	int sum = 0;
	int numbers[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	for (int i = 0; i < N; i++) {
		if (used[i] == 0) {
			numbers[i - 1] = numbers[i - 1] * 10 + numbers[i];
			if (i < N - 1) {
				if (used[i + 1] == 0) {
					numbers[i - 1] = numbers[i - 1] * 10 + numbers[i + 1];
					if (i < N - 2) {
						if (used[i + 2] == 0) return false;
					}
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		if (used[i] == 1) {
			sum += numbers[i];
		}
		else if (used[i] == 2) {
			sum -= numbers[i];
		}
	}
	if (sum == 0) return true;
	return false;
}

void find(int* used, int nd) {
	if (nd == N) {
		if (calculate(used) == true) {
			for (int i = 0; i < N - 1; i++) {
				fout << i + 1;
				if (used[i + 1] == 0) fout << " ";
				if (used[i + 1] == 1) fout << "+";
				if (used[i + 1] == 2) fout << "-";
			}
			fout << N << "\n";
		}
		return;
	}
	for (int i = 0; i < 3; i++) {
		used[nd] = i;
		find(used, nd + 1);
	}
	return;
}

int main() {
	fin >> N;
	for (int i = 0; i < 9; i++) {
		used[i] = 0;
	}
	used[0] = 1;
	find(used, 1);
	return 0;
}