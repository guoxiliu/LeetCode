class Solution {
public: 
    long long getDescentPeriods(vector<int> &prices) {
        long long ans = 1, prev = 1;
        for (int i = 1; i < prices.size(); i++) {
            // accumulate the prev if the difference is 1
            if (prices[i-1] - prices[i] == 1) {
                prev++;
            }
            // reset the prev otherwise 
            else {
                prev = 1;
            }
            ans += prev;
        }

        return ans;
    }
};
