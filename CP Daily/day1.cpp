#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int op = 0;
    int max = -1;

    for (int i = 0; i < n; i++) {
        if (nums[i] >= max) {
            max = nums[i];
            op++;
        }
    }

    cout << op<<endl;
}

int main() {

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
