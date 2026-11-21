class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> adj(n);

        // Build the original tree
        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<int> newParent(n, -1);
        vector<int> last(26, -1);

        // Step 1: Find the new parent of every node
        // Iterative DFS: {node, entering/exit, previous last node}
        stack<tuple<int, int, int>> st;
        st.push({0, 1, -1});

        while (!st.empty()) {
            auto [u, state, prev] = st.top();
            st.pop();

            int c = s[u] - 'a';

            if (state == 1) {
                int old = last[c];

                if (u == 0) {
                    newParent[u] = -1;
                }
                else if (old != -1) {
                    newParent[u] = old;
                }
                else {
                    newParent[u] = parent[u];
                }

                last[c] = u;

                st.push({u, 0, old});

                for (int i = adj[u].size() - 1; i >= 0; i--) {
                    st.push({adj[u][i], 1, -1});
                }
            }
            else {
                last[c] = prev;
            }
        }

        // Step 2: Build the modified tree
        vector<vector<int>> tree(n);

        for (int i = 1; i < n; i++) {
            tree[newParent[i]].push_back(i);
        }

        // Step 3: Calculate subtree sizes
        vector<int> order;
        stack<int> st2;

        st2.push(0);

        while (!st2.empty()) {
            int u = st2.top();
            st2.pop();

            order.push_back(u);

            for (int v : tree[u]) {
                st2.push(v);
            }
        }

        vector<int> ans(n, 1);

        // Process children before parents
        for (int i = n - 1; i > 0; i--) {
            int u = order[i];
            ans[newParent[u]] += ans[u];
        }

        return ans;
    }
};