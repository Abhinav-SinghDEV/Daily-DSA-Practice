class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> dp(budget + 1, 0);

        for (int i = 0; i < n; i++) {
            int factor = items[i][0];
            int price = items[i][1];

            int free = 0;

            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % factor == 0) {
                    free++;
                }
            }

            vector<int> ndp = dp;

            for (int r = 0; r < price && r <= budget; r++) {
                int best = INT_MIN;

                for (int b = r; b <= budget; b += price) {
                    if (b >= price) {
                        best = max(best, dp[b - price] - (b - price) / price);
                    }

                    if (best != INT_MIN) {
                        ndp[b] = max(ndp[b], b / price + free + best);
                    }
                }
            }

            dp = ndp;
        }

        return *max_element(dp.begin(), dp.end());
    }
};