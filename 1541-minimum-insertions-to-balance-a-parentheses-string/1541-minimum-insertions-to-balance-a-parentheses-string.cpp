
class Solution {
public:
    int minInsertions(string s) {
        int cnt = 0, balance = 0;

        for (char c : s) {
            if (c == '(') {
                balance += 2;

                if (balance % 2 != 0) {
                    cnt++;
                    balance--;
                }
            }
            else {
                balance--;

                if (balance < 0) {
                    cnt++;
                    balance = 1;
                }
            }
        }

        return cnt + balance;
    }
};
