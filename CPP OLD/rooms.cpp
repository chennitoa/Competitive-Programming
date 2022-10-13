#include <iostream>

using namespace std;

int n, m;
bool filled[1001][1001];
char array[1001][1001];
int colors;

void fill(int x, int y) {
	if (filled[x][y] == false && array[x][y] == '.') {
		filled[x][y] = true;
		if (array[x + 1][y] == '.') fill(x + 1, y);
		if (array[x - 1][y] == '.') fill(x - 1, y);
		if (array[x][y + 1] == '.') fill(x, y + 1);
		if (array[x][y - 1] == '.') fill(x, y - 1);
	}
	return;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> array[i][j];
		}
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (filled[i][j] == false && array[i][j] == '.') {
				colors++;
			}
			fill(i, j);
		}
	}
	cout << colors << "\n";
	return 0;
}
			