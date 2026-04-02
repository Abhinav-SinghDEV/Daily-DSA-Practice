class Solution {
public:

    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size();
        vector<vector<int>> dp(n, vector<int>(3, INT_MIN));
        vector<vector<int>> prev(n, vector<int>(3, INT_MIN));
        for(int k=0; k<3; k++){
            if(coins[0][0] >= 0) prev[0][k] = coins[0][0];
            else prev[0][k] = (k>0 ? 0 : coins[0][0]);
        }

        for(int j=1; j<n; j++){
            for(int k=0; k<3; k++){
                int best = max(INT_MIN, prev[j-1][k]);
                if(coins[0][j] >= 0) prev[j][k] = best+coins[0][j];
                else{
                    int noNeu = best+coins[0][j];
                    int neut = INT_MIN;
                    if(k>0){
                        int best2 = max(INT_MIN, prev[j-1][k-1]);
                        neut = best2;
                    }
                    prev[j][k] = max(noNeu, neut);
                }
            }
        }
        
        dp = prev;

        for(int i=1; i<m; i++){
            for(int j=0; j<n; j++){
                for(int k=0; k<3; k++){
                    int best = prev[j][k];
                    if(j>0) best = max(best, dp[j-1][k]);
                    if(coins[i][j] >= 0) dp[j][k] = best+coins[i][j];
                    else{
                        int noNeu = best+coins[i][j];
                        int neut = INT_MIN;
                        if(k>0){
                            int best2 = INT_MIN;
                            if(i>0) best2 = max(best2, prev[j][k-1]);
                            if(j>0) best2 = max(best2, dp[j-1][k-1]);
                            neut = best2;
                        }
                        dp[j][k] = max(noNeu, neut);
                    }
                }
            }
            prev = dp;
        }
        return max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
    }
};
