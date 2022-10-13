#include <iostream>


pair<int, int> cows[100000];
int M, N;
using namespace std;

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		cows[i] = make_pair(a, b);
	}
	