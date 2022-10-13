#include <iostream>
#include <cmath>

using namespace std;
int T, R, C;
int heights[301][301];
int total;

void solve(int x, int y) {
	if (x > 0) {
		if (abs(heights[x - 1][y] - heights[x][y]) > 1) {
			total += abs(heights[x - 1][y] - heights[x][y]) - 1;
			if (heights[x - 1][y] > heights[x][y]) heights[x][y] = heights[x - 1][y] - 1;
			else heights[x - 1][y] = heights[x][y] - 1;
			solve(x, y);
			solve(x - 1, y);
		}
	}
	if (x < R - 1) {
		if (abs(heights[x + 1][y] - heights[x][y]) > 1) {
			total += abs(heights[x + 1][y] - heights[x][y]) - 1;
			if (heights[x +	1][y] > heights[x][y]) heights[x][y] = heights[x + 1][y] - 1;
			else heights[x + 1][y] = heights[x][y] - 1;
			solve(x, y);
			solve(x + 1, y);
		}
	}
	if (y > 0) {
		if (abs(heights[x][y - 1] - heights[x][y]) > 1) {
			total += abs(heights[x][y - 1] - heights[x][y]) - 1;
			if (heights[x][y - 1] > heights[x][y]) heights[x][y] = heights[x][y - 1] - 1;
			else heights[x][y - 1] = heights[x][y] - 1;
			solve(x, y);
			solve(x, y - 1);
		}
	}
	if (y < C - 1) {
		if (abs(heights[x][y + 1] - heights[x][y]) > 1) {
			total += abs(heights[x][y + 1] - heights[x][y]) - 1;
			if (heights[x][y + 1] > heights[x][y]) heights[x][y] = heights[x][y + 1] - 1;
			else heights[x][y + 1] = heights[x][y] - 1;
			solve(x, y);
			solve(x, y + 1);
		}
	}
	return;
}

int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> R >> C;
		for (int j = 0; j < R; j++) {
			for (int k = 0; k < C; k++) {
				cin >> heights[j][k];
			}
		}
		total = 0;
		for (int j = 0; j < R; j++) {
			for (int k = 0; k < C; k++) {
				solve(j, k);
			}
		}
		cout << "Case #" << i + 1 << ": " << total << "\n";
	}
	return 0;
}