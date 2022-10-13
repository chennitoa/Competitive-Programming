#include <iostream>
#include <cmath>

using namespace std;

int main() {
	for (int i = 1; i < 1000; i++) {
		for (int j = i + 1; j < 1000; j++) {
			for (int k = j + 1; k < 1000; k++) {
				if (pow(k, 3) - pow(i, 3) - pow(j, 3) - i * j * k + 1 == 2022) {
					cout << "Found " << i << " " << j << " " << k << "\n";
				}
			}
		}
	}
	cout << "Done\n";
}