class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int i, int sum, int S, int **DP) {
        if(i == nums.size()) {
            if(sum == S) {
                return 1;
            } else {
                return 0;
            }
        }
        if(DP[i][sum] != -1) {
            return DP[i][sum];
        }
        DP[i][sum] = findTargetSumWays(nums, i + 1, sum + nums[i], S, DP) + findTargetSumWays(nums, i + 1, sum - nums[i], S, DP);
        return DP[i][sum];
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        int **DP = new int*[nums.size() + 1];
        for(int i = 0; i <= nums.size(); i++) {
            DP[i] = new int[2001];
            for(int j = 0; j <= 2000; j++) {
                DP[i][j] = -1;
            }
        }
        return findTargetSumWays(nums, 0, 1000, S + 1000, DP);
    }
};