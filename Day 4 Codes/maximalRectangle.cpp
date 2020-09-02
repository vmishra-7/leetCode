class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int N = heights.size();
        stack<int> L;
        stack<int> R;
        vector<int> left;
        vector<int> right;
        for(int i = 0; i < N; i++) {
            cout << heights[i] << " ";
            left.push_back(-1);
            right.push_back(N);
        }
        for(int i = 0; i < N; i++) {
            while(!R.empty() && heights[R.top()] > heights[i]) {
                right[R.top()] = i;
                R.pop();
            }
            R.push(i);
        }
        for(int i = N - 1; i >= 0; i--) {
            while(!L.empty() && heights[L.top()] > heights[i]) {
                left[L.top()] = i;
                L.pop();
            }
            L.push(i);
        }
        int ans = 0;
        for(int i = 0; i < N; i++) {
         //   cout << right[i] << " " << left[i] << '\n';
            ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) {
            return 0;
        }
        int N = matrix.size();
        int M = matrix[0].size();
        int output = 0;
        vector<int> heights(M, 0);
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(matrix[i][j] == '1') {
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }
           output = max(output, largestRectangleArea(heights)); 
        }
        return output;
    }
};
