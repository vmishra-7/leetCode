class Solution {
public:
    int search(vector<int>& arr, int si, int ei, int target) {
        int l = si, r = ei;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(arr[mid] == target) {
                return mid;
            }
            if(arr[l] <= arr[mid]) {
                if(target >= arr[l] && arr[mid] > target) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else if(arr[mid] <= arr[r]){
                if(target > arr[mid] && target <= arr[r]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        return search(nums, 0, nums.size() - 1, target);
    }
};