class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> M;
        for(int i = 0; i < nums.size(); i++) {
            M[nums[i]]++;
        }
        map<int, int> :: iterator it;
        int finalCount = 0;
        for(it = M.begin(); it != M.end(); it++) {
            int j = it -> first;
            if(M.count(j - 1) != 0) {
                continue;
            }
            int count = 1;
            while(M.count(j + 1) > 0) {
                count++;
                j++;
            }
            finalCount = max(count, finalCount);
        }
        return finalCount;
    }
};
