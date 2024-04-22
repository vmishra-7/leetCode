class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> out;
        int i = 0;
        while(i < nums.size() - 2) {
            int j = i + 1;
            int k = nums.size() - 1;
            while(j < k) {
                int tempSum = nums[i] + nums[j] + nums[k];
                if(tempSum == 0) {
                    out.push_back({nums[i], nums[j], nums[k]});
                    j++, k--;
                    while(j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }
                    while(j < k && nums[k] == nums[k + 1]) {
                        k--;
                    }
                } else if(tempSum > 0) {
                    k--;
                } else {
                    j++;
                }
            }
            i++;
            while(i < nums.size() - 2 && nums[i] == nums[i - 1]) {
                i++;
            }
        }
        return out;
    }
};