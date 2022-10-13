/*
ID: achenni1
TASK: milk3
LANG: C++                 
*/

#include <iostream> 
#include <fstream>
#include <string>
#define f first
#define s second

using namespace std;
pair<int, int> amts;
int maxCap[3];
bool state[21];
bool seen[21][21];
ofstream fout ("milk3.out");
ifstream fin ("milk3.in");

pair<int, int> pour(pair<int, int> amt, int from, int to) {
	int amtsTemp[3];
	amtsTemp[0] = amt.f;
	amtsTemp[1] = amt.s;
	amtsTemp[2] = maxCap[2] - amt.f - amt.s;
	if (amtsTemp[from] > maxCap[to] - amtsTemp[to]) {
		amtsTemp[from] -= (maxCap[to] - amtsTemp[to]);
		amtsTemp[to] = maxCap[to];
	}
	else {
		amtsTemp[to] += amtsTemp[from];
		amtsTemp[from] = 0;
	}
	pair<int, int> returned = make_pair(amtsTemp[0], amtsTemp[1]);
	return returned;
}
void search(pair<int, int> amt) {
	int amts2 = maxCap[2] -  amt.f - amt.s;
	if (seen[amt.f][amt.s]) return;
	
	seen[amt.f][amt.s] = true;
	
	if (amt.f == 0) state[amts2] = true; 
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i != j) {
				search(pour(make_pair(amt.f, amt.s), i, j));
			}
		}
	}
}

int main() {
	for (int i = 0; i < 3; i++) fin >> maxCap[i];
	amts.f = amts.s = 0;
	search(amts);
	for (int i = 0; i < 21; i++) {
		if (state[i] == true) {
			if (i == maxCap[2]) fout << i;
			else fout << i << " ";
		}
	}
	fout << "\n";
	return 0;
}