class Solution {
public:
    int search(vector<int>& nums, int si, int ei, int target) {
        if(si > ei) {
             return -1;
        }
        int mid = (si + ei) / 2;
        if(target == nums[mid]) {
            return mid;
        }
        if(nums[si] <= nums[mid]) {
            if(target >= nums[si] && target < nums[mid]) {
                return search(nums, si, mid - 1, target);
            } else {
                return search(nums, mid + 1, ei, target);
            }
        } else if(nums[mid] <= nums[ei]) {
            if(target > nums[mid] && target <= nums[ei]) {
                return search(nums, mid + 1, ei, target);
            } else {
                return search(nums, si, mid - 1, target);
            }
        } return -1;
    }
    int search(vector<int>& nums, int target) {
        return search(nums, 0, nums.size() - 1, target);
    }
};