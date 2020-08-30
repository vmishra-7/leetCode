class Solution {
public:
    int numDecodings(string s) {
        int *DP = new int[s.size() + 1];
        for(int i = 0; i <= s.size(); i++) {
            DP[i] = 0;
        }
        DP[0] = 1;
        if(s[0] != '0') {
            DP[1] = 1;
        }
        for(int i = 2; i <= s.size(); i++) {
            int temp = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
            if(s[i - 1] != '0') {
                DP[i] = DP[i - 1];  
            }
            if(temp >= 10 && temp <= 26) {
                DP[i] = DP[i] + DP[i - 2];
            }
        }
        return DP[s.size()];
    }
};
