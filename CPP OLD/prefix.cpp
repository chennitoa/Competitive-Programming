/*
ID: achenni1
TASK: prefix
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
string prim[202];
char S[200001];
bool T[200002];
int N, i, a;
int maxLength = 0;


int main() {
	ifstream fin("prefix.in");
	ofstream fout("prefix.out");
	i = 0;
	fin >> prim[0];
	while (prim[i] != ".") {
		i++;
		fin >> prim[i];
	}
	a = 0;
	while (fin >> S[a]) {
		a++;
	}
	T[0] = true;
	int maxLength = 0;
	for (int j = 0; j < a; j++) {
		if (T[j] == true) {
			for (int k = 0; k < i; k++) {
				bool wordFound = true;
				for (int l = 0; l < prim[k].length(); l++) {
					if (prim[k].at(l) != S[j + l]) {
						wordFound = false;
						break;
					}
				}
				if (wordFound == true) {
					int q = j + prim[k].length();
					T[q] = true;
					maxLength = max(maxLength, q);
				}
			}
		}
	}
	fout << maxLength << "\n";
	return 0;
}