/*
ID: achenni1
TASK: lamps
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int N, C;
bool on[6];
bool off[6];
string poss0[1] = {"111111"};
string poss1[4] = {"000000", "010101", "101010", "011011"};
string poss2[6] = {"101010", "010101", "100100", "110001", "001110", "000000"};
string poss3[4] = {"001110", "100100", "110001", "111111"};
string poss4[1] = {"011011"};
string sol[10];

bool sortNums(string &a, string &b) {
	return stoi(a) < stoi(b);
}

int main() {
	ifstream fin("lamps.in");
	ofstream fout("lamps.out");
	fin >> N >> C;
	int input;
	while (input != -1) {
		fin >> input;
		if (input != -1) {
			on[(input - 1) % 6] = true;
		}
	}
	input = 0;
	while (input != -1) {
		fin >> input;
		if (input != -1) {
			off[(input - 1) % 6] = true;
		}
	}
	int z = 0;
	if (C % 2 == 1) {
		for (int i = 0; i < 4; i++) {
			bool lampsWork = true;
			for (int j = 0; j < 6; j++) {
				if (on[j] == true) {
					if (poss1[i].at(j) != '1') lampsWork = false;
				}
				if (off[j] == true) {
					if (poss1[i].at(j) != '0') lampsWork = false;
				}
			}
			if (lampsWork == true) {
				sol[z] = poss1[i];
				z++;
			}
		}
		if (C >= 3) {
			for (int i = 0; i < 4; i++) {
				bool lampsWork = true;
				for (int j = 0; j < 6; j++) {
					if (on[j] == true) {
						if (poss3[i].at(j) != '1') lampsWork = false;
					}
					if (off[j] == true) {
						if (poss3[i].at(j) != '0') lampsWork = false;
					}
				}
				if (lampsWork == true) {
					sol[z] = poss3[i];
					z++;
				}
			}
		}
	}
	else {
		for (int i = 0; i < 1; i++) {
			bool lampsWork = true;
			for (int j = 0; j < 6; j++) {
				if (on[j] == true) {
					if (poss0[i].at(j) != '1') lampsWork = false;
				}
				if (off[j] == true) {
					if (poss0[i].at(j) != '0') lampsWork = false;
				}
			}
			if (lampsWork == true) {
				sol[z] = poss0[i];
				z++;
			}
		}
		if (C >= 2) {
			for (int i = 0; i < 6; i++) {
				bool lampsWork = true;
				for (int j = 0; j < 6; j++) {
					if (on[j] == true) {
						if (poss2[i].at(j) != '1') lampsWork = false;
					}
					if (off[j] == true) {
						if (poss2[i].at(j) != '0') lampsWork = false;
					}
				}
				if (lampsWork == true) {
					sol[z] = poss2[i];
					z++;
				}
			}
		}
		if (C >= 4) {
			for (int i = 0; i < 1; i++) {
				bool lampsWork = true;
				for (int j = 0; j < 6; j++) {
					if (on[j] == true) {
						if (poss4[i].at(j) != '1') lampsWork = false;
					}
					if (off[j] == true) {
						if (poss4[i].at(j) != '0') lampsWork = false;
					}
				}
				if (lampsWork == true) {
					sol[z] = poss4[i];
					z++;
				}
			}
		
		}
	}
	if (z == 0) {
		fout << "IMPOSSIBLE\n";
		return 0;
	}
	sort(sol, sol + z, sortNums);
	for (int i = 0; i < z; i++) {
		for (int j = 0; j < N / 6; j++) {
			fout << sol[i];
		}
		for (int j = 0; j < N % 6; j++) {
			fout << sol[i].at(j);
		}
		fout << "\n";
	}
	return 0;
}
	
			