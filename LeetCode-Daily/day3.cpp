class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m-k+1, vector<int>(n-k+1, 0));
        for(int i=0; i+k<=m; i++){
            for(int j=0; j+k<=n; j++){
                vector<int> v;
                for(int x=i; x<i+k; x++)
                    for(int y=j; y<j+k; y++)
                        v.push_back(grid[x][y]);

                sort(v.begin(), v.end());
                int mini = INT_MAX;
                for(int x=1; x<v.size(); x++){
                    if(v[x] != v[x-1]) mini = min(mini, v[x]-v[x-1]);
                }
                if(mini != INT_MAX) ans[i][j] = mini;
            }
        }
        return ans;
    }
};
