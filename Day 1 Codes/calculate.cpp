class Solution {
public:
    int calculate(string s) {
        stack<int> S;
        long long int temp = 0;
        char sign = '+';
        for(int i = 0; i < s.size(); i++) {
            if(isdigit(s[i])) {
                temp = temp * 10 + (s[i] - '0');
            }
            if((s[i] != ' ' && !isdigit(s[i])) || i == s.size() - 1) {
                if(sign == '+') {
                    S.push(temp);
                } else if(sign == '-') {
                    S.push(-temp);
                } else {
                    if(sign == '*') {
                        long long int num = S.top() * temp;
                        S.pop();
                        S.push(num);
                    } else {
                        long long int num = S.top() / temp;
                        S.pop();
                        S.push(num);
                    }
                }
                sign = s[i];
                temp = 0;
            }
        }
        long long int sum = 0;
        while(!S.empty()) {
            sum += S.top();
            S.pop();
        }
        return sum;
    }
};
