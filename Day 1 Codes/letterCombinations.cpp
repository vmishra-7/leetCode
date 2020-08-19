class Solution {
public:
    void letterCombinations(string digits, vector<string> &output, string comb[], int index, string temp) {
        if(digits.size() == index) {
            output.push_back(temp);
            return;
        }
        int N = digits[index] - '0';
        string newTemp = comb[N];
        for(int i = 0; i < newTemp.size(); i++) {
            letterCombinations(digits, output, comb, index + 1, temp + newTemp[i]);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) {
            return {};
        }
        string comb[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> output;
        letterCombinations(digits, output, comb, 0, "");
        return output;
    }
};
