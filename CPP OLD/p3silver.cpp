#include <bits/stdc++.h>
using namespace std;
#define MAXN 500


//Squares are either 100, less than 100, or greater than 100
//Let <100 be 0, =100 be 1, >100 be 2
//For all cases of 100, 

int N;
int grid[500][500];
int total;

int check(int x,int y,int i,int j) {
	bool foundHundred = false;
	for (int q = 0; q < x; q ++) {
		for (int w = 0; w < y; w ++) {
			if (grid[i + q] [w + j] == 0) {
				goto END;
			}	
			else if (grid[i + q] [w + j] == 1) {
				foundHundred = true;
			}
		}
	} 
	if(foundHundred == true) {
		return 1;
		cout << "1" << "\n";
	}
	END:	
	return 0;	
	cout << "0" << "\n";	
}

int search(int x,int y) {
	int subtotal = 0;
	for (int i = 0; i < N; i ++) {
		for (int j = 0; j < N; j ++) {
			if(check(x, y, i, j) == true) subtotal++;
		}
	}
	return subtotal;
}


int main() {
	cin >> N;
	for (int i = 0; i < N; i ++) {
		for (int j = 0; j < N; j ++) {
			int x;
			cin >> x;
			if (x < 100) {
				grid[i][j] = 0;
			}
			else if (x == 100) {
				grid[i][j] = 1;
			}
			else {
				grid[i][j] = 2;
			}
		}
	}
	//Search for differently sized rectangles
	
	for (int i = 1; i <= N; i ++) {
		for (int j = 1; j <= N; j ++) {
			total += search(i, j);
		}
	}
	
	cout << total;
}
