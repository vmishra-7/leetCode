class Solution {
public:
    int uniquePaths(int m, int n, int i, int j) {
        if(i == m - 1 && j == n - 1) {
            return 1;
        }
        if(i >= m || j >= n) {
            return 0;
        }
        return uniquePaths(m, n, i + 1, j) + uniquePaths(m, n, i, j + 1);
    }
    int uniquePaths(int m, int n) {
      //  return uniquePaths(m, n, 0, 0);
        int **DP = new int*[m];
        for(int i = 0; i < m; i++) {
            DP[i] = new int[n];
        }
        for(int i = m - 1; i >= 0; i--) {
            DP[i][n - 1] = 1;
        }
        for(int i = n - 1; i >= 0; i--) {
            DP[m - 1][i] = 1;
        }
        for(int i = m - 2; i >= 0; i--) {
            for(int j = n - 2; j >= 0; j--) {
                DP[i][j] = DP[i + 1][j] + DP[i][j + 1];
            }
        }
        return DP[0][0];
    }
};
