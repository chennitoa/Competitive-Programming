#include <bits/stdc++.h>
using namespace std;
#define MAXN 10000

//As cows get added, calculate comfort and floodfill to check 

int N;
pair<int, int> cows[MAXN]; 
bool farm[3000][3000];
bool checkComfort(x, y) {
	

int main() {
	cin >> N;
	for(int i = 0, i < N, i++) {
		int x, y;
		cin >> x >> y;
		farm[x][y] = true;
		cows[i] = make_pair(x, y); 
		checkComfort(x, y) 
		
	}
	
	