class Solution {
public:
    int fib(int N) {
        // if(N == 0) {
        //     return 0;
        // }
        // if(N == 1) {
        //     return 1;
        // }
        // return fib(N - 1) + fib(N - 2);
        int *outFib = new int[31];
        outFib[0] = 0;
        outFib[1] = 1;
        for(int i = 2; i <= 30; i++) {
            outFib[i] = (outFib[i - 1] + outFib[i - 2]);
        }
        return outFib[N];
    }
};
