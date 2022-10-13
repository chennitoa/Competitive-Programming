/*
ID: achenni1
TASK: holstein
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#define f first
#define s second

using namespace std;

int V, G;
int Vtotal[25];
int Glist[15][25];
long long maxNum = 1;
ifstream fin("holstein.in");
ofstream fout("holstein.out");
//Vtotal is nutrients needed
//Glist is list of nutrients by brand and # of nutrient

pair<bool, int> calcNut(long long num) {
	string numString = to_string(num);
	int Vtemp[25];
	for (int i = 0; i < 25; i++) {
		Vtemp[i] = 0;
	}
	int numScoops = 0;
	for (int i = 0; i < G; i++) {
		if (numString.at(i) == '1') {
			numScoops++;
			for (int j = 0; j < V; j++) {
				Vtemp[j] += Glist[i][j];
				
			}
		}
	}
	for (int i = 0; i < V; i++) {
		if (Vtemp[i] < Vtotal[i]) return make_pair(false, numScoops);
	}
	return make_pair(true, numScoops);
}

int minScoops = 16;
int feedType = 120;
bool feedTypes[15];

void genCombos(long long num) {
	if (num < maxNum) {
		genCombos(num * 10 + 1);
		genCombos(num * 10 + 2);
	}
	else {
		bool nutMet = calcNut(num).f;
		int scoopsUsed = calcNut(num).s;
		if (nutMet == true) {
			if (minScoops > scoopsUsed) {
				minScoops = scoopsUsed;
				feedType = 120;
			}
			int feedtypeTemp = 0;
			if (scoopsUsed == minScoops) {
				string numString = to_string(num);
				//Calculate feedtype numbers
				for (int i = 0; i < G; i++) {
					if (numString.at(i) == '1') {
						feedtypeTemp += i + 1;
					}
				}
				if (feedtypeTemp < feedType) {
					feedType = feedtypeTemp;
					feedtypeTemp = 0;
					for (int i = 0; i < G; i++) {
						if (numString.at(i) == '1') {
							feedTypes[i] = true;
						}
						else {
							feedTypes[i] = false;
						}
					}
				}
			}
		}
	}
	return;
}

int main() {

	fin >> V;
	for (int i = 0; i < V; i++) fin >> Vtotal[i];
	fin >> G;
	for (int i = 0; i < G; i++) {
		for (int j = 0; j < V; j++) {
			fin >> Glist[i][j];
		}
	}
	for (int i = 1; i < G; i++) {
		maxNum *= 10;
	}
	genCombos(0);
	fout << minScoops << " ";
	int scoopCounter = 0;
	for (int i = 0; i < G; i++) {
		if (feedTypes[i] == true) {
			fout << i + 1;
			scoopCounter++;
			if (scoopCounter != minScoops) fout << " ";
			else fout << "\n";
		}
	}
	return 0;
}