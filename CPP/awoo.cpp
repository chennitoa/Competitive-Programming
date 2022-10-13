#include <iostream>
#include <string>
#include <utility>

using namespace std;

int q, n;

string s, t;

int main() {
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> n >> s >> t;
		int csa = 0;
		int csb = 0;
		int csc = 0;
		int cta = 0;
		int ctb = 0;
		int ctc = 0;
		for (int j = 0; j < n; j++) {
			if (s.at(j) == 'a') csa++;
			else if (s.at(j) == 'b') csb++;
			else csc++;
			if (t.at(j) == 'a') cta++;
			else if (t.at(j) == 'b') ctb++;
			else ctc++;
		}
		if (csa == cta && csb == ctb && csc == ctc) {
			pair<int, int> csall[100000], ctall[100000];
			int cnts = 0; 
			int cntt = 0;
			for (int i = 0; i < n; i++) {
				if (s.at(i) == 'a' || s.at(i) == 'c') {
					csall[cnts] = make_pair(s.at(i), i);
					cnts++;
				}
				if (t.at(i) == 'a' || t.at(i) == 'c') {
					ctall[cntt] = make_pair(t.at(i), i);
					cntt++;
				}
			}
			bool stmatch = true;
			for (int j = 0; j < cnts; j++) {
				if (csall[j].first != ctall[j].first) stmatch = false;
				if (csall[j].first == 'a') {
					if (csall[j].second > ctall[j].second) stmatch = false;
				}
				else {
					if (csall[j].second < ctall[j].second) stmatch = false;
				}
			}
			if (stmatch) cout << "YES\n";
			else cout << "NO\n";
		}
		else cout << "NO\n";
	}
}