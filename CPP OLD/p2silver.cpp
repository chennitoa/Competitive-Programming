#include <bits/stdc++.h>
using namespace std;
#define MAXN 65536

//Take ceiling of years divided by 12
int N, K;
int years[MAXN];
int diff[MAXN];

int main() {
	cin >> N;
	cin >> K;
	for (int i = 0; i < N; i ++) {
		int x;
		cin >> x;
		years[i] = ceil((double) x / 12);
	}
	sort(years,years + N);
	int total;
	total = years[N - 1];
	//Let diff[i] be the number of 12-year segments bewtween two years
	for (int i = 0; i < N; i++) {
		if (i == 0) {
			diff[i] = years[i];
		}
		else {
			diff[i] = years[i] - years[i-1];
		}
	}
	sort(diff, diff + N);

	
	for(int i = 0; i < K-1; i++) {
		total -= diff[N - 1 - i] - 1;
	}

	cout << total * 12;
}