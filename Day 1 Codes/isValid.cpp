class Solution {
public:
    bool isValid(string s) {
        stack<char> S;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                S.push(s[i]);
            }
            if(s[i] == ')' || s[i] == '}' || s[i] == ']') {
                if(S.empty()) {
                    return false;
                }
                if(s[i] == ')' && S.top() == '(') {
                    S.pop();
                } else if(s[i] == '}' && S.top() == '{') {
                    S.pop();
                } else if(s[i] == ']' && S.top() == '[') {
                    S.pop();
                } else {
                    return false;
                }
            }
        }
        return S.empty();
    }
};
