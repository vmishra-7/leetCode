class Solution {
public:
    void combinationSum3(int K, int N, int start, vector<vector<int>> &output, vector<int> temp) {
        if(N == 0 && temp.size() == K) {
            output.push_back(temp);
            return;
        }
        if(K == 0 || N < 0) {
            return;
        }
        for(int i = start; i <= 9; i++) {
            temp.push_back(i);
            combinationSum3(K, N - i, i + 1, output, temp);
            temp.pop_back();
        }
    }
        
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> output;
        vector<int> temp;
        combinationSum3(k, n, 1, output, temp);
        return output;
    }
};
