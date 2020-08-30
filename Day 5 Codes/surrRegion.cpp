class Solution {
public:
    void check(vector<vector<char>>& board, int i, int j, int N, int M, bool **visited) {
        visited[i][j] = true;
        if(i - 1 >= 0 && !visited[i - 1][j] && board[i - 1][j] == 'O') {
            check(board, i - 1, j, N, M, visited);
        }
        if(i + 1 < N && !visited[i + 1][j] && board[i + 1][j] == 'O') {
            check(board, i + 1, j, N, M, visited);
        }
        if(j - 1 >= 0 && !visited[i][j - 1] && board[i][j - 1] == 'O') {
            check(board, i, j - 1, N, M, visited);
        }
        if(j + 1 < M && !visited[i][j + 1] && board[i][j + 1] == 'O') {
            check(board, i, j + 1, N, M, visited);
        }
    }
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0) {
            return;
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
        for(int i = 0; i < M; i++) {
            if(board[0][i] == 'O' && !visited[0][i]) {
                check(board, 0, i, N, M, visited);
            }
        }
        
        for(int i = 0; i < M; i++) {
            if(board[N - 1][i] == 'O' && !visited[ N - 1][i]) {
                check(board, N - 1, i, N, M, visited);
            }
        }
        
        for(int i = 0; i < N; i++) {
            if(board[i][0] == 'O' && !visited[i][0]) {
                check(board, i, 0, N, M, visited);
            }
        }
        for(int i = 0; i < N; i++) {
            if(board[i][M - 1] == 'O' && !visited[i][M - 1]) {
                check(board, i, M - 1, N, M, visited);
            }
        }
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(board[i][j] == 'O' && !visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
