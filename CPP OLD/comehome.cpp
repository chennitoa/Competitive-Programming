/*
ID: achenni1
TASK: comehome
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int P;
int minLength[26], visited[52];

int main() {
	ifstream fin("comehome.in");
	ofstream fout("comehome.out");
	fin >> P;
	