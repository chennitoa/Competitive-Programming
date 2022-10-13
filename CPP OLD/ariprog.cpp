/*
ID: achenni1
TASK: ariprog
LANG: C++                 
*/

#include <iostream> 
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;
int N, M;
bool biSquares[1250000];
int listOf[65000];

int fooBar = 0;

int main() {
	ifstream fin ("ariprog.in");
	ofstream fout ("ariprog.out");
	fin >> N >> M;
	int k = 0;
	for (int i = 0; i <= M; i++){
		for (int j = 0; j <= M; j++) {
			if (biSquares[i * i + j * j] == false) {
				biSquares[i * i + j * j] = true;
				listOf[k] = i * i + j * j;
				k++;
			}
		}
	}
	
	sort(listOf, listOf + k);
	if (M <= 150) {
		for (int i = 1; i <= M * M; i++) {
			for (int j = 0; j < k; j++) {
				int counter = 0;
				for (int a = 0; a < N; a++) {
					if (biSquares[listOf[j] + i * a] == true) {
						counter++;
					}
					else break;
				}
				if (counter == N) {
					fout << listOf[j] << " " << i << "\n";
					fooBar++;
				}
			}
		}
	}
	else {
		for (int i = 1; i <= M * M / 84; i++) {
			for (int j = 0; j < k; j++) {
				int counter = 0;
				for (int a = 0; a < N; a++) {
					if (biSquares[listOf[j] + i * a * 84] == true) {
						counter++;
					}
					else break;
				}
				if (counter == N) {
					fout << listOf[j] << " " << i * 84 << "\n";
					fooBar++;
				}
			}
		}
	}
	if (fooBar == 0) fout << "NONE" << "\n";
	return 0;
}