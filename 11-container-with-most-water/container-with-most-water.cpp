class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int out = INT_MIN;
        while(i <= j) { 
            int temp = min(height[i], height[j]) * (j - i);
            out = max(out, temp);
            if(height[i] > height[j]) {
                j--;
            } else {
                i++;
            }
        }
        return out;
    }
};