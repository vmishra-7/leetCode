class Solution {
public:
    // int rob(vector<int> nums, int i, int *DP) {
    //     if(i >= nums.size()) {
    //         return 0;
    //     }
    //     if(DP[i] != -1) {
    //         return DP[i];
    //     }
    //     return DP[i] = max(nums[i] + rob(nums, i + 2, DP), rob(nums, i + 1, DP));
    // }
    int rob(vector<int>& nums) {
        int N = nums.size();
        if(N == 0) {
            return 0;
        }
        if(N == 1) {
            return nums[0];
        }
        if(N == 2) {
            return max(nums[0], nums[1]);
        }
        int *DP = new int[N + 1];
        DP[0] = 0;
        DP[1] = nums[0];
        DP[2] = max(DP[1], nums[1]);
        for(int i = 3; i <= N; i++) {
            DP[i] = max(DP[i - 2] + nums[i - 1], DP[i - 1]);
        }
        return DP[N];
    }
};
