class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        int n = s.size();
        vector<int> ans;

        unordered_map<string, int> mp;

        for (string c : words) {
            mp[c]++;
        }

        int wordlen = words[0].size();
        int totalwords = words.size();
        int windowsize = wordlen * totalwords;

        for (int start = 0; start < wordlen; start++) {

            int left = start;
            int count = 0;

            unordered_map<string, int> current;

            for (int right = start; right + wordlen <= n; right += wordlen) {

                string word = s.substr(right, wordlen);

                // Word is not present in words
                if (mp.find(word) == mp.end()) {
                    current.clear();
                    count = 0;
                    left = right + wordlen;
                    continue;
                }

                current[word]++;
                count++;

                // Too many occurrences of this word
                while (current[word] > mp[word]) {

                    string leftword = s.substr(left, wordlen);

                    current[leftword]--;
                    left += wordlen;
                    count--;
                }

                // We have exactly all required words
                if (count == totalwords) {
                    ans.push_back(left);

                    // Move left by one word to search for next answer
                    string leftword = s.substr(left, wordlen);
                    current[leftword]--;
                    left += wordlen;
                    count--;
                }
            }
        }

        return ans;
    }
};