#include <iostream>

using namespace std;

int constants[100];

int main() {
	int total;
	for (int i = 0; i < 39; i++) {
		constants[i] = -1;
	}
	for (int i = 39; i < 100; i++) {
		constants[i] = 1;
	}
	for (int i = 0; i < 99; i++) {
		for (int j = i + 1; j < 100; j++) {
			total += constants[i] * constants[j];
		}
	}
	cout << total << "\n";
}