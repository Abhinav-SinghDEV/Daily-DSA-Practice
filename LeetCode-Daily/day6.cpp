class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        
        string word(n + m - 1, '?');
        vector<int> locked(n + m - 1, 0);

        // Step 1: Place T
        for(int i = 0; i < n; i++){
            if(str1[i] == 'T'){
                for(int j = 0; j < m; j++){
                    if(word[i+j] == '?' || word[i+j] == str2[j]){
                        word[i+j] = str2[j];
                        locked[i+j] = 1;
                    } else return "";
                }
            }
        }

        // Step 2: Fill remaining with 'a'
        for(int i = 0; i < word.size(); i++){
            if(word[i] == '?') word[i] = 'a';
        }

        // Step 3: Handle F
        for(int i = 0; i < n; i++){
            if(str1[i] == 'F'){
                if(word.substr(i, m) == str2){
                    bool ok = false;
                    for(int j = m-1; j >= 0; j--){
                        if(!locked[i+j] && word[i+j] != 'z'){
                            word[i+j]++;
                            ok = true;
                            break;
                        }
                    }
                    if(!ok) return "";
                }
            }
        }

        return word;
    }
};
