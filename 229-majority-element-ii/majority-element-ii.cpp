class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int thirdMaj = nums.size() / 3;
        vector<int> out;
        for(int i = 0; i < nums.size() - thirdMaj;) {
            if(out.size() != 0 && out.back() == nums[i]) {
                i++;
                continue;
            }
            if(nums[i] == nums[i + thirdMaj]) {
                out.push_back(nums[i]);
                i += thirdMaj;
            }
            i++;
        }
        reverse(out.begin(), out.end());
        return out;
    }
};