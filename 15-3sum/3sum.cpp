class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> out;
        int i = 0;
        while(i < nums.size() - 2) {
            int j = i + 1;
            int k = nums.size() - 1;
            while(j < k) {
                int tempSum = nums[i] + nums[j] + nums[k];
                if(tempSum == 0) {
                    out.insert({nums[i], nums[j], nums[k]});
                    j++, k--;
                } else if(tempSum > 0) {
                    k--;
                } else {
                    j++;
                }
            }
            i++;
        }
        set<vector<int>>:: iterator it;
        vector<vector<int>> res;
        for(it = out.begin(); it != out.end(); it++) {
            res.push_back(*it);
        }
        return res;
    }
};