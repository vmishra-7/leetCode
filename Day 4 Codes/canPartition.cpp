class Solution {
public:
   bool canPartition(vector<int>& nums, int i, int sum, int tempSum, int *DP) {
        if(i >= nums.size()) {
            if(sum == tempSum) {
                return true;
            } return false;
        }
       if(DP[tempSum] != -1) {
           return DP[tempSum];
       }
        if(sum == tempSum) {
            return true;
        }
        if(sum < tempSum) {
            return false;
        }
        DP[tempSum] = canPartition(nums, i + 1, sum, tempSum + nums[i], DP) || canPartition(nums, i + 1, sum, tempSum, DP);
       return DP[tempSum];
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if(sum % 2 != 0) {
            return false;
        }
        sum /= 2; // Not for memoization solution.
        bool *DP = new bool[sum + 1];
        for(int i = 0; i <= sum; i++) {
            DP[i] = false;
        }
        DP[0] = true;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = sum; j >= nums[i]; j--) {
                DP[j] = DP[j - nums[i]] || DP[j];
            }
        }
        //return canPartition(nums, 0, sum / 2, 0, DP);
        return DP[sum];
    }
};
