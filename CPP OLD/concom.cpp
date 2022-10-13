/*
ID: achenni1
TASK: concom
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;
int companies[101][101];
bool companies2[101][101];

int N;

int main() {
	ifstream fin("concom.in");
	ofstream fout("concom.out");
	fin >> N;
	int x, y, z;
	while (fin >> x) {
		fin >> y;
		fin >> z;
		companies[x][y] += z;
		if (companies[x][y] > 50) companies2[x][y] = true;
		
	}
	for (int a = 1; a < 101; a++) {
		companies2[a][a] = true;
	}
	for (int a = 1; a < 101; a++) {
		for (int b = 1; b < 101; b++) {
			int stockOwned = 0;
			for (int i = 1; i < 101; i++) {
				if (companies[a][i] > 50 || companies2[a][i] == true) {
					stockOwned += companies[i][b];
				}
			}
			if (stockOwned > 50) companies2[a][b] = true;
		}
	}
	for (int a = 1; a < 101; a++) {
		for (int b = 1; b < 101; b++) {
			for (int i = 1; i < 101; i++) {
				if (companies2[a][b] == true && companies2[b][i] == true) {
					companies2[a][i] = true;
				}
			}
		}
	}
	for (int a = 1; a < 101; a++) {
		for (int b = 1; b < 101; b++) {
			int stockOwned = 0;
			for (int i = 1; i < 101; i++) {
				if (companies[a][i] > 50 || companies2[a][i] == true) {
					stockOwned += companies[i][b];
				}
			}
			if (stockOwned > 50) companies2[a][b] = true;
		}
	}
	for (int a = 1; a < 101; a++) {
		for (int b = 1; b < 101; b++) {
			for (int i = 1; i < 101; i++) {
				if (companies2[a][b] == true && companies2[b][i] == true) {
					companies2[a][i] = true;
				}
			}
		}
	}
	for (int a = 1; a < 101; a++) {
		for (int b = 1; b < 101; b++) {
			int stockOwned = 0;
			for (int i = 1; i < 101; i++) {
				if (companies[a][i] > 50 || companies2[a][i] == true) {
					stockOwned += companies[i][b];
				}
			}
			if (stockOwned > 50) companies2[a][b] = true;
		}
	}
	for (int a = 1; a < 101; a++) {
		for (int b = 1; b < 101; b++) {
			for (int i = 1; i < 101; i++) {
				if (companies2[a][b] == true && companies2[b][i] == true) {
					companies2[a][i] = true;
				}
			}
		}
	}
	for (int a = 1; a < 101; a++) {
		for (int b = 1; b < 101; b++) {
			int stockOwned = 0;
			for (int i = 1; i < 101; i++) {
				if (companies[a][i] > 50 || companies2[a][i] == true) {
					stockOwned += companies[i][b];
				}
			}
			if (stockOwned > 50) companies2[a][b] = true;
		}
	}
	for (int a = 1; a < 101; a++) {
		for (int b = 1; b < 101; b++) {
			for (int i = 1; i < 101; i++) {
				if (companies2[a][b] == true && companies2[b][i] == true) {
					companies2[a][i] = true;
				}
			}
		}
	}
	for (int a = 1; a < 101; a++) {
		for (int b = 1; b < 101; b++) {
			int stockOwned = 0;
			for (int i = 1; i < 101; i++) {
				if (companies[a][i] > 50 || companies2[a][i] == true) {
					stockOwned += companies[i][b];
				}
			}
			if (stockOwned > 50) companies2[a][b] = true;
		}
	}
	for (int a = 1; a < 101; a++) {
		for (int b = 1; b < 101; b++) {
			for (int i = 1; i < 101; i++) {
				if (companies2[a][b] == true && companies2[b][i] == true) {
					companies2[a][i] = true;
				}
			}
		}
	}
	for (int a = 1; a < 101; a++) {
		for (int b = 1; b < 101; b++) {
			int stockOwned = 0;
			for (int i = 1; i < 101; i++) {
				if (companies[a][i] > 50 || companies2[a][i] == true) {
					stockOwned += companies[i][b];
				}
			}
			if (stockOwned > 50) companies2[a][b] = true;
		}
	}
	for (int a = 1; a < 101; a++) {
		for (int b = 1; b < 101; b++) {
			for (int i = 1; i < 101; i++) {
				if (companies2[a][b] == true && companies2[b][i] == true) {
					companies2[a][i] = true;
				}
			}
		}
	}
	for (int a = 1; a < 101; a++) {
		for (int b = 1; b < 101; b++) {
			int stockOwned = 0;
			for (int i = 1; i < 101; i++) {
				if (companies[a][i] > 50 || companies2[a][i] == true) {
					stockOwned += companies[i][b];
				}
			}
			if (stockOwned > 50) companies2[a][b] = true;
		}
	}
	for (int a = 1; a < 101; a++) {
		for (int b = 1; b < 101; b++) {
			for (int i = 1; i < 101; i++) {
				if (companies2[a][b] == true && companies2[b][i] == true) {
					companies2[a][i] = true;
				}
			}
		}
	}
	for (int a = 1; a < 101; a++) {
		for (int b = 1; b < 101; b++) {
			int stockOwned = 0;
			for (int i = 1; i < 101; i++) {
				if (companies[a][i] > 50 || companies2[a][i] == true) {
					stockOwned += companies[i][b];
				}
			}
			if (stockOwned > 50) companies2[a][b] = true;
		}
	}
	for (int a = 1; a < 101; a++) {
		for (int b = 1; b < 101; b++) {
			for (int i = 1; i < 101; i++) {
				if (companies2[a][b] == true && companies2[b][i] == true) {
					companies2[a][i] = true;
				}
			}
		}
	}
	int counter = 0;
	for (int i = 1; i < 101; i++) {
		for (int j = 1; j < 101; j++) {
			if (i != j) {
				if (companies2[i][j] == true) {
					fout << i << " " << j << "\n";
					counter++;
				}
			}
		}
	}
	
	if (counter == 0) fout << "\n";
	return 0;
}