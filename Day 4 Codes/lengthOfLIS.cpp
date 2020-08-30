class Solution {
public:
    // int LIS(vector<int> &nums, int element, int i) {
    //     if(i == nums.size()) {
    //         return 0;
    //     }
    //     int outputA = INT_MIN;
    //     if(element < nums[i]) {
    //         outputA = 1 + LIS(nums, nums[i], i + 1);
    //     }
    //     int output = LIS(nums, element, i + 1);
    //     return max(outputA, output);
    // }
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        //return LIS(nums, INT_MIN, 0);
        int *output = new int[nums.size()];
        for(int i = 0; i < nums.size(); i++) {
            output[i] = 1;
        }
        for(int i = 1; i < nums.size(); i++) {
            for(int j = i - 1; j >= 0; j--) {
                if(nums[j] < nums[i] && output[i] < output[j] + 1) {
                    output[i] = output[j] + 1;
                }
            }
        }
        int maxLen = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            maxLen = max(maxLen, output[i]);
        }
        return maxLen;
    }
};
