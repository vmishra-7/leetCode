class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0, first = 0, two = nums.size() - 1;
        while(first <= two) {
            if(nums[first] == 0) {
                swap(nums[first++], nums[zero++]);
            } else if(nums[first] == 1) {
                first++;
            } else {
                swap(nums[first], nums[two--]);
            }
        }
    }
};