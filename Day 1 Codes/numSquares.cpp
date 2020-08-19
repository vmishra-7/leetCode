class Solution {
public:
    // int numSquares(int n, int *DP) {
    //     if(n == 0) {
    //         return 0;
    //     }
    //     if(DP[n] != -1) {
    //         return DP[n];
    //     }
    //     int output = INT_MAX;
    //     for(int i = 1; i * i <= n; i++) {
    //         output = min(output, numSquares(n - i * i, DP) + 1);
    //     }
    //     DP[n] = output;
    //     return output;
    // }
    int numSquares(int n) {
        int *DP = new int[n + 1];
        // for(int i = 0; i <= n; i++) {
        //     DP[i] = -1;
        // }
        // int output = numSquares(n, DP);
        // delete []DP;
        // return output;
        DP[0] = 0;
        for(int i = 1; i <= n; i++) {
            int output = INT_MAX;
            for(int j = 1; j *j <= i; j++) {
                output = min(output, DP[i - j * j] + 1);
            }
            DP[i] = output;
        }
        return DP[n];
    }
};
