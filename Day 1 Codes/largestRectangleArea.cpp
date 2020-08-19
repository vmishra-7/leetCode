class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), max_area = 0;
        vector<int> left(n), right(n);
        stack<int> s1;
        for(int i = 0; i < n; i++) {
            while (!s1.empty() && heights[s1.top()] >= heights[i]) s1.pop();
            left[i] = s1.empty() ? 0 : s1.top()+1;
            s1.push(i);
        }
        stack<int> s2;
        for(int i = n-1; i >= 0; i--) {
            while (!s2.empty() && heights[s2.top()] >= heights[i]) s2.pop();
            right[i] = s2.empty() ? n-1 : s2.top()-1;
            s2.push(i);
            max_area = max(max_area, ((right[i]-left[i]+1) * heights[i]));
        }
        return max_area;
    }
};
