class Solution {
public:
    int findTargetSumWays(vector<int> &nums, int i, int target, int **DP) {
        if(i == nums.size()) {
            if(target == 1000) {
                return 1;
            }
            return 0;
        }
        if(DP[i][target] != -1) {
            return DP[i][target];
        }
        DP[i][target] = findTargetSumWays(nums, i + 1, target + nums[i], DP) + findTargetSumWays(nums, i + 1, target - nums[i], DP);
        return DP[i][target];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int **DP = new int*[nums.size() + 1];
        for(int i = 0; i <= nums.size(); i++) {
            DP[i] = new int[3001];   //traget + 20 * 1000 (worst case)
            for(int j = 0; j <= 3000; j++) {
                DP[i][j] = -1;
            }
        }
        return findTargetSumWays(nums, 0, target + 1000, DP);
    }
};