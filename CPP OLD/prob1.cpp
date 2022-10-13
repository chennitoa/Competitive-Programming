#include <iostream>
using namespace std;

long long nums[20001];
int n;


int main() {
	cin >> n;
	int dis = 0;
	for (int i = 0; i < n; i++) {
		long long k;
		cin >> k;
		bool found = false;
		for (int j = 0; j < dis; j++) {
			if (nums[j] == k) found = true;
		}
		if (found == false) {
			nums[dis] = k;
			dis++;
		}
	}
	cout << dis << "\n";
	return 0;
}