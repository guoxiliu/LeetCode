#include "../leetcode.h"

class Solution {
public: 
    vector<vector<int>> minimumAbsDifference(vector<int> &arr) {
        sort(arr.begin(), arr.end());
        int minAbsDiff = INT_MAX;
        vector<vector<int>> ans;
        for (int i = 0; i < arr.size()-1; i++) {
            int cur = abs(arr[i+1] - arr[i]);
            if (cur < minAbsDiff) {
                ans.clear();
                ans.push_back(vector<int>{arr[i], arr[i+1]});
                minAbsDiff = cur;
            }
            else if (cur == minAbsDiff) {
                ans.push_back(vector<int>{arr[i], arr[i+1]});
            }
        }
        return ans;
    }
};
