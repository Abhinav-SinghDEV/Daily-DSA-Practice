class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        int high=nums[n-1];
        int mov=0;
        for(int num:nums){
            mov+=abs(num-high);
        }
        return mov;

        
    }
};