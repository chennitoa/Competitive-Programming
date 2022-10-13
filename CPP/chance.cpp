#include <iostream>

using namespace std;

int main() {
double chance = 1.0;
for (int i = 0; i < 38; i++ ){
chance *= (366 - i);
chance /= 366;

}
cout << chance << "\n";
}