class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) {
            return 0;
        }
        int N = prices.size();
        int *rightMax = new int[N];
        rightMax[N - 1] = prices[N - 1];
        for(int i = N  - 2; i >= 0; i--) {
            rightMax[i] = max(prices[i], rightMax[i + 1]);
        }
        int output = 0;
        for(int i = 0; i < N; i++) {
            output = max(output, rightMax[i] - prices[i]);
        }
        return output;
    }
};
