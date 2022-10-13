/*
ID: achenni1
TASK: gift1
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#define MAXNP 10
#define f first
#define s second

using namespace std;

int NP;
string names[MAXNP];
pair<string, int> bal[MAXNP];

int main() {
	ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
	fin >> NP;
	for (int i = 0; i < NP; i++) {
		fin >> names[i];
		bal[i] = make_pair(names[i], 0);
	}
	for (int i = 0; i < NP; i++) {
		string name;
		int people, money;
		fin >> name;
		fin >> money >> people;
		for (int j = 0; j < NP; j++) {
			if (names[j].compare(name) == 0) {
				bal[j].s = bal[j].s - money;
				if (people != 0) { 
					bal[j].s = bal[j].s + (money % people);
				}
				break;
			}
		}
		for (int j = 0; j < people; j++) {
			fin >> name;
			for (int j = 0; j < NP; j++) {
				if (names[j].compare(name) == 0) {
					bal[j].s = bal[j].s + money/people;
					break;
				}
			}
		}
	}
	for (int i = 0; i < NP; i++) {
		fout << names[i] << " " << bal[i].s << "\n";
	}
}