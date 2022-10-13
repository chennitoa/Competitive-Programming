#include <iostream>
#include <vector>

using namespace std;

int main() {
		vector<vector<int>> groups = {{1,-1,-1},{3,-2,0}};
		vector<int> nums = {1,-1,0,1,-1,-1,3,-2,0};
        int k = 0;
        for (auto & group: groups) {
            for (auto & j : group) {
				if (k >= nums.size()) {
					cout << "false\n";
					return 1;
				}
				cout << j << "\n";
                while (nums[k] != j) {
					cout << k << " " << nums[k] << "\n";
                    if (k >= nums.size()) {
						cout << "false\n";
						return 1;
					}
                    k++;
                }
                k++;
            }
        }
        cout << "true\n";
		return 1;
    }