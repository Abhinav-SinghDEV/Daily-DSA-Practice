class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        multiset<int> low, high;
        long long sumLow = 0, sumHigh = 0;

        vector<long long> cost(n - x + 1);

        auto add = [&](int val) {
            if (low.empty() || val <= *low.rbegin()) {
                low.insert(val);
                sumLow += val;
            } else {
                high.insert(val);
                sumHigh += val;
            }

            while (low.size() > high.size() + 1) {
                int v = *low.rbegin();
                low.erase(low.find(v));
                sumLow -= v;
                high.insert(v);
                sumHigh += v;
            }

            while (low.size() < high.size()) {
                int v = *high.begin();
                high.erase(high.find(v));
                sumHigh -= v;
                low.insert(v);
                sumLow += v;
            }
        };

        auto remove = [&](int val) {
            if (low.find(val) != low.end()) {
                low.erase(low.find(val));
                sumLow -= val;
            } else {
                high.erase(high.find(val));
                sumHigh -= val;
            }

            while (low.size() > high.size() + 1) {
                int v = *low.rbegin();
                low.erase(low.find(v));
                sumLow -= v;
                high.insert(v);
                sumHigh += v;
            }

            while (low.size() < high.size()) {
                int v = *high.begin();
                high.erase(high.find(v));
                sumHigh -= v;
                low.insert(v);
                sumLow += v;
            }
        };

        for (int i = 0; i < n; i++) {
            add(nums[i]);

            if (i >= x) 
                remove(nums[i - x]);

            if (i >= x - 1) {
                long long median = *low.rbegin();

                cost[i - x + 1] =
                    median * low.size() - sumLow
                    + sumHigh - median * high.size();
            }
        }

        vector<vector<long long>> dp(
            n + 1, vector<long long>(k + 1, LLONG_MAX / 2)
        );

        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                dp[i][j] = dp[i - 1][j];

                if (i >= x) {
                    dp[i][j] = min(
                        dp[i][j],
                        dp[i - x][j - 1] + cost[i - x]
                    );
                }
            }
        }

        return dp[n][k];
    }
};