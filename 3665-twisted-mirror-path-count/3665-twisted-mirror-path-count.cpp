class Solution {
public:
    const int mod = 1e9 + 7;

    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<long long>> dpR(m, vector<long long>(n, 0));
        vector<vector<long long>> dpD(m, vector<long long>(n, 0));

        dpR[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i == 0 && j == 0) {
                    dpR[i][j] = 1;
                }

                if (grid[i][j] == 0) {
                    long long ways = (dpR[i][j] + dpD[i][j]) % mod;

                    if (j + 1 < n) {
                        dpR[i][j + 1] = (dpR[i][j + 1] + ways) % mod;
                    }

                    if (i + 1 < m) {
                        dpD[i + 1][j] = (dpD[i + 1][j] + ways) % mod;
                    }
                }
                else {
                    if (i + 1 < m) {
                        dpD[i + 1][j] = (dpD[i + 1][j] + dpR[i][j]) % mod;
                    }

                    if (j + 1 < n) {
                        dpR[i][j + 1] = (dpR[i][j + 1] + dpD[i][j]) % mod;
                    }
                }
            }
        }

        return (dpR[m - 1][n - 1] + dpD[m - 1][n - 1]) % mod;
    }
};