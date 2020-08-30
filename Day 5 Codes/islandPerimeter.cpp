class Solution {
public:
    int peri(vector<vector<int>>& grid, bool **visited, int i, int j, int N, int M) {
        visited[i][j] = true;
        int count = 4;
        if(i - 1 >= 0 && grid[i - 1][j]) {
            if(visited[i - 1][j]) {
                count--;
            } else {
                count--;
                count += peri(grid, visited, i - 1, j, N, M);
            }
        }
        if(i + 1 < N && grid[i + 1][j]) {
            if(visited[i + 1][j]) {
                count--;
            } else {
                count--;
                count += peri(grid, visited, i + 1, j, N, M);
            }
        }
        if(j - 1 >= 0 && grid[i][j - 1]) {
            if(visited[i][j - 1]) {
                count--;
            } else {
                count--;
                count += peri(grid, visited, i, j - 1, N, M);
            }
        }
        if(j + 1 < M && grid[i][j + 1]) {
            if(visited[i][j + 1]) {
                count--;
            } else {
                count--;
                count += peri(grid, visited, i, j + 1, N, M);
            }
        }
        return count;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int N = grid.size();
        int M = grid[0].size();
        bool **visited = new bool*[N];
        for(int i = 0; i < N; i++) {
            visited[i] = new bool[M];
            for(int j = 0; j < M; j++) {
                visited[i][j] = false;
            }
        }
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(grid[i][j]) {
                    return peri(grid, visited, i, j, N, M);
                }
            }
        }
        return 0;
    }
};
