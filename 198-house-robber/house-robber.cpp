class Solution {
public:
    int rob(vector<int> nums, int i, int *DP) {
        if(i >= nums.size()) {
            return 0;
        }
        if(DP[i] != -1) {
            return DP[i];
        }
        return DP[i] = max(nums[i] + rob(nums, i + 2, DP), rob(nums, i + 1, DP));
    }
    int rob(vector<int>& nums) {
        int *DP = new int[nums.size()];
        for(int i = 0; i < nums.size(); i++) {
            DP[i] = -1;
        }
        int out = rob(nums, 0, DP);
        for(int i = 0; i < nums.size(); i++) {
            cout << DP[i] << " ";
        }
        return out;
    }
};