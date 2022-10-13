#include <iostream>

using namespace std;

int N;

int maze[25][25];
bool filled[25][25];
bool graph[25][25][25][25];
char toe[3][3];

void fill(int x, int y, int lastX, int lastY) {
	if (filled[x][y] == false && maze[i][j] > 0) {
		filled[x][y] = true;
		if (filled[x][y] > 2) {
			graph[lastX][lastY][x][y] = true;
			graph[x][y][lastX][lastY] = true;
			lastX = x;
			lastY = y;
		}
		fill(x + 1, y, lastX, lastY);
		fill(x - 1, y, lastX, lastY);
		fill(x, y + 1, lastX, lastY);
		fill(x, y - 1, lastX, lastY);
	}
	return;
}

void play(int x, int y, char* toe) {
	

int main() {
	cin >> N;
	int firstX, firstY;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char a, b, c;
			cin >> a >> b >> c;
			if (a == '#') {
				maze[i][j] = 0;
			}
			else if (a == 'B') {
				maze[i][j] = 1;
				firstX = i;
				firstY = j;
			}
			else if (a == '.') {
				maze[i][j] = 2;
			}
			else {
				if (a == 'O') {
					maze[i][j] = (b - 1) * 3 + c + 2;
				}
				else if (a == 'M') {
					maze[i][j] = (b - 1) * 3 + c + 11;
				}
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			toe[i][j] = '.';
		}
	}
	fill(firstX, firstY, firstX, firstY);
	play(firstX, firstY, toe);
}