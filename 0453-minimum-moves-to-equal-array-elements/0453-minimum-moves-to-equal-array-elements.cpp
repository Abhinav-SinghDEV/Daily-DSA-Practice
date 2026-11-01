class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
       
        int req=0;
        int minel=nums[0];
        for(int i=1;i<n;i++){
            minel= min(minel,nums[i]);
        }
      
        for(int i=0;i<n;i++){
            req+=(nums[i]-minel);
        }
        return req;
    }
};