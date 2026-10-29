class Solution {
public:
    vector<vector<int>> adj;
    vector<int> parent, depth, heavy, head, pos, sz;
    vector<int> seg;
    int timer;

    int dfs(int u, int p) {
        parent[u] = p;
        sz[u] = 1;
        int maxSize = 0;

        for (int v : adj[u]) {
            if (v == p) continue;

            depth[v] = depth[u] + 1;
            int childSize = dfs(v, u);
            sz[u] += childSize;

            if (childSize > maxSize) {
                maxSize = childSize;
                heavy[u] = v;
            }
        }

        return sz[u];
    }

    void decompose(int u, int h, string &s) {
        head[u] = h;
        pos[u] = timer++;

        if (heavy[u] != -1)
            decompose(heavy[u], h, s);

        for (int v : adj[u]) {
            if (v == parent[u] || v == heavy[u]) continue;
            decompose(v, v, s);
        }
    }

    void build(int node, int l, int r, string &s) {
        if (l == r) {
            int u = -1;

            for (int i = 0; i < (int)pos.size(); i++) {
                if (pos[i] == l) {
                    u = i;
                    break;
                }
            }

            seg[node] = 1 << (s[u] - 'a');
            return;
        }

        int mid = (l + r) / 2;
        build(node * 2, l, mid, s);
        build(node * 2 + 1, mid + 1, r, s);
        seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            seg[node] = val;
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(node * 2, l, mid, idx, val);
        else
            update(node * 2 + 1, mid + 1, r, idx, val);

        seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr)
            return seg[node];

        if (r < ql || l > qr)
            return 0;

        int mid = (l + r) / 2;

        return query(node * 2, l, mid, ql, qr) ^
               query(node * 2 + 1, mid + 1, r, ql, qr);
    }

    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                   string s, vector<string>& queries) {
        adj.assign(n, {});
        parent.assign(n, -1);
        depth.assign(n, 0);
        heavy.assign(n, -1);
        head.assign(n, 0);
        pos.assign(n, 0);
        sz.assign(n, 0);

        timer = 0;

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(0, -1);
        decompose(0, 0, s);

        vector<int> arr(n);

        for (int u = 0; u < n; u++)
            arr[pos[u]] = 1 << (s[u] - 'a');

        seg.assign(4 * n, 0);

        function<void(int, int, int)> buildArray =
            [&](int node, int l, int r) {
                if (l == r) {
                    seg[node] = arr[l];
                    return;
                }

                int mid = (l + r) / 2;
                buildArray(node * 2, l, mid);
                buildArray(node * 2 + 1, mid + 1, r);

                seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
            };

        buildArray(1, 0, n - 1);

        vector<bool> ans;

        for (string &q : queries) {
            stringstream ss(q);
            string type;
            int u, v;

            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;

                s[u] = c;
                update(1, 0, n - 1, pos[u],
                       1 << (c - 'a'));
            } else {
                ss >> v;

                int mask = 0;

                while (head[u] != head[v]) {
                    if (depth[head[u]] < depth[head[v]])
                        swap(u, v);

                    mask ^= query(1, 0, n - 1,
                                  pos[head[u]], pos[u]);

                    u = parent[head[u]];
                }

                if (depth[u] > depth[v])
                    swap(u, v);

                mask ^= query(1, 0, n - 1, pos[u], pos[v]);

                if (mask == 0 || (mask & (mask - 1)) == 0)
                    ans.push_back(true);
                else
                    ans.push_back(false);
            }
        }

        return ans;
    }
};