#include <iostream>

using namespace std;


int main() {
	int *p = 0;
	for (int i = 0; i < 1000; i++) {
		cout << p << " " << *p << "\n";
		p++;
	}
}