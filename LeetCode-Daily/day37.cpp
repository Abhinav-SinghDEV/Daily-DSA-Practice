class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>>mp;
        for(int i = 0; i < n; i++){
            mp[nums[i]].push_back(i);
        }
        int ans=0;
        for(auto it:mp){
            if(it.second.size()>=3){
                int gap=it.second[1]-it.second[0];
                bool check=true;
                for(int i=2;i<it.second.size();i++){
                    if(it.second[i]-it.second[i-1]!=gap){
                        check=false;
                        break;
                    }
                }
                if(check) ans++;
            }
        }
        return ans;



                

        
    }
};
