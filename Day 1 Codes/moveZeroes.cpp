class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 1;
        while(j < nums.size()) {
            if(nums[i] != 0) {
                i++;
                j++;
                continue;
            }
            if(nums[j] == 0) {
                j++;
                continue;
            }
            swap(nums[i], nums[j]);
            i++;
            j++;
        }
    }
};
