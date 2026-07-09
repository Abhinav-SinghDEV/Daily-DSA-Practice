class Solution {
public:
    int maxDigitRange(vector<int>& nums) {

        int maxRange = 0;

        // First pass: find the maximum digit range
        for (int num : nums) {
            string s = to_string(num);

            int mx = 0;
            int mn = 9;

            for (char c : s) {
                int digit = c - '0';
                mx = max(mx, digit);
                mn = min(mn, digit);
            }

            maxRange = max(maxRange, mx - mn);
        }

        // Second pass: sum numbers having maximum digit range
        int sum = 0;

        for (int num : nums) {
            string s = to_string(num);

            int mx = 0;
            int mn = 9;

            for (char c : s) {
                int digit = c - '0';
                mx = max(mx, digit);
                mn = min(mn, digit);
            }

            if (mx - mn == maxRange)
                sum += num;
        }

        return sum;
    }
};
