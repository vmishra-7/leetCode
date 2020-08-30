class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int N = strs.size();
        unordered_map<string, int> M;
        for(int i = 0; i < strs.size(); i++) {
            for(int j = 0; j < strs[i].size(); j++) {
                string st = strs[i].substr(0, j + 1);
                M[st]++;
            }
        }
        unordered_map<string, int> :: iterator it;
        string output = "";
        int maxLength = 1;
        for(it = M.begin(); it != M.end(); it++) {
            if(it -> second == N) {
                if(it -> first.size() > output.size()) {
                    output = it -> first;
                    maxLength = output.size();
                }
            }
        }
        return output;
    }
};
