class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>result;
        vector<int>arr1,arr2;
        for(int i=0;i<n;i++){
            if(arr1.empty()) arr1.push_back(nums[i]);
            else if(arr2.empty()) arr2.push_back(nums[i]);
            else if(!arr1.empty() && !arr2.empty() && arr1.back()>arr2.back()){
                arr1.push_back(nums[i]);
            }
            else arr2.push_back(nums[i]);
        }
        for(int j=0;j<arr1.size();j++){
            result.push_back(arr1[j]);
        }
        for(int m=0;m<arr2.size();m++){
            result.push_back(arr2[m]);
        }
        return result;


        
    }
};
