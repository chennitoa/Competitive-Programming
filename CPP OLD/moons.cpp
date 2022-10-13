#include <iostream>
#define f first
#define s second

using namespace std;

int T, X, Y;
string S;
bool searched[1000];

pair<int, int> findEdge(int index) {
    int start = index;
    int end = index;
	if (searched[index] == true) {
		return make_pair(index, index);
	}
    while (start > 0 && S.at(start) == '?') {
		searched[start] = true;
        start--;
    }
    while (end < S.length() - 1 && S.at(end) == '?') {
		searched[end] = true;
        end++;
    }
    return make_pair(start, end);
}

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
		for (int j = 0; j < 1000; j++) {
			searched[j] = false;
		}
        cin >> X >> Y >> S;
        int total = 0;
        for (int j = 0; j < S.length() - 1; j++) {
            if (S.at(j) == 'C' && S.at(j + 1) == 'J') {
                total += X;
            }  
            else if (S.at(j) == 'J' && S.at(j + 1) == 'C') {
                total += Y;
            }
            else if (S.at(j) == '?') {
				pair<int, int> pairOf = findEdge(j);
				int start = pairOf.f;
				int end = pairOf.s;
				cout << "Start and end are " << start << " " << end << "\n";
                if (S.at(start) == 'C' && S.at(end) == 'J') {
                    total += X;
                }  
                else if (S.at(start) == 'J' && S.at(end) == 'C') {
                    total += Y;
                }
            }
        }
        cout << "Case #" << i + 1 << ": " << total << "\n";
    }
    return 0;
}