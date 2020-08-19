class Solution {
public:
    int romanToInt(string s) {
        if(s.size() == 0) {
            return 0;
        }
        map<char, int> M;
        M.insert({'I', 1});
        M.insert({'V', 5});
        M.insert({'X', 10});
        M.insert({'L', 50});
        M.insert({'C', 100});
        M.insert({'D', 500});
        M.insert({'M', 1000});
        int sum = M[s[s.size() - 1]];
        for(int i = s.size() - 2; i >= 0; i--) {
            if(M[s[i]] >= M[s[i + 1]]) {
                sum += M[s[i]];
            } else {
                sum -= M[s[i]];
            }
        }
        return sum;
    }
};
