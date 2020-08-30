class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& board) {
        if(board.size() == 0) {
            return 0;
        }
        if(board[0][0] != 0) {
            return -1;
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
        queue<pair<int, int> > Q;
        Q.push({0, 0});
        board[0][0] = 1;
        while(!Q.empty()) {
            pair<int, int> P = Q.front();
            Q.pop();
            int i = P.first;
            int j = P.second;
            if(i == N - 1 && j == M - 1) {
                return board[i][j];
            }
            if(visited[i][j]) {
             //   continue;
            }
            visited[i][j] = true;
            if(i - 1 >= 0 && !visited[i - 1][j] && board[i - 1][j] == 0) {
                Q.push({i - 1, j});
                board[i - 1][j] = board[i][j] + 1;
            }
            if(i + 1 < N && !visited[i + 1][j] && board[i + 1][j] == 0) {
                Q.push({i + 1, j});
                board[i + 1][j] = board[i][j] + 1;
            }
            if(j - 1 >= 0 && !visited[i][j - 1] && board[i][j - 1] == 0) {
                Q.push({i, j - 1});
                board[i][j - 1] = board[i][j] + 1;
            }
            if(j + 1 < M && !visited[i][j + 1] && board[i][j + 1] == 0) {
                Q.push({i, j + 1});
                board[i][j + 1] = board[i][j] + 1;
            }
            if(i - 1 >= 0 && j - 1 >= 0 && !visited[i - 1][j - 1] && board[i - 1][j - 1] == 0) {
                Q.push({i - 1, j - 1});
                board[i - 1][j - 1] = board[i][j] + 1;
            }
            if(i + 1 < N && j + 1 < M && !visited[i + 1][j + 1] && board[i + 1][j + 1] == 0) {
                Q.push({i + 1, j + 1});
                board[i + 1][j + 1] = board[i][j] + 1;
            }
            if(i - 1 >= 0 && j + 1 < M && !visited[i - 1][j + 1] && board[i - 1][j + 1] == 0) {
                Q.push({i - 1, j + 1});
                board[i - 1][j + 1] = board[i][j] + 1;
            }
            if(i + 1 < N && j - 1 >= 0 && !visited[i + 1][j - 1] && board[i + 1][j - 1] == 0) {
                Q.push({i + 1, j - 1});
                board[i + 1][j - 1] = board[i][j] + 1;
            }
        }
        return -1;
    }
};
