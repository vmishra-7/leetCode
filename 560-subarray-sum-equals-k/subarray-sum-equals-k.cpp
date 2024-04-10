class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> M;
        int count = 0, prefixSum = 0;
        for(int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            if(prefixSum == k) {
                count++;
            }
            if(M.count(prefixSum - k) > 0) {
                count += M[prefixSum - k];
            }
            M[prefixSum]++;
        }
        return count;
    }
};