string Solution::solve(string A) {
    map<char, int> C;
    queue<char> Q;
    string output = "";
    for(int i = 0; i < A.size(); i++) {
        if(C[A[i]] == 0)
        Q.push(A[i]);
        C[A[i]]++;
        while(!Q.empty()) {
            if(C[Q.front()] > 1) {
                Q.pop();
            } else {
                output += Q.front();
                break;
            }
        }
        if(Q.empty()) {
            output += '#';
        }
    }
    return output;
}
