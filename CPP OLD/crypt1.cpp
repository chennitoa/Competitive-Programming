/*
ID: achenni1
TASK: crypt1
LANG: C++                
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;
int N;
int numbers[10];

int main() {
	ofstream fout("crypt1.out");
	ifstream fin("crypt1.in");
	fin >> N;
	for (int i = 0; i < N; i++) {
		fin >> numbers[i];
	}
	int total = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				for (int l = 0; l < N; l++) {
					for (int m = 0; m < N; m++) {
						bool foundV = true;
						int number1 = 100 * numbers[i] + 10 * numbers[j] + numbers[k];
						int number2 = 10 * numbers[l] + numbers[m];
						int pproduct1 = numbers[m] * number1;
						int pproduct2 = numbers[l] * number1;
						int product = number1 * number2;
						string one = to_string(pproduct1);
						string two = to_string(pproduct2);
						string three = to_string(product);
						if (one.size() != 3 || two.size() != 3 || three.size() != 4) {
							foundV = false;
						}
						int count1 = 0;
						int count2 = 0;
						int count3 = 0;
						if (foundV == true) {
							for (int a = 0; a < 3; a++) {
								for (int b = 0; b < N; b++) {
									char z = numbers[b] + '0';
									if (one.at(a) == z) count1++;
									if (two.at(a) == z) count2++;
								}
							}
						}
						if (count1 != 3 || count2 != 3) foundV = false;
						if (foundV == true) {
							for (int a = 0; a < 4; a++) {
								for (int b = 0; b < N; b++) {
									char z = numbers[b] + '0';
									if (three.at(a) == z) count3++;
								}
							}
						}
						if (count3 != 4) foundV = false;
						if (foundV == true) {
							total++;
						}
					}
				}
			}
		}
	}
	fout << total << "\n";
	return 0;
}