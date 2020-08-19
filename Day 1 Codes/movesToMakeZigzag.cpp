class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        if(nums.size() == 1) {
            return 0;
        }
        int countEven = 0, countOdd = 0;
        for(int i = 1; i < nums.size(); i += 2) {
            if(i == nums.size() - 1) {
                if(nums[i - 1] <= nums[i]) {
                    countEven += (nums[i] - nums[i - 1]) + 1;
               }
            } else if(nums[i] >= nums[i - 1] || nums[i + 1] <= nums[i]) {
                countEven += (nums[i] - min(nums[i + 1], nums[i - 1]) + 1);
            }
        }
        for(int i = 0; i < nums.size(); i += 2) {
            if(i == 0) {
                if(nums[i] >= nums[i + 1]) {
                    countOdd += nums[i] - nums[i + 1] + 1;
                }
            } else if(i == nums.size() - 1) {
                    if(nums[i] >= nums[i - 1]) {
                        countOdd += nums[i] - nums[i - 1] + 1;
                    } 
            } else if(nums[i - 1] <= nums[i] || nums[i] >= nums[i + 1]) {
                   countOdd += nums[i] - min(nums[i - 1], nums[i + 1]) + 1;
           }
        }
        return min(countEven, countOdd);
    }
};
