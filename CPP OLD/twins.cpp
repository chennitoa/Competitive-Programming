#include <iostream>
#include <algorithm>

using namespace std;

int n, total;
int coins[100];

int main() {
	cin >> n;
	total = 0;
	for (int i = 0; i < n; i++) {
		cin >> coins[i];
		total += coins[i];
	}
	sort(coins, coins + n);
	int counter = n;
	int sum = 0;
	while (total / 2 >= sum) {
		counter--;
		sum += coins[counter];
	}
	cout << n - counter << "\n";
	return 0;
}