#include <iostream>
#include <algorithm>
#define f first
#define s second

using namespace std;

int n, m, k;
int prices[10][100][3];
pair<int, int> profit[100];

bool comparator(const pair<int, int> &a, const pair<int, int> &b) {
	return (a.f < b.f);
}

int main() {
	string s;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			for (int l = 0; l < 3; l++) {
				cin >> prices[i][j][l];
			}
		}
	}
	int maxProfit = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j) {
				//cout << i << " " << j << "\n";
				for (int l = 0; l < m; l++) {
					profit[l] = make_pair(prices[j][l][1] - prices[i][l][0], l);
				}
				sort(profit, profit + m, comparator);
				int total = 0;
				int profits = 0;
				for (int l = m - 1; l > -1; l--) {
					if (profit[l].f <= 0 || total == k) {
						break;
					}
					if (total + prices[i][profit[l].s][2] > k) {
						//cout << "Buying remaining " << k - total << " of " << profit[l].f << "\n";
						profits += profit[l].f * (k - total);
						total = k;
					}
					else {
						//cout << "Buying " << prices[i][profit[l].s][2] << " of " << profit[l].f << "\n";
						profits += profit[l].f * prices[i][profit[l].s][2];
						total += prices[i][profit[l].s][2];
					}
					//cout << "Profit is now " << profits << "\n";
				}
				maxProfit = max(maxProfit, profits);
			}
		}
	}
	cout << maxProfit << "\n";
	return 0;
}