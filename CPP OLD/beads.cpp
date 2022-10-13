/*
ID: achenni1
TASK: beads
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#define MAXN 1050

using namespace std;

int N;
char String[MAXN];

int main() {
	ofstream fout ("beads.out");
    ifstream fin ("beads.in");
	fin >> N;
	for (int i = 0; i < N; i++) {
		fin >> String[i];
		String[i + N] = String[i];
		String[i + (2 * N)] = String[i];
	}
	int maxBeads;
	//Let break be before bead index
	for (int i = 0; i < N; i++) {
		char x, y;
		int j, index, count;
		count = 2;
		//Different color found marker
		bool colorFound = false;
		x = String[N + i];
		y = String[N + i - 1];
		while (colorFound == false) {
			index++;
			if (String[i + N + index] == x || String[i + N + index] == 'w') {
				count++;
			}
			else if (x == 'w') {
				x = String[i + N + index];
				count++;
			}
			else {
				colorFound = true;
			}
			if (index == N) colorFound == true;
		}
		index = 0;
		colorFound = false;
		while (colorFound == false) {
			index--;
			if (String[i + N + index - 1] == y || String[i + N + index - 1] == 'w') {
				count++;
			}
			else if (y == 'w') {
				y = String[i + N + index - 1];
				count++;
			}
			else {
				colorFound = true;
			}
		}
		index = 0;
		colorFound = false;
		string a = "";
		fout << a;
		if (maxBeads < count) {
			maxBeads = count;
			if (N == 333) fout << a;
		}
		count = 2;
	}
	if (maxBeads > N) maxBeads = N;
	fout << maxBeads << "\n";
	return 0;
}