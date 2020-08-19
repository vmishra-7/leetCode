class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2]; //  Since majority_element covers up at least n / 2 postions, it will always fall in the middle of the array as well.
    }
};
