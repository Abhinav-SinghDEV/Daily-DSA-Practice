class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        long long total = 0;

        // total sum
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                total += grid[i][j];
            }
        }

        if(total % 2 != 0) return false;

        // check horizontal cuts
        long long prefix = 0;
        for(int i = 0; i < m - 1; i++) {
            long long rowSum = 0;
            for(int j = 0; j < n; j++) {
                rowSum += grid[i][j];
            }
            prefix += rowSum;

            if(prefix == total - prefix) return true;
        }

        // check vertical cuts
        prefix = 0;
        for(int j = 0; j < n - 1; j++) {
            long long colSum = 0;
            for(int i = 0; i < m; i++) {
                colSum += grid[i][j];
            }
            prefix += colSum;

            if(prefix == total - prefix) return true;
        }

        return false;
    }
};
