class Solution {
public:
    void subsetsWithDup(vector<int>& nums, vector<vector<int>> &output, vector<int> temp, int start) {
        if(start == nums.size()) {
            return;
        }
        for(int i = start; i < nums.size(); i++) {
            if(i == start || nums[i] != nums[i - 1]) {
                temp.push_back(nums[i]);
                output.push_back(temp);
                subsetsWithDup(nums, output, temp, i + 1);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> output;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        output.push_back({});
        subsetsWithDup(nums, output, temp, 0);
        return output;
    }
};
