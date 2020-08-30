class Solution {
public:
    // int coinChange(vector<int>& coins, int amount, int *DP) {
    //     if(amount < 0) {
    //         return -1;
    //     }
    //     if(amount == 0) {
    //         return 0;
    //     }
    //     if(DP[amount] != 0) {
    //         return DP[amount];
    //     }
    //     int output = INT_MAX;
    //     for(int i = 0; i < coins.size(); i++) {
    //         int res = coinChange(coins, amount - coins[i], DP);
    //         if(res != -1 && res < output) {
    //             output = res + 1;
    //         }
    //     }
    //     if(output == INT_MAX) {
    //         DP[amount] = -1;
    //     } else {
    //         DP[amount] = output;
    //     }
    //     return DP[amount];
    // }
    int coinChange(vector<int>& coins, int amount) {
        int *DP = new int[amount + 1];
        for(int i = 0; i <= amount; i++) {
            DP[i] = amount + 1;
        }
        // sort(coins.begin(), coins.end());
        // return coinChange(coins, amount, DP);
        DP[0] = 0;
        for(int i = 0; i < coins.size(); i++) {
            for(int j = coins[i]; j <= amount; j++) {
                DP[j] = min(DP[j], DP[j - coins[i]] + 1);
            }
        }
        if(DP[amount] > amount) {
            return -1;
        } return DP[amount];
    }
};
