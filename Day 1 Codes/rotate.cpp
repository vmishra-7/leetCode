class Solution {
public:
    void reverseArray(vector<int> &nums, int si, int ei) {
        int i = si, j = ei;
        while(i < j) {
            swap(nums[i++], nums[j--]);
        }
    }
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverseArray(nums, 0, nums.size() - 1);
        reverseArray(nums, 0, k - 1);
        reverseArray(nums, k, nums.size() - 1);
    }
};
