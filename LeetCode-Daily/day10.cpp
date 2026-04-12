
class Solution {
    int f(int i, int j){
        return abs(i/6 - j/6) + abs(i%6 - j%6);
    }
public:
    int minimumDistance(string word) {
        int n = word.size();
        vector<int> curr(26), prev(26);
        // for(int i=0; i<n; i++){
        //     int ch = word[i]-'A';
        //     for(int j=0; j<26; j++){
        //         for(int k=0; k<26; k++) dp[i+1][j][k] = 1e6;
        //     }
        //     for(int j=0; j<26; j++){
        //         for(int k=0; k<26; k++){
        //             dp[i+1][j][ch] = min(dp[i+1][j][ch], dp[i][j][k] + f(k, ch));
        //             dp[i+1][ch][k] = min(dp[i+1][ch][k], dp[i][j][k] + f(j, ch));
        //         }
        //     }
        // }
        for(int i=1; i<n; i++){
            int pr = word[i-1]-'A', cu = word[i]-'A';
            for(int j=0; j<26; j++) curr[j] = prev[j] + f(pr, cu);
            for(int j=0; j<26; j++) curr[pr] = min(curr[pr], prev[j] + f(j, cu));
            prev = curr;
        }
        return *min_element(prev.begin(), prev.end());
    }
};
