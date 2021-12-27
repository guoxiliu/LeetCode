#include "leetcode.h"

class Solution {
public: 
    // compare function for sorting the intervals
    static bool compareInterval(const vector<int> &a, const vector<int> &b) {
        if (a[0] == b[0])
            return (a[1] < b[1]);
        return (a[0] < b[0]);
    }

    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        int i = 1, n = intervals.size();
        if (n == 0 || n == 1) return intervals;
        sort(intervals.begin(), intervals.end(), compareInterval);
        vector<vector<int>> ans = {intervals[0]};
        for (int i = 1; i < n; i++) {
            if (ans.back()[1] >= intervals[i][0]) {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            } else {
                ans.emplace_back(intervals[i]);
            }
        }
        return ans;
    }
};
