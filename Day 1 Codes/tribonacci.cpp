class Solution {
public:
    int tribonacci(int n, int *DP) {
        if(n <= 0) {
            return 0;
        }
        if(n == 1) {
            return 1;
        }
        if(n ==  2) {
            return 1;
        }
        if(DP[n] != -1) {
            return DP[n];
        }
        DP[n] = tribonacci(n - 1, DP) + tribonacci(n - 2, DP) + tribonacci(n - 3, DP);
        return DP[n];
    }
    int tribonacci(int n) {
        int *DP = new int[n + 1];
        for(int i = 0; i <= n; i++) {
            DP[i] = -1;
        }
        return tribonacci(n, DP);
    }
};
