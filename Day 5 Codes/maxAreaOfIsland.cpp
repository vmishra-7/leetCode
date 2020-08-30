class Solution {
public:
    int check(vector<vector<int>>& board, int i, int j, int N, int M, bool **visited) {
        visited[i][j] = true;
        int count = 0;
        if(i - 1 >= 0 && !visited[i - 1][j] && board[i - 1][j] == 1) {
            count += check(board, i - 1, j, N, M, visited);
        }
        if(i + 1 < N && !visited[i + 1][j] && board[i + 1][j] == 1) {
            count += check(board, i + 1, j, N, M, visited);
        }
        if(j - 1 >= 0 && !visited[i][j - 1] && board[i][j - 1] == 1) {
            count += check(board, i, j - 1, N, M, visited);
        }
        if(j + 1 < M && !visited[i][j + 1] && board[i][j + 1] == 1) {
            count += check(board, i, j + 1, N, M, visited);
        }
        return count + 1;
    }
    int maxAreaOfIsland(vector<vector<int>>& board) {
        if(board.size() == 0) {
            return 0;
        }
        int N = board.size();
        int M = board[0].size();
        bool **visited = new bool*[N];
        for(int i = 0; i < N; i++) {
            visited[i] = new bool[M];
            for(int j = 0; j < M; j++) {
                visited[i][j] = false;
            }
        }
        int count = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(board[i][j] == 1 && !visited[i][j]) {
                    count = max(count, check(board, i, j, N, M, visited));
                }
            }
        }
        return count;
    }
};
