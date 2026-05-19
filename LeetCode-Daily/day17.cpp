class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {

        int minc = INT_MAX;
        int n = nums1.size(), m = nums2.size();

        int i = 0, j = 0;

        while(i < n && j < m) {

            if(nums1[i] == nums2[j]) {
                minc = min(minc, nums1[i]);
                i++;
                j++;
            }

            else if(nums1[i] > nums2[j]) {
                j++;
            }

            else {
                i++;
            }
        }

        return (minc == INT_MAX) ? -1 : minc;
    }
};
