class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, candidate = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            if(count == 0) {
                candidate = nums[i];
                count++;
                continue;
            }
            if(candidate == nums[i]) {
                count++;
            } else {
                count--;
            }
        }
        return candidate;
    }
};