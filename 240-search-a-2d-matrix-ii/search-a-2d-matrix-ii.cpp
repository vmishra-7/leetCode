class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int N = matrix.size();
        int M = matrix[0].size();
        int r = N - 1, c = 0;
        while(r >= 0 && c < M) {
            if(matrix[r][c] == target) {
                return true;
            }
            if(matrix[r][c] > target) {
                r--;
            } else c++;
        }
        return false;
    }
};