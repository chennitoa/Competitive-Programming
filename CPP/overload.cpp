#include <iostream>

using namespace std;

int doFoo(int n) {
	return n + 3;
}

void doFoo(string s) {
	cout << s << "\n";
}


int main() {
	cout << doFoo(3) << "\n";
	doFoo("abracadabra");
}
	