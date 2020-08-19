class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        map<int, int> M;
        for(int i = 0; i < hand.size(); i++) {
            M[hand[i]]++;
        }
        map<int, int> :: iterator it;
        for(it = M.begin(); it != M.end(); it++) {
            int key = it -> first;
            int freq = it -> second;
            if(freq == 0) {
                continue;
            }
            for(int i = key; i < key + W; i++) {
                if(M.count(i) == 0) {
                    return false;
                }
                if(M[i] >= freq) {
                    M[i] -= freq;
                } else {
                    return false;
                }
                if(M[i] == 0) {
                    cout << i << " ";
                }
            }
        }
        return true;
    }
};
