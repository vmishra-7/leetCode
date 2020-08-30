class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        int output = nums[0];
        int maxTemp = nums[0], minTemp = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            int temp = maxTemp;
            maxTemp = max(nums[i], max(minTemp * nums[i], maxTemp * nums[i]));
            minTemp = min(nums[i], min(temp * nums[i], nums[i] * minTemp));
            output = max(output, maxTemp);
        }
        return output;
    }
};
