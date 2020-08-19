class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> output;
        int maxCand = INT_MIN;
        for(int i = 0; i < candies.size(); i++) {
            maxCand = max(maxCand, candies[i]);
        }
        for(int i = 0; i < candies.size(); i++) {
            if(candies[i] + extraCandies >= maxCand) {
              output.push_back(true);
            } else {
                output.push_back(false);
            }
        }
        return output;
    }
};
