class Solution {
public:
    vector<string> ans;

    void dfs(string &s, int index,
             int left, int right,
             int lrem, int rrem,
             string path) {

        // Reached the end
        if(index == s.size()) {

            if(lrem == 0 && rrem == 0) {
                ans.push_back(path);
            }

            return;
        }

        char c = s[index];

        // -------------------------
        // Case 1: character is '('
        // -------------------------
        if(c == '(') {

            // Remove this '('
            if(lrem > 0) {
                dfs(s, index + 1,
                    left, right,
                    lrem - 1, rrem,
                    path);
            }

            // Keep this '('
            dfs(s, index + 1,
                left + 1, right,
                lrem, rrem,
                path + c);
        }

        // -------------------------
        // Case 2: character is ')'
        // -------------------------
        else if(c == ')') {

            // Remove this ')'
            if(rrem > 0) {
                dfs(s, index + 1,
                    left, right,
                    lrem, rrem - 1,
                    path);
            }

            // Keep ')' only if possible
            if(right < left) {
                dfs(s, index + 1,
                    left, right + 1,
                    lrem, rrem,
                    path + c);
            }
        }

        // -------------------------
        // Case 3: normal character
        // -------------------------
        else {
            dfs(s, index + 1,
                left, right,
                lrem, rrem,
                path + c);
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        int lrem = 0;
        int rrem = 0;

        // Find minimum removals
        for(char c : s) {

            if(c == '(') {
                lrem++;
            }

            else if(c == ')') {

                if(lrem > 0)
                    lrem--;
                else
                    rrem++;
            }
        }

        dfs(s, 0, 0, 0, lrem, rrem, "");

        // Remove duplicate answers
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());

        return ans;
    }
};