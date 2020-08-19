class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 0) {
            return {};
        }
        vector<vector<int> > V(numRows);
        V[0].push_back(1);
        if(numRows == 1) {
            return V;
        }
        for(int i = 1; i < numRows; i++) {
            V[i].push_back(1);
            for(int j = 0; j < i - 1; j++) {
                V[i].push_back(V[i - 1][j] + V[i - 1][j + 1]);
            }
            V[i].push_back(1);
        }
        return V;
    }
};
