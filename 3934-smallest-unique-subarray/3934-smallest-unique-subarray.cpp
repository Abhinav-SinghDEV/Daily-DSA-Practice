class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        // Build suffix array using doubling
        vector<int> sa(n), rank(n), temp(n);

        for (int i = 0; i < n; i++) {
            sa[i] = i;
            rank[i] = nums[i];
        }

        for (int len = 1; len < n; len *= 2) {
            auto cmp = [&](int a, int b) {
                if (rank[a] != rank[b])
                    return rank[a] < rank[b];

                int ra = (a + len < n) ? rank[a + len] : -1;
                int rb = (b + len < n) ? rank[b + len] : -1;

                return ra < rb;
            };

            sort(sa.begin(), sa.end(), cmp);

            temp[sa[0]] = 0;

            for (int i = 1; i < n; i++) {
                temp[sa[i]] = temp[sa[i - 1]] +
                              (cmp(sa[i - 1], sa[i]) ? 1 : 0);
            }

            rank = temp;

            if (rank[sa[n - 1]] == n - 1)
                break;
        }

        // Build inverse suffix-array positions
        vector<int> pos(n);
        for (int i = 0; i < n; i++) {
            pos[sa[i]] = i;
        }

        // Build LCP array using Kasai's algorithm
        vector<int> lcp(n, 0);
        int common = 0;

        for (int i = 0; i < n; i++) {
            int r = pos[i];

            if (r == n - 1) {
                common = 0;
                continue;
            }

            int j = sa[r + 1];

            while (i + common < n &&
                   j + common < n &&
                   nums[i + common] == nums[j + common]) {
                common++;
            }

            lcp[r] = common;

            if (common > 0)
                common--;
        }

        // Find the shortest unique prefix among all suffixes
        int ans = n;

        for (int r = 0; r < n; r++) {
            int longestCommon = lcp[r];

            if (r > 0)
                longestCommon = max(longestCommon, lcp[r - 1]);

            int shortestUnique = longestCommon + 1;
            int suffixLength = n - sa[r];

            if (shortestUnique <= suffixLength) {
                ans = min(ans, shortestUnique);
            }
        }

        return ans;
    }
};