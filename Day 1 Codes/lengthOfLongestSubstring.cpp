class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() < 2) {
            return s.size();
        }
        map<char, int> M;
        int i = 0, j = 1;
        int ans = INT_MIN;
        M[s[0]] = 0;
        while(j < s.size()) {
            if(M.count(s[j]) == 0) {
                M[s[j]] = j;
                j++;
                continue;
            }
            if(M[s[j]] >= i) {
                ans = max(ans, j - i);
                i = M[s[j]] + 1;
            }
            M[s[j]] = j;
            j++;
        }
        ans = max(ans, j - i);
        return ans;
    }
};
