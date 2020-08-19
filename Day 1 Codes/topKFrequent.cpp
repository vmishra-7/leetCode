class Solution {
public:
    struct myComp { 
        constexpr bool operator()( pair<int, int> const& a, pair<int, int> const& b) const noexcept{ 
        return a.first > b.first; 
        } 
    }; 
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> output;
        map<int, int> M;
        for(int i = 0; i < nums.size(); i++) {
            M[nums[i]]++;
        }
        map<int, int> :: iterator it;
        priority_queue<pair<int,int>, vector<pair<int,int>>, myComp> pq;
        int i = 0;
        for(it = M.begin(); it != M.end(); it++) {
            if(i == k) {
                break;
            }
            i++;
            pq.push({it -> second, it -> first});
        }
        while(it != M.end()) {
            pq.push({it -> second, it -> first});
            pq.pop();
            it++;
        }
        while(!pq.empty()) {
            pair<int, int> P = pq.top();
            output.push_back(P.second);
            pq.pop();
        }
        return output;
    }
};
