class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();

        vector<vector<int>> children(n);

        for (int i = 1; i < n; i++) {
            children[parent[i]].push_back(i);
        }

        vector<int> depth(n);

        depth[0] = 1;

        vector<int> st;
        st.push_back(0);

        int height = 1;

        while (!st.empty()) {
            int node = st.back();
            st.pop_back();

            for (int child : children[node]) {
                depth[child] = depth[node] + 1;
                height = max(height, depth[child]);
                st.push_back(child);
            }
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            ans += (long long)nums[i] * (height - depth[i] + 1);
        }

        return ans;
    }
};
