class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) {
            return "1";
        } string tempRes = countAndSay(n -1);
        string output = "";
        int i = 0, freq = 0;
        while(i < tempRes.size()) {
            char ch = tempRes[i];
            freq = 1;
            i++;
            while(i < tempRes.size() && ch == tempRes[i]) {
                i++;
                freq++;
            }
            output += (to_string(freq)) + ch;
        }
        return output;
    }
};
