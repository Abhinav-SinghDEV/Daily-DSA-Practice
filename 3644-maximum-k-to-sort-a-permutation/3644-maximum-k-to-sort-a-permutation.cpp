class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n=nums.size();
        int binary=-1;
        for(int i=0;i<n;i++){
           if(nums[i]!=i){
             if(binary==-1){
                binary=nums[i];
             }else{
                binary&= nums[i];
             }
           }
        }

          return (binary==-1)?0:binary;
    }
};