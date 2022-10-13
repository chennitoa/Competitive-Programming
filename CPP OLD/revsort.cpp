#include <iostream>

using namespace std;
int T, N;
int nums[100];

void reverse(int start, int end) {
    while (start < end) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        int total = 0;
        for (int j = 0; j < N; j++) {
            cin >> nums[j];
        }
        for (int j = 0; j < N; j++) {
            int minNum = 101;
			int index = 0;
            for (int k = j; k < N; k++) {
                if (minNum > nums[k]) {
					minNum = nums[k];
					index = k;
				}
            }
            reverse(j, index);
            total += index - j + 1;
		}
        total--;
        cout << "Case " << i + 1 << ": " << total << "\n";
    }
    return 0;
}