class Solution {
public:
    bool checkString(string s) {
        int n=s.size();
        int cnt1=0, cnt2=0;
        for(char c:s){
            if(c=='a') cnt1++;
            else cnt2++;
        }
        for(int i=0;i<n;i++){
            if(s[i]=='a' && i+1>cnt1) return false;
            else if(s[i]=='b' && i+1<cnt1) return false;
            else continue;
        }
        return true;


        

        
    }
};