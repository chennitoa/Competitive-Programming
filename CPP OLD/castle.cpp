/*
ID: achenni1
TASK: castle
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#define f first
#define s second

using namespace std;

int M, N;
bool rooms[51][51];
int roomsID[51][51];
int roomColor[51][51];
int roomSize[2500];
vector<pair<pair<int, int>, pair<char, pair<int, int> > > > colorPairs; 
ifstream fin("castle.in");
ofstream fout("castle.out");

void fill(int x1, int y1, int color) {
	if (rooms[x1][y1] == false) {
		rooms[x1][y1] = true;
		bool north, west, south, east;
		north = west = south = east = false;
		int ID = roomsID[x1][y1];
		if (ID >= 8) {
			south = true;
			ID -= 8;
		}
		if (ID >= 4) {
			east = true;
			ID -= 4;
		}
		if (ID >= 2) {
			north = true;
			ID -= 2;
		}
		if (ID >= 1) {
			west = true;
			ID -= 1;
		}
		if (south == false) {
			fill(x1 + 1, y1, color);
		}
		
		if (east == false) {
			fill(x1, y1 + 1, color);
		}
		
		if (north == false) {
			fill(x1 - 1, y1, color);
		}
		
		if (west == false) {
			fill(x1, y1 - 1, color);
		}
		
		roomSize[color]++;
		roomColor[x1][y1] = color;
	} 
	return;
}

void checkBorder(int x1, int y1) {
	if (x1 < N - 1) {
		if (roomColor[x1][y1] != roomColor[x1 + 1][y1]) {
			colorPairs.push_back(make_pair(make_pair(roomColor[x1][y1], roomColor[x1 + 1][y1]), make_pair('S', make_pair(x1, y1)))); 
		}
	}
	if (x1 > 0) {
		if (roomColor[x1][y1] != roomColor[x1 - 1][y1]) {
			colorPairs.push_back(make_pair(make_pair(roomColor[x1][y1], roomColor[x1 - 1][y1]), make_pair('N', make_pair(x1, y1)))); 
		}
	}
	if (y1 < M - 1) {
		if (roomColor[x1][y1] != roomColor[x1][y1 + 1]) {
			colorPairs.push_back(make_pair(make_pair(roomColor[x1][y1], roomColor[x1][y1 + 1]), make_pair('E', make_pair(x1, y1)))); 
		}
	}
	if (y1 < 0) {
		if (roomColor[x1][y1] != roomColor[x1][y1 - 1]) {
			colorPairs.push_back(make_pair(make_pair(roomColor[x1][y1], roomColor[x1][y1 - 1]), make_pair('W', make_pair(x1, y1)))); 
		}
	}
}
	
int main() {
	ifstream fin("castle.in");
	ofstream fout("castle.out");
	fin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			fin >> roomsID[i][j];
		}
	}
	int counterColor = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (rooms[i][j] == false) {
				counterColor++;
			}
			fill(i, j, counterColor);
		}
	}
	fout << counterColor + 1 << "\n";
	int maxSize = 0;
	for (int i = 0; i < counterColor + 1; i++) {
		maxSize = max(maxSize, roomSize[i]);
	}
	fout << maxSize << "\n";
	int maxPairRoom = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			checkBorder(i, j);
		}
	}
	int westCoord = 51;
	int southCoord = 0;
	char direction = 'N';
	for (int i = 0; i < colorPairs.size(); i++) {
		if (maxPairRoom < roomSize[colorPairs[i].f.f] + roomSize[colorPairs[i].f.s]) {
			maxPairRoom = roomSize[colorPairs[i].f.f] + roomSize[colorPairs[i].f.s];
			westCoord = 51;
			southCoord = 0;
			direction = 'E';
		}
		if (roomSize[colorPairs[i].f.f] + roomSize[colorPairs[i].f.s] == maxPairRoom) {
			if (westCoord > colorPairs[i].s.s.s) {
				westCoord = colorPairs[i].s.s.s;
				southCoord = 0;
				direction = 'E';
			}
			if (westCoord == colorPairs[i].s.s.s) {
				if (southCoord < colorPairs[i].s.s.f) {
					southCoord = colorPairs[i].s.s.f;
					direction = 'E';
				}
				if (southCoord == colorPairs[i].s.s.f) {
					if (colorPairs[i].s.f == 'N') direction = 'N';
				}
			}
		}
	}
	fout << maxPairRoom << "\n";
	fout << southCoord + 1 << " " << westCoord + 1 << " " << direction << "\n";
	return 0;
}