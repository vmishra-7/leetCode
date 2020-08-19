class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> M;
        for(int i = 0; i < nums.size(); i++) {
            if(M.count(target - nums[i]) > 0) {
                vector<int> output;
                output.push_back(M[target - nums[i]]);
                output.push_back(i);
                return output;
            }
            M[nums[i]] = i;
        }
        return {};
    }
};
