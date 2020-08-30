class Solution {
public:
    int LIP(vector<vector<int>>& matrix, int i, int j, int N, int M, bool **visited, int **val) {
        if(visited[i][j]) {
            return val[i][j];
        }
        visited[i][j] = true;
        int output = INT_MIN;
        if(i - 1 >= 0 && matrix[i - 1][j] > matrix[i][j]) {
            output = max(output, LIP(matrix, i - 1, j, N, M, visited, val) + 1);
        }
        if(i + 1 < N && matrix[i + 1][j] > matrix[i][j]) {
            output = max(output, LIP(matrix, i + 1, j, N, M, visited, val) + 1);
        }
        if(j - 1 >= 0 && matrix[i][j - 1] > matrix[i][j]) {
            output = max(output, LIP(matrix, i, j - 1, N, M, visited, val) + 1);
        }
        if(j + 1 < M && matrix[i][j + 1] > matrix[i][j]) {
            output = max(output, LIP(matrix, i, j + 1, N, M, visited, val) + 1);
        }
        val[i][j] = max(output, val[i][j]);
        return val[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) {
            return 0;
        }
        int N = matrix.size();
        int M = matrix[0].size();
        bool **visited = new bool*[N];
        for(int i = 0; i < N; i++) {
            visited[i] = new bool[M];
            for(int j = 0; j < M; j++) {
                visited[i][j] = false;
            }
        }
        int **val = new int*[N];
        for(int i = 0; i < N; i++) {
            val[i] = new int[M];
            for(int j = 0; j < M; j++) {
                val[i][j] = 1;
            }
        }
        int output = INT_MIN;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(!visited[i][j]) {
                    output = max(output, LIP(matrix, i, j, N, M, visited, val));
                }
            }
        }
        for(int i = 0; i < N; i++) {
            delete[] val[i];
            delete[] visited[i];
        }
        delete[] val;
        delete[] visited;
        return output;
    }
};
