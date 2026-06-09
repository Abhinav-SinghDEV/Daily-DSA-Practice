class Solution {
public:
    string reverseWords(string s) {

        int n = s.size();
        string ans = "";

        int i = n - 1;

        while(i >= 0){

            // skip spaces
            while(i >= 0 && s[i] == ' ')
                i--;

            if(i < 0)
                break;

            string word = "";

            // collect current word
            while(i >= 0 && s[i] != ' '){
                word = s[i] + word;
                i--;
            }
            // add spaces if the current ans is not empty..
            if(!ans.empty())
                ans += " ";

            ans += word;
        }

        return ans;
    }
};
