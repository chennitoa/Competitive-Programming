#include <iostream>

using namespace std;
int T, N, M;
pair<int, int> paths[500000];
int fill[500000];

int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		int solution = 0;
		cin >> N >> M;
		for (int j = 0; j < M; j++) {
			int a, b;
			cin >> a >> b;
			paths[j] = make_pair(a, b);
		}
		cout << solution << "\n";
	}
}