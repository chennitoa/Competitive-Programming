#include <iostream>

using namespace std;

int total;
char sequenca[10];

void generate (char sequences[], int num)
	char sequence[10] = sequences[];
	if (num < 10) {
		sequence[num] = 'A';
		generate(sequences, num + 1);
		sequence[num] = 'B';
		generate(sequences, num + 1);
	}
	else {
		check(sequence);
	}
}

void check(char sequences[]) {
	bool broken = false;
	if (sequences[0] == 'A' && sequences[9] == 'B') {
		for (int i = 0; i < 7; i++) {
			if ((sequences[i] == 'A' || sequences[i + 1] == 'B') || sequences[i + 2] == 'A') {
				broken = true;
			}
		}
		if (broken == false) total++;
	}
}


int main() {
	for (int i = 0; i < 10; i++) {
		sequenca[i] = 'A';
	}
	generate(sequenca[], 0);
	cout << total << "\n";
}