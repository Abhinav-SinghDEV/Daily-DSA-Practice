class Solution {
public:
    vector<string> ans;

    void solve(string num, int target, int index, 
               long long currResult, long long prevNum, 
               string expr) {

        // Base case: All digits have been used
        if (index == num.size()) {
            if (currResult == target) {
                ans.push_back(expr);
            }
            return;
        }

        // Try forming a number using the remaining digits
        for (int i = index; i < num.size(); i++) {

            // Avoid numbers with leading zeros
            if (i > index && num[index] == '0')
                break;

            string part = num.substr(index, i - index + 1);
            long long currNum = stoll(part);

            // First number: no operator is needed
            if (index == 0) {
                solve(num, target, i + 1, currNum, currNum, part);
            }
            else {
                // Try addition
                solve(num, target, i + 1,
                      currResult + currNum, currNum,
                      expr + "+" + part);

                // Try subtraction
                solve(num, target, i + 1,
                      currResult - currNum, -currNum,
                      expr + "-" + part);

                // Try multiplication
                solve(num, target, i + 1,
                      currResult - prevNum + prevNum * currNum,
                      prevNum * currNum,
                      expr + "*" + part);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        ans.clear();
        solve(num, target, 0, 0, 0, "");
        return ans;
    }
};