class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0, candidate1 = INT_MIN, count2 = 0, candidate2 = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            if(count1 == 0 && nums[i] != candidate2) {
                candidate1 = nums[i];
                count1++;
            } else if(count2 == 0 && nums[i] != candidate1) {
                candidate2 = nums[i];
                count2++;
            } else if(nums[i] == candidate1) {
                count1++;
            } else if(nums[i] == candidate2) {
                count2++;
            } else {
                count1--, count2--;
            }
        }
        count1 = 0, count2 = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == candidate1) {
                count1++;
            } else if(nums[i] == candidate2) {
                count2++;
            }
        }
        vector<int> out;
        if(count1 > nums.size() / 3) {
            out.push_back(candidate1);
        }
        if(count2 > nums.size() / 3) {
            out.push_back(candidate2);
        }
        return out;
    }
};