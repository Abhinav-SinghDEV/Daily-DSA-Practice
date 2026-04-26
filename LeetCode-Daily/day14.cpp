class Solution {
public:
    bool dfs(int r, int c, int pr, int pc, vector<vector<char>>& grid,
             vector<vector<int>>& vis) {
        int m = grid.size();
        int n = grid[0].size();

        vis[r][c] = 1;
        int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for (auto& d : dir) {
            int nr = r + d[0];
            int nc = c + d[1];

            if (nr >= 0 && nc >= 0 && nr < m && nc < n &&
                grid[nr][nc] == grid[r][c]) {
                if (nr == pr && nc == pc)
                    continue;
                if (vis[nr][nc])
                    return true;
                if (dfs(nr, nc, r, c, grid, vis))
                    return true;
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j]) {
                    if (dfs(i, j, -1, -1, grid, vis)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
