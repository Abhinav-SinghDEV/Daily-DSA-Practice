class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> dist(n, vector<int>(m, -1));

        queue<pair<int,int>> q;

        // Push all 0's into queue
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while(!q.empty()) {

            auto [row, col] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++) {

                int nr = row + dr[k];
                int nc = col + dc[k];

                if(nr >= 0 && nr < n &&
                   nc >= 0 && nc < m &&
                   dist[nr][nc] == -1) {

                    dist[nr][nc] = dist[row][col] + 1;
                    q.push({nr, nc});
                }
            }
        }

        return dist;
    }
};
