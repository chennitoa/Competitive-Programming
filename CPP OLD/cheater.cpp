#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
bool ans[100][10000];
int questions[10000];
int students[100];

int T, P;

int main() {
	ifstream fin("cheater.in");
    fin >> T >> P;
    for (int i = 0; i < T; i++) {
        int cheater = 101;
        unsigned long long score = 0;
		for (int j = 0; j < 10000; j++) {
			questions[j] = 0;
		}
        for (int j = 0; j < 100; j++) {
			students[j] = 0;
            for (int k = 0; k < 10000; k++) {
				char temp;
                fin >> temp;
				if (temp == '1') {
					ans[j][k] = true;
					students[j]++;
					questions[k]++;
				}
				else {
					ans[j][k] = false;
				}
            }
        }
        for (int j = 0; j < 100; j++) {
			cout << j + 1 << " " << students[j] << "\n";
            unsigned long long stuScore = 0;
            for (int k = 0; k < 10000; k++) {
                long long sus;
				if (ans[j][k] == false) {
					sus = students[j] * questions[k];
				}
				else {
					sus = students[j] * (1 - questions[k]);
				}
                stuScore += sus * sus;
            }
            if (stuScore > score) {
                score = stuScore;
                cheater = j + 1;
            }
        }
        cout << "Case #" << i + 1 << ": " << cheater << "\n";
    }
    return 0;
}