class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) {
            return 0;
        }
        int N = matrix.size();
        int M = matrix[0].size();
        int **DP = new int*[N + 1];
        for(int i = 0; i <= N; i++) {
            DP[i] = new int[M + 1];
            for(int j = 0; j <= M; j++) {
                DP[i][j] = 0;
            }
        }
        int maxLen = 0;
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= M; j++) {
                if(matrix[i - 1][j - 1] == '1') {
                    DP[i][j] = min(DP[i - 1][j - 1], min(DP[i - 1][j], DP[i][j - 1])) + 1;
                    maxLen = max(maxLen, DP[i][j]);
                }
            }
        }
        return maxLen * maxLen;
    }
};
