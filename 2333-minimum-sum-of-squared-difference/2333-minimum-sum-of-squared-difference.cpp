class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int> freq(100001, 0);

        int n = nums1.size();
        long long k = (long long)k1 + k2;

        for (int i = 0; i < n; i++) {
            int d = abs(nums1[i] - nums2[i]);
            freq[d]++;
        }

        for (int i = 100000; i > 0 && k > 0; i--) {
            long long take = min(k, (long long)freq[i]);

            freq[i] -= take;
            freq[i - 1] += take;

            k -= take;
        }

        long long ans = 0;

        for (int i = 1; i <= 100000; i++) {
            ans += 1LL * i * i * freq[i];
        }

        return ans;
    }
};