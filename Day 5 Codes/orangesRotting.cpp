class Solution {
public:
    int rottenEmAll(vector<vector<int>>& grid, int N, int M, bool **visited, queue<pair<int, int>> &Q) {
        int count = 0;
        cout << Q.size();
        while(!Q.empty()) {
            pair<int, int> P = Q.front();
            Q.pop();
            int i = P.first;
            int j = P.second;
            if(i == -1 && j == -1) {
                count++;
                if(!Q.empty()) {
                    Q.push({-1, -1});
                }
            } else {
            //    cout << i << " " << j << '\n';
                visited[i][j] = true;
                if(i - 1 >= 0 && !visited[i - 1][j] && grid[i - 1][j] == 1) {
                    grid[i - 1][j] = 2;
                    Q.push({i - 1, j});
                }
                if(i + 1 < N && !visited[i + 1][j] && grid[i + 1][j] == 1) {
                    grid[i + 1][j] = 2;
                    Q.push({i + 1, j});
                }
                if(j - 1 >= 0 && !visited[i][j - 1] && grid[i][j - 1] == 1) {
                    grid[i][j - 1] = 2;
                    Q.push({i, j - 1});
                }
                if(j + 1 < M && !visited[i][j + 1] && grid[i][j + 1] == 1) {
                    grid[i][j + 1] = 2;
                    Q.push({i, j + 1});
                }
            }
        }
        return count;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.size() == 0) {
            return 0;
        }
        int N = grid.size();
        int M = grid[0].size();
        bool **visited = new bool*[N];
        for(int i = 0; i < N; i++) {
            visited[i] = new bool[M];
            for(int j = 0; j < M; j++) {
                visited[i][j] = false;
            }
        }
        int count = 0;
        queue<pair<int, int> > Q;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(grid[i][j] == 2 && !visited[i][j]) {
                    Q.push({i, j});
                }
            }
        }
        Q.push({-1, -1});
        count += rottenEmAll(grid, N, M, visited, Q);
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return count - 1;
    }
};
