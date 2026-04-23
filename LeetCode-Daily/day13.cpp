class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n, 0);

        unordered_map<int, vector<int>> mp;

        // Step 1: store indices of each value
        for(int i = 0; i < n; i++){
            mp[nums[i]].push_back(i);
        }

        // Step 2: process each group
        for(auto &it : mp){
            vector<int> &v = it.second;
            int m = v.size();

            vector<long long> prefix(m, 0);
            prefix[0] = v[0];

            for(int i = 1; i < m; i++){
                prefix[i] = prefix[i-1] + v[i];
            }

            for(int i = 0; i < m; i++){
                long long left = 0, right = 0;

                // left side
                if(i > 0){
                    left = (long long)i * v[i] - prefix[i-1];
                }

                // right side
                if(i < m-1){
                    right = (prefix[m-1] - prefix[i]) - (long long)(m-i-1) * v[i];
                }
                ans[v[i]] = left + right;
            }
        }
        return ans;
    }
};
