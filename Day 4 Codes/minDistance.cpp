class Solution {
public:
    // int minDistance(string word1, string word2, int i, int j, int **DP) {
    //     if(word1.empty()) {
    //         return word2.size();
    //     }
    //     if(word2.empty()) {
    //         return word1.size();
    //     }
    //     if(DP[i][j] != -1) {
    //         return DP[i][j];
    //     }
    //     if(word1[0] == word2[0]) {
    //         return minDistance(word1.substr(1), word2.substr(1), i + 1, j + 1, DP);
    //     }
    //     int outA = minDistance(word1.substr(1), word2, i + 1, j, DP);
    //     int outB = minDistance(word1, word2.substr(1), i, j + 1, DP);
    //     int outC = minDistance(word1.substr(1), word2.substr(1), i + 1, j + 1, DP);
    //     return DP[i][j] =  min(outA, min(outB, outC)) + 1;
    // }
    int minDistance(string word1, string word2) {
        // int **DP = new int*[word1.size() + 1];
        // for(int i = 0; i <= word1.size(); i++) {
        //     DP[i] = new int[word2.size() + 1];
        //     for(int j = 0; j <= word2.size() ; j++) {
        //         DP[i][j] = -1;
        //     }
        // }
        // return minDistance(word1, word2, 0, 0, DP);
        int N = word1.size();
        int M = word2.size();
        int **DP = new int*[N + 1];
        for(int i = 0; i <= N; i++) {
            DP[i] = new int[M + 1];
        }
        for(int i = N; i >= 0; i--) {
            DP[i][M] = N - i;
        }
        for(int i = M; i >= 0; i--) {
            DP[N][i] = M - i;
        }
        for(int i = N - 1; i >= 0; i--) {
            for(int j = M - 1; j >= 0; j--) {
                if(word1[i] == word2[j]) {
                    DP[i][j] = DP[i + 1][j + 1];
                } else {
                    DP[i][j] = 1 + min(DP[i + 1][j + 1], min(DP[i + 1][j], DP[i][j + 1]));
                }
            }
        }
        return DP[0][0];
    }
};
