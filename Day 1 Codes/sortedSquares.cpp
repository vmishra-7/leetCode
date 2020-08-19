class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> output(A.size());
        int si = 0, ei = A.size() - 1;
        int i = A.size() - 1;
        while(si <= ei) {
            int valSI = A[si] * A[si];
            int valEI = A[ei] * A[ei];
            if(valSI > valEI) {
                output[i] = valSI;
                si++;
                i--;
            } else {
                output[i] = valEI;
                ei--;
                i--;
            }
        }
        return output;
    }
};
