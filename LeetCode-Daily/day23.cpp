class Solution {
public:
    vector<string> ans;

    void solve(int idx, int n, int k, int cost, string &curr) {

        if (cost > k) return;

        if (idx == n) {
            ans.push_back(curr);
            return;
        }

        curr.push_back('0');
        solve(idx + 1, n, k, cost, curr);
        curr.pop_back();

        if (idx == 0 || curr.back() != '1') {
            curr.push_back('1');
            solve(idx + 1, n, k, cost + idx, curr);
            curr.pop_back();
        }
    }

    vector<string> generateValidStrings(int n, int k) {
        string curr = "";
        solve(0, n, k, 0, curr);
        return ans;
    }
};
