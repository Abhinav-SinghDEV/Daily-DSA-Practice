class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0)
                continue;

            bool valid = true;
            int prevMax = INT_MIN;

            for (int start = 0; start < n; start += k) {
                int mn = INT_MAX;
                int mx = INT_MIN;
                int descents = 0;

                // Check the current block
                for (int j = 0; j < k; j++) {
                    int cur = nums[start + j];
                    int next = nums[start + (j + 1) % k];

                    mn = min(mn, cur);
                    mx = max(mx, cur);

                    if (cur > next)
                        descents++;
                }

                // Condition 1: Block must be sortable by rotation
                if (descents > 1) {
                    valid = false;
                    break;
                }

                // Condition 2: Blocks must join in sorted order
                if (prevMax > mn) {
                    valid = false;
                    break;
                }

                prevMax = mx;
            }

            if (valid)
                ans += k;
        }

        return ans;
    }
};