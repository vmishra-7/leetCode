class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> S;
        map<int, int> M;
        vector<int> output;
        for(int i = 0; i < nums2.size(); i++) {
            while(!S.empty() && S.top() < nums2[i]) {
                M[S.top()] = nums2[i];
                S.pop();
            }
            S.push(nums2[i]);
        }
        for(int i = 0; i < nums1.size(); i++) {
            if(M.count(nums1[i]) > 0) {
                output.push_back(M[nums1[i]]);
            } else {
                output.push_back(-1);
            }
        }
        return output;
    }
};
