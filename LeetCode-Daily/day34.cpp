class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int n = drones.size();
        int ans = -1;
        int best = INT_MAX;
        for (int i = 0; i < n; i++) {
            int val = abs(drones[i][0]-target[0]) + abs(drones[i][1]-target[1]);
            if (val <= drones[i][2]) {
                if (val < best) {
                    best = val;
                    ans = i;
                }
            }
        }
        return ans;
    }
};
