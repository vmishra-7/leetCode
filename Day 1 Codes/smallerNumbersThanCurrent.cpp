class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        map<int, int> M;
        vector<int> V;
        for(int i = 0; i < nums.size(); i++) {
            V.push_back(nums[i]);
        }
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            if(M.count(nums[i]) > 0) {
                continue;
            }
            M[nums[i]] = i;
        }
        vector<int> output;
        for(int i = 0; i < V.size(); i++) {
            output.push_back(M[V[i]]);
        }
        return output;
    }
};
