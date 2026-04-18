class Solution {
public:
    int mirrorDistance(int n) {
        int org=n;
        int rev=0;
        while(n){
            int m=n%10;
            rev=rev*10 +m;
            n=n/10;
        }
        return abs(org-rev);
    }
};
