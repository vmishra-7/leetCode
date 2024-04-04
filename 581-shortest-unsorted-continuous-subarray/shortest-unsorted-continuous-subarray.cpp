class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int leftId = 0, rightId = nums.size() - 1;
        while(leftId < rightId) {
            if(nums[leftId] <= nums[leftId + 1]) {
                leftId++;
                continue;
            }
            break;
        }
        if(leftId == rightId) {
            return 0;
        }
        while(rightId > 0) {
            if(nums[rightId] >= nums[rightId - 1]) {
                rightId--;
                continue;
            }
            break;
        }
        if(leftId >= rightId) {
            return 0;
        }
        int tempMin = INT_MAX, tempMax = INT_MIN;
        for(int i = leftId; i <= rightId; i++) {
            tempMin = min(tempMin, nums[i]);
            tempMax = max(tempMax, nums[i]);
        }
        while(leftId > 0 && nums[leftId - 1] > tempMin) leftId--;
        while(rightId < nums.size() - 1 && nums[rightId + 1] < tempMax) rightId++;
        return rightId - leftId + 1;
    }
};