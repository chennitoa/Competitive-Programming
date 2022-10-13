#include <iostream>
#include <iomanip>

using namespace std;
int n;
int x[200000], y[200000];

pair<long double, long double> computeArea(int a) {
    long double area1 = 0.0;
	cout << setprecision(15);
    int j = a - 1;
    for (int i = 0; i < a; i++) {
        area1 += (x[j] + x[i]) * (y[j] - y[i]);
        j = i;
    }
    j = n - 1;
    long double area2 = 0.0;
    for (int i = a; i < n; i++) {
        area2 += (x[j] + x[i]) * (y[j] - y[i]);
        j = i;
    }
    return make_pair(abs(area1 / 2.0), abs(area2 / 2.0));
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    //binary search
    int beg = 1;
    int end = n - 1;
    while (beg < end - 1) {
        int mid = (beg + end) / 2;
		cout << "Testing mid " << mid << " at x " << x[mid] << " and y " << y[mid] << "\n";
        pair<long double, long double> area = computeArea(mid);
		cout << "area1 = " << area.first << " and area2 = " << area.second << "\n";
        if (area.first > area.second) {
            end = mid;
        }
        else if (area.first < area.second) {
            beg = mid;
        }
		else {
			cout << "Mid " << mid << " is solution\n";
			break;
		}
    }
	cout << "beg is " << beg << " and end is " << end << "\n";
	long double area1 = computeArea(beg).second;
	long double area2 = computeArea(end).first;
	long double ratio = area1 / (area1 + area2);
	cout << "area1 = " << area1 << " and area2 = " << area2 << "\n";
	if (area1 == area2) ratio = 0.5;
	cout << (long double) (x[end] - x[beg]) * ratio + (long double) x[beg] << " " << (y[end] - y[beg]) * ratio + y[beg] << "\n"; 
}

