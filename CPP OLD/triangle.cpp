#include <iostream>

using namespace std;

int main() {
	int total;
	for (int i = 1; i < 7; i++) {
		for (int j = 1; j < 7; j++) {
			for (int k = 1; k < 7; k++) {
				if (i + j > k && i + k > j && j + k > i) total++;
			}
		}
	}
	cout << total;
}