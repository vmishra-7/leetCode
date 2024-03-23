class Solution {
public:
    int rob(vector<int>& nums, int i) {
        if(i >= nums.size()) {
            return 0;
        }
        return max(rob(nums, i + 2) + nums[i], rob(nums, i + 1));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) {
            return 0;
        }
        if(n == 1) {
            return nums[0];
        }
        int *DP = new int[nums.size()];
        DP[0] = nums[0];
        DP[1] = max(nums[0], nums[1]);
        for(int i = 2; i < nums.size(); i++) {
            DP[i] = max(DP[i - 1], DP[i - 2] + nums[i]);
        }
        return DP[nums.size() - 1];
    }
};