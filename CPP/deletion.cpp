#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> v;
	v.push_back(3);
	cout << v[0];
	int t;
	cin >> t;
	vector<int> *p = &v;
	if (t == 1) {
		delete p;
		cerr << "You are stupid\n";
	}
	cout << v[0];
}