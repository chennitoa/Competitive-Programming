#include <iostream>


pair<int, int> cows[100000];
int n, m;
char labyrinth[1000][1000];
using namespace std;



int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> labyrinth[i][j];
		}
	}
	