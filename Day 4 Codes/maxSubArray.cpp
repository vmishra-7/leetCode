class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN, sumSoFar = 0;
        for(int i = 0; i < nums.size(); i++) {
            sumSoFar += nums[i];
            maxSum = max(maxSum, sumSoFar);
            if(sumSoFar < 0) {
                sumSoFar = 0;
            }
        }
        return maxSum;
    }
};
