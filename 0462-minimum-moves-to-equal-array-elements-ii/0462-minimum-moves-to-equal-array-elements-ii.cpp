class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        int req=0;
        sort(nums.begin(), nums.end());
        int med=nums[n/2];
        for(int i=0;i<n;i++){
            req+=abs(nums[i]-med);
        }
        return req;


        
        
    }
};