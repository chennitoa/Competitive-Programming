/*
ID: achenni1
TASK: ttwo
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#define f first
#define s second

using namespace std;

char grid[10][10];
pair<int, int> cows, farmer;

/* Direction Guide:
N is x - 1
S is x + 1
E is y + 1
W is y - 1
*/

int main() {
	ifstream fin("ttwo.in");
	ofstream fout("ttwo.out");
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			fin >> grid[i][j];
			if (grid[i][j] == 'C') cows = make_pair(i, j);
			if (grid[i][j] == 'F') farmer = make_pair(i, j);
		}
	}
	char directionC, directionF;
	directionC = directionF = 'N';
	for (int i = 0; i < 100000; i++) {
		switch (directionC) {
			case 'N':
				if (cows.f == 0 || grid[cows.f - 1][cows.s] == '*') {
					directionC = 'E';
				}
				else {
					cows = make_pair(cows.f - 1, cows.s);
				}
				break;
			case 'S':
				if (cows.f == 9 || grid[cows.f + 1][cows.s] == '*') {
					directionC = 'W';
				}
				else {
					cows = make_pair(cows.f + 1, cows.s);
				}
				break;
			case 'E':
				if (cows.s == 9 || grid[cows.f][cows.s + 1] == '*') {
					directionC = 'S';
				}
				else {
					cows = make_pair(cows.f, cows.s + 1);
				}
				break;
			case 'W':
				if (cows.s == 0 || grid[cows.f][cows.s - 1] == '*') {
					directionC = 'N';
				}
				else {
					cows = make_pair(cows.f, cows.s - 1);
				}
				break;
		}
		switch (directionF) {
			case 'N':
				if (farmer.f == 0 || grid[farmer.f - 1][farmer.s] == '*') {
					directionF = 'E';
				}
				else {
					farmer = make_pair(farmer.f - 1, farmer.s);
				}
				break;
			case 'S':
				if (farmer.f == 9 || grid[farmer.f + 1][farmer.s] == '*') {
					directionF = 'W';
				}
				else {
					farmer = make_pair(farmer.f + 1, farmer.s);
				}
				break;
			case 'E':
				if (farmer.s == 9 || grid[farmer.f][farmer.s + 1] == '*') {
					directionF = 'S';
				}
				else {
					farmer = make_pair(farmer.f, farmer.s + 1);
				}
				break;
			case 'W':
				if (farmer.s == 0 || grid[farmer.f][farmer.s - 1] == '*') {
					directionF = 'N';
				}
				else {
					farmer = make_pair(farmer.f, farmer.s - 1);
				}
				break;
		}
		if (farmer.f == cows.f && cows.s == farmer.s) {
			fout << i + 1 << "\n";
			return 0;
		}
	}
	fout << 0 << "\n";
	return 0;
}