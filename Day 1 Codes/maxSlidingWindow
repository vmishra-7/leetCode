class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> DQ;
        vector<int> output;
        for(int i = 0; i < nums.size(); i++) {
            while(!DQ.empty() && nums[i] >= nums[DQ.back()]) {
                DQ.pop_back();
            }
            DQ.push_back(i);
            if(i >= k - 1) {
                output.push_back(nums[DQ.front()]);
            } 
            if(DQ.front() <= i - k + 1) {
                DQ.pop_front();
            } 
        }
        return output;
    }
};
