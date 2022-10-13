/*
ID: achenni1
TASK: milk2
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#define MAXN 5000
#define MAXT 1000000
#define f first
#define s second

using namespace std;

int N;
int startTime[MAXN], endTime[MAXN];
int sTime, bTime;
bool times[MAXT];

int main() {
	ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");
	fin >> N;
	for (int i = 0; i < N; i++) {
		fin >> startTime[i] >> endTime[i];
	}
	sTime = MAXT;
	for (int i = 0; i < N; i++) {
		if (startTime[i] < sTime) sTime = startTime[i];
	}
	bTime = 0;
	for (int i = 0; i < N; i++) {
		if (endTime[i] > bTime) bTime = endTime[i];
	}
	if (N == 476564) fout << sTime << "\n";
	for (int i = 0; i < N; i++) {
		for (int j = startTime[i]; j < endTime[i]; j++) {
		times[j] = true;
		}
	}
	
	int counterT, counterF;
	counterT = 0;
	counterF = 0;
	int maxT, maxF;
	maxT = 0;
	maxF = 0;
	for (int i = sTime; i < bTime; i++) {
		if (N == 414123) fout << i << " " << times[i] << "\n";
		if (times[i] == true) {
			counterT++;
			if (counterF > maxF) {
				maxF = counterF;
			}
			counterF = 0;
		}
		else {
			counterF++;
			if (counterT > maxT) {
				maxT = counterT;
			}
			counterT = 0;
		}
	}
	if (counterF > maxF) maxF = counterF;
	if (counterT > maxT) maxT = counterT;
	fout << maxT << " " << maxF << "\n";
}
