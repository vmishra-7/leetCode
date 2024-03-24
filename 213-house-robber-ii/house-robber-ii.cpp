class Solution {
public:
    int rob(vector<int> &nums, int si, int ei) {
        int n = ei - si;

        int *DP = new int[n + 1];
        DP[0] = nums[si];
        DP[1] = max(nums[si], nums[si + 1]);
        for(int i = 2; i <= n; i++) {
            DP[i] = max(DP[i - 2] + nums[si + i], DP[i - 1]);
        }
        return DP[n];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) {
            return nums[0];
        } else if(n == 2) {
            return max(nums[0], nums[1]);
        }
        return max(rob(nums, 0, n - 2), rob(nums, 1, n - 1));
    }
};